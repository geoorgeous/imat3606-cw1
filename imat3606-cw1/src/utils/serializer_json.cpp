/*!
 * @file serializer_json.cpp
 * @brief Implimentation file for SerializerJSON class.
 * @author George McDonagh */


// Local includes

#include "utils\serializer_json.h"


// Namespaces 

using namespace engine::utils;


bool SerializerJSON::openFile(const char* filepath)
{
	std::fstream file;
	file.open(filepath);

	if (!file.is_open())
	{
		utils::Logger::log("ERROR::SERIALIZER_JSON::OPEN_FILE - Failed to open file: \"%s\".", filepath);
		return false;
	}

	Json::Value root;
	Json::Reader reader;

	// Check for parser errors.
	if (!reader.parse(file, root))
	{
		utils::Logger::log("ERROR::SERIALIZER_JSON::OPEN_FILE - Failed to parse JSON in \"%s\": \"%s\".", filepath, reader.getFormattedErrorMessages());
		return false;
	}

	return true;
}