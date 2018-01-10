#pragma once

/*! @file component.h
  * @brief Header file for Component class.
  * @author George McDonagh */


// Namespaces

namespace engine {

	//! Parent class for various SceneObject component's classes.
	class Component
	{
	public:
		//! Virtual compiler-default destructor to enforce abstract class.
		virtual ~Component() = default;
	};

}