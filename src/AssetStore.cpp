#include "AssetStore.h"
#include "Logger.h"

AssetStore::AssetStore()
{

}

AssetStore::~AssetStore()
{

}

void AssetStore::ClearAssets()
{
    for (auto texture : textures)
    {
        UnloadTexture(texture.second);
    }

    textures.clear();
}

void AssetStore::AddTexture(const std::string& name, const std::string& path)
{
    Texture texture = LoadTexture(path.c_str());

    textures.emplace(name, texture);

    Logger::Log("Loaded texture: " + name);
}

Texture AssetStore::GetTexture(const std::string& name)
{
    return textures[name];
}
