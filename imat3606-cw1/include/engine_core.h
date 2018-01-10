#pragma once

/*!
 * @file engine_core.h
 * @brief Header file for GLFW implementation of the engine core.
 * @author George McDonagh */


// Defines

// Error flags appropriate for this implementation.

#define ENGINE_ERR_GLFW_FAIL		1
#define ENGINE_ERR_WINDOW_CREATION	2
#define ENGINE_ERR_GLEW_FAIL		3


// External includes

#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <vector>
#include <DearIMGUI\imgui.h>


// Local includes

#include "game.h"
#include "i_engine_core.h"
#include "graphics/renderer_3d.h"
#include "graphics/window.h"
#include "utils/logger.h"


// Verbose namespace commenting for doxygen documentation...

//! Primary namespace for FYP project
namespace engine {

	//! All things related to graphics and rendering.
	namespace graphics {}

	//! All things related to mathematics.
	namespace maths {}

	//! Helpful utility functions functionality.
	namespace utils {}


	//! EngineCore implementation using GLFW and GLEW.
	class EngineCore : public IEngineCore 
	{
	public:
		//! Destructor.
		~EngineCore() override;

		//! Initialize the engine.
		/*! Initializes the engine by initializing GLFW, creating a context using GLFW, and loading OpenGL implementation headers with GLEW.
		  * @param windowWidth The width of the engine's main window on start.
		  * @param windowHeight The height of the engine's main window on start.
		  * @param windowTitle The engine's main window's title. */
		bool init(int windowWidth, int windowHeight, const char* windowTitle) override;

		//! Begin the engine's main loop.
		/*! Kickstart the engine's main loop (update logic, input, rendering, etc.). */
		void run(Game& game) override;

		//! Terminate the engine.
		/*! Terminates GLFW and reports any known errors. */
		void terminate() override;

	private:
		//! Initializes GLFW.
		bool initGLFW();

		//! Initializes GLEW.
		bool initGLEW();
	};

}