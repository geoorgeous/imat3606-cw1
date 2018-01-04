#pragma once

/*!
 * @file engine.h 
 * @brief The project's main header file.
 * @author George McDonagh */


// External includes

#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <vector>
#include <DearIMGUI\imgui.h>


// Local includes

#include "graphics/window.h"
#include "utils/logger.h"


// Macros

#define SCREEN_WIDTH 1600.0f
#define SCREEN_HEIGHT 900.0f
#define CLEAR_COLOUR 0.5f, 0.5f, 0.5f, 1.0f


//! Primary namespace for FYP project
namespace engine {

	//! Helpful utility functions functionality.
	namespace utils {}

}

// Namespaces

using namespace engine;