#pragma once
#include <SFML/Graphics.hpp>
#include "framework/Core.h"

namespace mz
{
	//a singleton class
	class AssetManager
	{
	public:
		static AssetManager& Get();
		//texture loading functionality
		shared<sf::Texture> LoadTexture(const std::string& path);
		void CleanCycle();
		//function asking client to specify root directory of assets
		void SetAssetRootDirectory(const std::string& directory);
	//protected constructor - allowing anyone else to construct but only inside of the class
	protected:
		AssetManager();

	private:
		static unique<AssetManager> assetManager;
		//because pointer type is static, the whole class shares one and only one copy
		
		//a list for texture load
		Dictionary<std::string, shared<sf::Texture>> _mLoadedTextureMap;
		std::string _mRootDirectory;
	};
}