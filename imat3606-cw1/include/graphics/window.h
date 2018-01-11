#pragma once

/*!
  * @file window.h
  * @brief Header file for the Window class.
  * @author George McDonagh */


// External includes

#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <DearIMGUI\imgui.h>


// Local includes

#include "maths\maths.h"
#include "imgui_impl.h"


// Namespaces

namespace engine { namespace graphics {

	//! @p GLFWwindow wrapper-class.
	/*! Wraps up GLFW functionality for creating and using OpenGL contexts. */
	class Window
	{
	public:
		//! Constructor
		/*! Constructs a 640 x 420 window which is then set to as the current context. */
		Window();

		//! Constructs a Window with a specified width, height, and title.
		/*! @param width The width of the Window in pixels.
		  * @param height The height of the Window in pixels.
		  * @param title The title of the Window - this string appears at the top of the Window.
		  * @param makeCurrent If passed as true then the Window will immediately become the current OpenGL context after successful construction. */
		Window(int width, int height, const char* title, bool makeCurrent = false);

		//! Default desctructor.
		/*! Destorys the GLFW window. */
		~Window();

		//! Check if the window got created.
		/*! @return True when GLFW fails to create the window. */
		bool created() const;

		//! Get the 2D dimensions of the window.
		/*! @return A reference to an immutable 2D vector. The width and height of the window as @p x and @p y components respectively. */
		const maths::Vec2& getDimensions() const;

		//! Get the Window's aspect ratio.
		/*! @return The Window's aspect ratio (width / height). */
		float getAspectRatio() const;

		//! Cursor position inside the Window.
		/*! @return A reference to an immutable 2D vector. The X and Y position of the cursor relative to the top-left pixel of the Window's context. */
		const maths::Vec2& cursorPos() const;

		//! Cursor position delta.
		/*! @return A reference to an immutable 2D vector. The X and Y change (delta) in the cursor position since the last GLFW event poll. */
		const maths::Vec2& cursorPosDelta() const;

		//! State of the window's cursor.
		/*! @return True if the cursor is disabled for this window. */
		const bool& isCursorDisabled() const;

		//! Disable the window's cursor. This hides the cursor's movement.
		void disableCursor();

		//! Enable the window's cursor.
		void enableCursor();

		//! Check if a key is pressed.
		/*! @param key Key enumeration of the key to check is down.
		  * @return True if the key is found to be pressed. */
		bool isKeyDown(int key) const;

		//! Check if a key is released after being pressed down.
		/*! @param key Key enumeration of the key to check is down.
		  * @return True if the key is found to have been released just after being pressed. */
		bool isKeyStroked(int key) const;

		//! Check if the Window should close.
		/*! @return Returns true when GLFW says this window should be closing. */
		bool shouldClose();

		//! Sets the window title.
		/*! @param title The string to set the Window's title to. */
		void setTitle(const char* title);

		//! Makes the Window the current OpenGL context.
		void makeCurrent();

		//! Set the Window to close.
		/*! Tells GLFW that this Window should be closing. */
		void close();

		//! Preforms pre-draw logic.
		/*! Clears the GLFW context. This should be called before drawing with OpenGL. */
		void clear();

		//! Preforms post-draw logic.
		/*! Polls events and swaps the buffer. This should be called after drawing with OpenGL. */
		void swapBuffers();

	private:
		bool m_isCreated = false; /*!< Flag for when GLFW fails to create a window. */
		maths::Vec2 m_dimensions; /*! The 2D dimensions of the window. */
		GLFWwindow* m_window; /*!< GLFW window pointer. */
		maths::Vec2 m_cursorPos; /*!< Cursor position relative to top left corner of window. */
		maths::Vec2 m_cursorPosDelta; /*!< Change in cursor position. */
		bool m_disableCursor; /*!< Flag for hiding and disabled the cursor movement. */
		bool m_keysDownOld[GLFW_KEY_LAST]; /*!< Array of GLFW key states from old key state. */
		bool m_keysDownNew[GLFW_KEY_LAST]; /*!< Array of GLFW key states from latest key state. */

		//! GLFW callback function for when the cursor position changes.
		static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);

		//! GLFW callback function for when key states change.
		static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	};

} }