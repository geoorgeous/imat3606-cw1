#pragma once

/*! @file asset.h 
  * @brief Header file for Asset class. 
  * @author George McDonagh */


// External includes

#include <string>


// Namespaces

namespace engine {

	//! Base class for all asset classes.
	class Asset
	{
	public:
		static enum AssetType
		{
			MESH
		};

		Asset(const char* filepath);

		virtual void load() = 0;

		virtual void unload() = 0;

		std::string getLoadErrorString();

		bool isLoaded();

	protected:
		std::string m_filepath;
		std::string m_loadErrorString;
		bool m_isLoaded;
	};

}