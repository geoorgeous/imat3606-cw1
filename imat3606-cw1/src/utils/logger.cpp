/*!
 * @file logger.cpp
 * @brief Implimentation file for the Logger class.
 * @author George McDonagh */


// Local includes

#include "utils\logger.h"


// Namespaces 

using namespace engine::utils;


// Static variables

HANDLE Logger::hConsole;
ConsoleColour Logger::backColour = ConsoleColour::LOG_CC_DEFAULTBACK;
ConsoleColour Logger::foreColour = ConsoleColour::LOG_CC_DEFAULTFORE;
ConsoleColour Logger::oldBackColour = backColour;
ConsoleColour Logger::oldForeColour = foreColour;


void Logger::log(const char* fmt, fmt::ArgList args)
{
	fmt::printf(fmt, args);
}

void Logger::log(ConsoleColour foreColour, ConsoleColour backColour, const char* fmt, fmt::ArgList args)
{
	setBackColour(backColour);
	setForeColour(foreColour);
	log(fmt, args);
	setBackColour(oldBackColour);
	setForeColour(oldForeColour);
}

void Logger::logWarning(const char* fmt, fmt::ArgList args)
{
	setForeColour(ConsoleColour::LOG_CC_YELLOW);
	log(fmt, args);
	setBackColour(oldBackColour);
	setForeColour(oldForeColour);
}

void Logger::logError(const char* fmt, fmt::ArgList args)
{
	setForeColour(ConsoleColour::LOG_CC_RED);
	log(fmt, args);
	setBackColour(oldBackColour);
	setForeColour(oldForeColour);
}

void Logger::logNewLine()
{
	log("\n");
}

void Logger::updateConsoleColours()
{
	if (!hConsole)
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, foreColour + backColour * 16);
}

void Logger::setForeColour(ConsoleColour colour)
{
	if (colour != foreColour && colour != ConsoleColour::LOG_CC_UNCHANGED)
	{
		oldForeColour = foreColour;
		foreColour = colour;
		updateConsoleColours();
	}
}

void Logger::setBackColour(ConsoleColour colour)
{
	if (colour != backColour && colour != ConsoleColour::LOG_CC_UNCHANGED)
	{
		oldBackColour = backColour;
		backColour = colour;
		updateConsoleColours();
	}
}

void Logger::glClearErrorQueue()
{
	while (glGetError() != GL_NO_ERROR);
}

bool Logger::glCheckErrors(const char* function, const char* file, const int line)
{
	while (GLenum glError = glGetError())
	{
		log("OpenGL Error: [%i] in \"%s\" on line %i. Function: %s", glError, file, line, function);
		return false;
	}
	return true;
}