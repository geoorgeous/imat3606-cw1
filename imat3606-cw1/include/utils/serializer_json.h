#pragma once

/*!
 * @file serializer_json.h
 * @brief Header file for SerializerJSON class.
 * @author George McDonagh */


// External includes

#include <fstream>
#include <json\json.h>


// Internal includes

#include "utils\i_serializer.h"


// Namespaces

namespace engine { namespace utils {

	class SerializerJSON : public ISerializer
	{
	public:
		template <typename T>
		static T read(const char* filepath)
		{
			utils::Logger::log("ERROR::I_SERIALIZER::READ - Object type is not a serialieable type.");
		}

		template <>
		static Game read<Game>(const char* filepath)
		{

		}

		template <>
		static graphics::Scene3D read<graphics::Scene3D>(const char* filepath)
		{

		}

		template <typename T>
		static void write(const T& object)
		{
			utils::Logger::log("ERROR::I_SERIALIZER::WRITE - Object type is not a serialieable type.");
		}

		template <>
		static void write<Game>(const Game& game)
		{

		}

		template <>
		static void write<graphics::Scene3D>(const graphics::Scene3D& scene)
		{

		}

	private:
		bool openFile(const char* filepath) override;
	};

} }