/*! @file asset.cpp
  * @brief Implementation file for Asset class.
  * @author George McDonagh */


// Internal includes

#include "asset.h"


using namespace engine;


Asset::Asset(const char* filepath)
	: m_filepath(filepath), m_isLoaded(false) { }

std::string Asset::getLoadErrorString()
{
	return m_loadErrorString;
}

bool Asset::isLoaded()
{
	return m_isLoaded;
}