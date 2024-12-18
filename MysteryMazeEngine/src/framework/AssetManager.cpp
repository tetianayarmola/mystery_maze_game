#include "framework/AssetManager.h"

namespace mz
{
	//initialise pointer with null pointer
	unique<AssetManager> AssetManager::assetManager{ nullptr };

	AssetManager& AssetManager::Get()
	{
		//check if assetManager is null 
		if (!assetManager)
		{
			assetManager = unique<AssetManager>{ new AssetManager };
		}

		return *assetManager;
	}
	shared<sf::Texture> AssetManager::LoadTexture(const std::string& path)
	{
		auto found = _mLoadedTextureMap.find(path); //returns the iterator of Dictionary
		if (found != _mLoadedTextureMap.end()) //if we reached the end and did not found the texture
		{
			return found->second; //returns key value pair (second value is a texture)
		}

		//if texture was not found as loaded already, we load it
		shared<sf::Texture> newTexture{ new sf::Texture }; //initialise with a new texture
		//if we loaded texture successfully
		if (newTexture->loadFromFile(_mRootDirectory + path))
		{
			//then we put texture as a texture map
			_mLoadedTextureMap.insert({path, newTexture}); //kay-value pair: path - key, texture - value
			return newTexture;
		}

		//if nothing can be loaded -> path or texture name is wrong, return null pointer
		return shared<sf::Texture> {nullptr};
	}

	void AssetManager::CleanCycle()
	{
		//checks if texture still exist
		for (auto iter = _mLoadedTextureMap.begin(); iter != _mLoadedTextureMap.end(); )
		{
			//if nothing else holds a shared pointer of the texture
			if (iter->second.unique())
			{
				LOG("! - cleaning texture: %s", iter->first);
				//it is no longer needed -> remove
				iter = _mLoadedTextureMap.erase(iter);
			}
			else
			{
				++iter;
			}
		}
	}

	void AssetManager::SetAssetRootDirectory(const std::string& directory)
	{
		_mRootDirectory = directory;
	}

	AssetManager::AssetManager() 
		:_mRootDirectory{} //initialise root dir with nothing
	{
	}
}