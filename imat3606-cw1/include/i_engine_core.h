#pragma once

/*!
  * @file i_engine_core.h 
  * @brief Interface for engine core implementations.
  * @author George McDonagh */


// Defines

#define ENGINE_ERR_NONE 0


// External includes

#include <memory>
#include <string>


// Namespaces

namespace engine {


	// Forward declarations
	namespace graphics {

		class Game;
		class Renderer3D;
		class Window;

	}


	//! Engine core interface.
	/*! Interface for any engine core implementations. See member function documentation for implementation specifics. */
	class IEngineCore
	{
	public:
		//! Destructor.
		virtual ~IEngineCore() {}

		//! Initialize the engine.
		/*! Initializes the engine by creating a context and loading the graphics library.
		  * @note This function should also check for errors during initialization and abort when a fatal error is detected, for example a failure to create a OpenGL context.
		  * @param windowWidth The width of the engine's main window on start.
		  * @param windowHeight The height of the engine's main window on start.
		  * @param windowTitle The engine's main window's title. */
		virtual bool init(int windowWidth, int windowHeight, const char* windowTitle) = 0;

		//! Begin the engine's main loop.
		/*! Kickstart the engine's main loop (update logic, input, rendering, etc.). */
		virtual void run(Game& game) = 0;

		//! Terminate the engine.
		/*! Cleans up any engine resources and logs any known errors. */
		virtual void terminate() = 0;

	protected:
		bool m_terminated = false; /*!< Flag to check if engine was terminated correctly. */
		int m_engineError = ENGINE_ERR_NONE; /*!< Stores any engine-stopping errors. */
		std::unique_ptr<graphics::Window> m_mainWindow; /*!< Engine's primary window. */
		std::unique_ptr<graphics::Renderer3D> m_renderer3D; /*!< Engine's 3D renderer. */
	}; 
}