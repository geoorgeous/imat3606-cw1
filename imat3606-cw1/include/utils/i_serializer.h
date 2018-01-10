#pragma once

/*!
 * @file i_serializer.h
 * @brief Interface for engine serializers.
 * @author George McDonagh */


// Internal includes

#include "graphics\scene_3d.h"
#include "utils\logger.h"
#include "game.h"


// Namespaces

namespace engine {

	namespace utils {

	//! Interface for Serializers.
	class ISerializer
	{
	public:
		template <typename T>
		static T read(const char* filepath) = 0;

		template <typename T>
		static void write(const T& object) = 0;

	private:
		virtual bool openFile(const char* filepath) = 0;
	};

} }