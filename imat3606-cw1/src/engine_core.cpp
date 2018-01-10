/*!
 * @file engine_core.cpp
 * @brief Implementation file for GLFW implementation of the engine core.
 * @author George McDonagh */


// Macros

#define CLEAR_COLOUR 0.5f, 0.5f, 0.5f, 1.0f


// Local includes

#include "engine_core.h"


// Namespaces

using namespace engine;


EngineCore::~EngineCore() 
{
	// Automatically terminate if we should have called terminate() already but haven't.
	if (m_mainWindow->created() && !m_terminated)
		terminate();
}

bool EngineCore::init(int windowWidth, int windowHeight, const char* windowTitle)
{
	// Initialize GLFW for context creation.
	if (!initGLFW())
	{
		m_engineError = ENGINE_ERR_GLFW_FAIL;
		return false;
	}

	utils::Logger::log("%-32s", "Creating window... ");

	// Initialize our engine's main window.
	m_mainWindow.reset(new graphics::Window(windowWidth, windowHeight, windowTitle, true));

	if (m_mainWindow->created())
	{
		utils::Logger::log(utils::ConsoleColour::LOG_CC_GREEN, utils::ConsoleColour::LOG_CC_UNCHANGED, "OK");
		utils::Logger::log(" (%i x %i)\n", windowWidth, windowHeight);
	}
	else
	{
		m_engineError = ENGINE_ERR_WINDOW_CREATION;
		return false;
	}

	// Initialize GLEW so we can access the OpenGL implementation.
	if (!initGLEW())
	{
		m_engineError = ENGINE_ERR_GLEW_FAIL;
		return false;
	}

	utils::Logger::log("\n--------------------------------------------\n");
	utils::Logger::log("OpenGL %s\n", (char const*)glGetString(GL_VERSION));
	utils::Logger::log("GLSL %s\n", (char const*)glGetString(GL_SHADING_LANGUAGE_VERSION));
	utils::Logger::log("Platform: %s - %s\n", (char const*)glGetString(GL_VENDOR), (char const*)glGetString(GL_RENDERER));
	utils::Logger::log("--------------------------------------------\n\n");

	m_renderer3D = std::unique_ptr<graphics::Renderer3D>(new graphics::Renderer3D());

	return true;
}

bool EngineCore::initGLFW()
{
	utils::Logger::log("%-32s", "Initialising GLFW...");

	if (!glfwInit())
		return false;

	utils::Logger::log(utils::ConsoleColour::LOG_CC_GREEN, utils::ConsoleColour::LOG_CC_UNCHANGED, "OK");
	utils::Logger::log(" (v.%i.%i.%i)\n", GLFW_VERSION_MAJOR, GLFW_VERSION_MINOR, GLFW_VERSION_REVISION);

	return true;
}

bool EngineCore::initGLEW()
{
	utils::Logger::log("%-32s", "Initialising GLEW...");

	GLenum err = glewInit();
	if (err != GLEW_OK)
		return false;
	
	// Set a context background color 
	GL_CALL(glClearColor(CLEAR_COLOUR));

	// Tell OpenGL to cull back faces (by default faces with clock-wise vertex winding).
	GL_CALL(glEnable(GL_CULL_FACE));

	// Tell OpenGL to only draw a pixel if its shape is closer to the viewer.
	// i.e. Enable depth testing with smaller depth value interpreted as being closer 
	GL_CALL(glEnable(GL_DEPTH_TEST));
	GL_CALL(glDepthFunc(GL_LESS));

	utils::Logger::log(utils::ConsoleColour::LOG_CC_GREEN, utils::ConsoleColour::LOG_CC_UNCHANGED, "OK");
	utils::Logger::log(" (v.%s)\n", glewGetString(GLEW_VERSION));
	
	return true;
}

void EngineCore::run(Game& game)
{
	// The engine's main loop.
	while (!m_mainWindow->shouldClose())
	{
		glfwPollEvents();

		if (m_mainWindow->isKeyStroked(GLFW_KEY_ESCAPE))
			m_mainWindow->close();

		m_mainWindow->clear();

		m_renderer3D->renderScene(game.currentScene());

		ImGui::TextColored(ImVec4(1, 0, 0, 1), "%.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
		ImGui::TextColored(ImVec4(0, 1, 0, 1), "\nInput controls");
		ImGui::Text("\tCamera:\n\t[W]: Forwards.\n\t[S]: Backwards.\n\t[A]: Left.\n\t[D]: Right.\n\t[Space]: Up.\n\t[L-Ctrl]: Down.\n\t[Q]: Roll left.\n\t[E]: Roll right.\n\n\tOther:\n\t[M]: Disable/enable mouse input.\n\t[Esc]Exit.");

		m_mainWindow->swapBuffers();
	}
}

void EngineCore::terminate()
{
	glfwTerminate();

	if (m_engineError != ENGINE_ERR_NONE)
	{
		const char* errorMessage;
		switch (m_engineError)
		{
		case ENGINE_ERR_GLFW_FAIL: errorMessage = "GLFW failed to initialize."; break;
		case ENGINE_ERR_WINDOW_CREATION: errorMessage = "Failed to create window."; break;
		case ENGINE_ERR_GLEW_FAIL: errorMessage = "GLEW failed to initialize."; break;
		}

		utils::Logger::log(utils::ConsoleColour::LOG_CC_RED, utils::ConsoleColour::LOG_CC_UNCHANGED, "FATAL ENGINE ERROR");
		utils::Logger::log(": [%i] \"%s\"\nPress enter to continue...", m_engineError, errorMessage);

		std::cin.get();
	}

	m_terminated = true;
}