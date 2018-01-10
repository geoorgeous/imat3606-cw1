#pragma once

/*! @file asset.h 
  * @brief Header file for Asset class. 
  * @author George McDonagh */


// External includes

#include <string>


// Namespaces

namespace engine {

	//! Abstract parent class for all asset classes.
	class Asset
	{
	public:
		//! Asset constructor.
		/*! @param filepath The filepath for the Asset file. */
		Asset(const char* filepath);

		//! Load the Asset's data in to memory.
		/*! @return True if the Asset loaded successfully.
		  * @note If there is a failure to load then an error message should be stored in @p m_loadErrorString. */
		virtual bool load() = 0;

		//! Unload the Asset's data from memory.
		virtual void unload() = 0;
		
		//! Get the error string generated froma failure to load.
		/*! @return A reference to an immutable string. The error message generated when the Asset fails to load successfully. Returns an empty string if no error message was cached. */
		const std::string& getLoadErrorString() const;

		//! Get if the Asset has loaded.
		/*! @return The current value of m_isLoaded. */
		bool isLoaded();

	protected:
		std::string m_filepath; /*!< The Asset's file's filepath. */
		std::string m_loadErrorString; /*!< TThe error message generated in @p load() upon failure to load. */
		bool m_isLoaded; /*!< Boolean value for if the Asset has been successfully loaded or not. */
	};

}