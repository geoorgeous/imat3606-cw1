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

namespace engine { namespace utils {

	//! Interface for Serializers.
	class ISerializer
	{
	public:
		//! Deserialize from a file.
		/*! @param filepath The filepath of the file to deserialize from.
		  * @return The object which was created from deserializing the specified file. */
		template <typename T>
		static T read(const char* filepath) = 0;

		//! Serialize an object.
		/*! @param object A reference to the immutable Object to serialize. */
		template <typename T>
		static void write(const T& object) = 0;

	private:
		//! Attempt to open a file ready for deserialization.
		/*! @param filepath The filepath of the file to open.
		  * @return False if the file failed to open. */
		virtual bool openFile(const char* filepath) = 0;
	};

} }