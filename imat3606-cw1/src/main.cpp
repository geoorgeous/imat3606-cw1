// Defines

#define STB_IMAGE_IMPLEMENTATION


// Local includes

#include "engine.h"


// Forward declarations

bool init();
bool initGLFW();
bool initGLEW();
void checkFPS();
void exitApp(int error);


// Variables

graphics::Window* mainWindow;
double lastTime;
int frameCount;
int error = 0;


// Application entry point
int main()
{
	if (init())
	{
		// GUI VARS
		int currentSelectedModel = 0;
		int currentSelectedSceneObject = 0;
		int currentTab = 0;

		while (!mainWindow->shouldClose())
		{
			glfwPollEvents();

			if (mainWindow->isKeyStroked(GLFW_KEY_ESCAPE))
				mainWindow->close();

			mainWindow->clear();

			ImGui::TextColored(ImVec4(1, 0, 0, 1), "%.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
			ImGui::TextColored(ImVec4(0, 1, 0, 1), "\nInput controls");
			ImGui::Text("\tCamera:\n\t[W]: Forwards.\n\t[S]: Backwards.\n\t[A]: Left.\n\t[D]: Right.\n\t[Space]: Up.\n\t[L-Ctrl]: Down.\n\t[Q]: Roll left.\n\t[E]: Roll right.\n\n\tOther:\n\t[M]: Disable/enable mouse input.\n\t[Esc]Exit.");

			mainWindow->swapBuffers();
		}
	}

	exitApp(error);
	return error;
}



// Preforms all initialization
bool init()
{
	if (!initGLFW()) 
		return false;

	utils::Logger::log("%-32s", "Creating window... ");

	mainWindow = new graphics::Window((int)SCREEN_WIDTH, (int)SCREEN_HEIGHT, "FYP - 3D Scene Renderer", true);

	if (mainWindow->created())
	{
		utils::Logger::log(utils::ConsoleColour::LOG_CC_GREEN, utils::ConsoleColour::LOG_CC_UNCHANGED, "OK");
		utils::Logger::log(" (%.0f x %.0f)\n", SCREEN_WIDTH, SCREEN_HEIGHT);
	}
	 
	if (!initGLEW()) 
		return false;

	utils::Logger::log("\n--------------------------------------------\n");
	utils::Logger::log("OpenGL %s\n", (char const*)glGetString(GL_VERSION));
	utils::Logger::log("GLSL %s\n", (char const*)glGetString(GL_SHADING_LANGUAGE_VERSION));
	utils::Logger::log("Platform: %s - %s\n", (char const*)glGetString(GL_VENDOR), (char const*)glGetString(GL_RENDERER));
	utils::Logger::log("--------------------------------------------\n\n");

	return true;
}



// Initialization logic for GLFW
bool initGLFW()
{
	utils::Logger::log("%-32s", "Initialising GLFW...");

	if (!glfwInit())
	{
		error = 1;
		return false;
	}

	utils::Logger::log(utils::ConsoleColour::LOG_CC_GREEN, utils::ConsoleColour::LOG_CC_UNCHANGED, "OK");
	utils::Logger::log(" (v.%i.%i.%i)\n", GLFW_VERSION_MAJOR, GLFW_VERSION_MINOR, GLFW_VERSION_REVISION);

	return true;
}



// Initialization for GLEW
bool initGLEW()
{
	utils::Logger::log("%-32s", "Initialising GLEW...");

	GLenum err = glewInit();
	if (err != GLEW_OK)
	{
		error = 2;
		return false;
	}
	else
	{
		// Set a background color 
		GL_CALL(glClearColor(CLEAR_COLOUR));

		// Tell OpenGL to cull back faces.
		GL_CALL(glEnable(GL_CULL_FACE));

		// Tell OpenGL to only draw a pixel if its shape is closer to the viewer.
		// i.e. Enable depth testing with smaller depth value interpreted as being closer 
		GL_CALL(glEnable(GL_DEPTH_TEST));
		GL_CALL(glDepthFunc(GL_LESS));

		utils::Logger::log(utils::ConsoleColour::LOG_CC_GREEN, utils::ConsoleColour::LOG_CC_UNCHANGED, "OK");
		utils::Logger::log(" (v.%s)\n", glewGetString(GLEW_VERSION));
	}

	return true;
}



// Prints frames per second to console every second
void checkFPS()
{
	double currentTime = glfwGetTime();
	frameCount++;
	if (currentTime - lastTime >= 1.0) 
	{
		utils::Logger::log(utils::ConsoleColour::LOG_CC_GREEN, utils::ConsoleColour::LOG_CC_UNCHANGED, "%i FPS (%.3d ms.frame)\n", frameCount, 1000.0 / double(frameCount));
		frameCount = 0;
		lastTime += 1.0;
	}
}



// Exit and clean up
void exitApp(int error)
{
	delete mainWindow;

	glfwTerminate();

	if (error != 0)
	{
		switch (error)
		{
		case 1:
			utils::Logger::logError("\nFatal Error: GLFW failed to initialize.\n");
			break;

		case 2:
			utils::Logger::logError("\nFatal Error: GLEW failed to initialize.\n");
			break;
		}

		utils::Logger::log("Press enter to exit...");

		std::cin.get();
	}
}