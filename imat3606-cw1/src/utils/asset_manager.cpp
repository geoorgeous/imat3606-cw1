/*!
 * @file asset_manager.cpp
 * @brief Implimentation file for the AssetManager class.
 * @author George McDonagh */


// Local includes

#include "utils\asset_manager.h"


// Namespaces 

using namespace engine::utils;


// Static variables

std::unordered_map<std::string, engine::Asset*> AssetManager::m_assets;


void AssetManager::unloadAsset(const char* filepath)
{
	if (assetExists(filepath))
		m_assets[filepath]->unload();
}

engine::Asset* AssetManager::getAsset(const char* filepath)
{
	if (assetExists(filepath))
		return m_assets[filepath];
	
	// Could not find element in map, log error and return null pointer.

	utils::Logger::log("ERROR::ASSET_MANAGET::GET - Asset not found: \"%s\"", filepath);
	return nullptr;
}

bool AssetManager::assetExists(const char* filepath)
{
	return (m_assets.find(filepath) != m_assets.end());
}

void AssetManager::unloadAll()
{
	for (auto it = m_assets.begin(); it != m_assets.end(); it++)
		delete it->second;
}