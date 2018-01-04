#pragma once

/*!
 * @file logger.h
 * @brief Header file for the Logger class.
 * @author George McDonagh */


// External includes

#define NOMINMAX // Gets rid of horrible errors... don't remove.
#include <windows.h>
#undef NOMINMAX

#include <GL\glew.h>
#include <iostream>
#include <string>
#include <stdarg.h>
#include <fmt\format.h>
#include <fmt\printf.h>


// Macros

#define ASSERT(x)\
	if(!(x)) __debugbreak();

#define GL_CALL(x)\
	engine::utils::Logger::glClearErrorQueue();\
	x;\
	ASSERT(engine::utils::Logger::glCheckErrors(#x, __FILE__, __LINE__))


// Namespaces

namespace engine { namespace utils { 

	//! The different Console output colours.
	enum ConsoleColour : short
	{
		LOG_CC_UNCHANGED	= -1,

		LOG_CC_BLACK		= 0,
		LOG_CC_NAVY			= 1,
		LOG_CC_DARKGREEN	= 2,
		LOG_CC_TEAL			= 3,
		LOG_CC_CRIMSON		= 4,
		LOG_CC_PURPLE		= 5,
		LOG_CC_DARKYELLOW	= 6,
		LOG_CC_OFFWHITE		= 7,
		LOG_CC_GREY			= 8,
		LOG_CC_BLUE			= 9,
		LOG_CC_GREEN		= 10,
		LOG_CC_LIGHTBLUE	= 11,
		LOG_CC_RED			= 12,
		LOG_CC_PINK			= 13,
		LOG_CC_YELLOW		= 14,
		LOG_CC_WHITE		= 15,

		LOG_CC_DEFAULTBACK	= LOG_CC_BLACK,
		LOG_CC_DEFAULTFORE	= LOG_CC_OFFWHITE
	};

	//! Satic class providing some simple console-logging functionality.
	/*! Simplifies outputting helpful information to the console (Windows) and also wraps colour-changing functionality using the WIN API. */
	class Logger
	{
	public:
		//! Logs a new-line character.
		/*! Logs a new-line character ("\n") to the console. */
		static void logNewLine();

		//! Sets the logging text colour.
		/*! Sets the console window's current output foreground (text) colour to the specified colour.
		  * @param colour The new foreground colour (use "LOG_COLOUR_*"). */
		static void setForeColour(ConsoleColour colour);

		//! Sets the logging background colour.
		/*! Sets the console window's current output background colour to the specified colour (use LOG_COLOUR_* macros).
		  * @param colour The new background colour (use "LOG_COLOUR_*"). */
		static void setBackColour(ConsoleColour colour);

		//! Clear OpenGL's error queue.
		/*! Pops all of OpenGL's error off of its error queue without taking any action. 
		  * @warning Calling this function will get rid of any un-processed OpenGL errors. */
		static void glClearErrorQueue();

		//! Check for OpenGL errors.
		/*! Logs an error message for the first error in OpenGL's error queue.
		  * @param function The name of the function @p glCheckErrors is being called inside of. 
		  * @param filename The name of the file that @p function is in.
		  * @param lineNumber The line number of where @p glCheckErrors is being called from.
		  * @return True if the OpenGL error queue is empty. */
		static bool glCheckErrors(const char* function, const char* filename, const int lineNumber);

	private:
		static HANDLE hConsole; /*!< A handle to the console window. */

		static ConsoleColour oldForeColour; /*!< The old console window foreground (text) colour. */
		static ConsoleColour oldBackColour; /*!< The old console window background colour. */

		static ConsoleColour foreColour; /*!< The current console window foreground (text) colour. */
		static ConsoleColour backColour; /*!< The current console window background colour. */

		//! Updates the console colours to match the stored values.
		static void updateConsoleColours();

		//! Logs a string.
		/*! Logs the specified string using the colours that are currently being used.
		  * @param string The string to output to the console. */
		static void log(const char* fmt, fmt::ArgList args);

		//! Logs a string using the specified colours.
		/*! Logs the specified string using a specified colour and background colour.
		  * @param string The string to output to the console.
		  * @param foreColour The colour to use for the string's text.
		  * @param backColour The colour to use for the stirng's background. */
		static void log(ConsoleColour foreColour, ConsoleColour backColour, const char* fmt, fmt::ArgList args);

		//! Logs a warning string.
		/*! Logs the specified string as a warning, using the warning log colour settings (yellow text on black background).
		  * @param warning The warning string to output to the console. */
		static void logWarning(const char* warning, fmt::ArgList args);

		//! Logs an error string.
		/*! Logs the specified string as an error, using the error log colour settings (red text on black background).
		  * @param error The error string to output to the console. */
		static void logError(const char* error, fmt::ArgList args);

	public:
		// Create overides of the above functions with variable-number of arguments using the fmt library FMT_VARIADIC macro...

		FMT_VARIADIC(static void, log, const char *)

		FMT_VARIADIC(static void, log, ConsoleColour, ConsoleColour, const char *)

		FMT_VARIADIC(static void, logWarning, const char *)

		FMT_VARIADIC(static void, logError, const char *)
	};

} }