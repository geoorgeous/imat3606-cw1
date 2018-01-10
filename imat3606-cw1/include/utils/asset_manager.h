#pragma once

/*!
  * @file asset_manager.h
  * @brief Header file for the AssetManager class.
  * @author George McDonagh */


// External includes

#include <stdexcept>
#include <string>
#include <typeindex>
#include <unordered_map>


// Internal includes

#include "graphics\mesh.h"
#include "utils\logger.h"
#include "asset.h"


// Namespaces

namespace engine { namespace utils {

	//! Game assets manager.
	/*! Contains static asset-management functions and a static collection of game assets. */
	class AssetManager
	{
	public:
		//! Loads an asset and adds it to the current Asset collection if not already existing witin it.
		/*! @param filepath The Asset's filepath. 
		  * @return A pointer to the Asset which has ust been loaded. 
		  * @note Return @p nullptr if the Asset failed to load. */
		template <typename AssetType>
		static AssetType* loadAsset(const char* filepath)
		{
			// Throw an exception if the template type does not derive from Asset.
			if (std::is_base_of<Asset, AssetType>())
			{
				AssetType* asset = nullptr;

				if (assetExists(filepath))
				{
					// If the asset exists already then all we need to do is load the asset again and return it...
					asset = dynamic_cast<AssetType*>(m_assets[filepath]);
					// We don't have to check if the assets loaded properly as assets will only exist AssetManager's collection if they have already loaded correctly.
					asset->load();

					return asset;
				}
				else
				{
					// If the asset doesn't exist yet then try and find the typeid of AssetType and create the asset.
					if (typeid(AssetType) == typeid(graphics::Mesh))
						asset = new graphics::Mesh(filepath);

					// If the asset loaded successfully, add to collection and return it. If not - log an error.
					if (asset->isLoaded())
					{
						m_assets[filepath] = asset;
						return asset;
					}
					else
						utils::Logger::log("ERROR::ASSET_MANAGER::LOAD - Unable to load asset: \tFile: \"%s\".\n\tError message: \"%s\"\n", filepath, asset->getLoadErrorString());
				}
			}
			else
				throw std::invalid_argument("Type does not derive from type Asset.");

			// If we reach this point then something went wrong... return a nullptr.
			return nullptr;
		}
		
		//! Unload an Asset's data from memory.
		/*! @param filepath The filepath of the Asset to unload. 
		  * @note This function will do nothing if the filepath does not corrospond to an existing Asset's filepath. */
		static void unloadAsset(const char* filepath);

		//! Get an existing Asset.
		/*! @param filepath The filepath of the Asset to get.
		  * @return A pointer to a mutable Asset. 
		  * @note This function will return a @p nullptr and log an error if it cannot find the Asset.*/
		static Asset* getAsset(const char* filepath);

		//! Check to see if an Asset exists.
		/*! Check to see if an Asset with a specific filepath exists.
		  * @param filepath The filepath of the Asset to check to see exists.
		  * @return @p true if the Asset is found in AssetManager's collection of assets. */
		static bool assetExists(const char* filepath);

		//! Unloads all of the currently loaded Assets.
		static void unloadAll();

	private:
		static std::unordered_map<std::string, Asset*> m_assets; /*!< AssetManager's collection of Asset pointers, using their filepaths as keys. */
	};

} }