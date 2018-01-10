#pragma once

/*!
 * @file asset_manager.h
 * @brief Header file for the AssetManager class.
 * @author George McDonagh */


// External includes

#include <string>
#include <unordered_map>


// Internal includes

#include "graphics\mesh.h"
#include "utils\logger.h"
#include "asset.h"


namespace engine { namespace utils {

	class AssetManager
	{
	public:
		template <typename AssetType>
		static AssetType* loadAsset(const char* filepath)
		{
			AssetType* asset = nullptr;

			if (assetExists(filepath))
			{
				asset = dynamic_cast<AssetType*>(m_assets[filepath]);
				asset->load();
			}
			else
			{
				if (typeid(AssetType) == typeid(graphics::Mesh))
					asset = dynamic_cast<AssetType*>(new graphics::Mesh(filepath));

				if (asset->isLoaded())
					m_assets[filepath] = asset;
				else
					utils::Logger::log("ERROR::ASSET_MANAGER::LOAD - Unable to load asset: \tFile: \"%s\".\n\tError message: \"%s\"\n", filepath, asset->getLoadErrorString());
			}

			return asset;
		}
		
		static void unloadAsset(const char* filepath);

		static Asset* getAsset(const char* filepath);

		static bool assetExists(const char* filepath);

		static void unloadAll();

	private:
		static std::unordered_map<std::string, Asset*> m_assets;
	};

} }