#ifndef GAME_H
#define GAME_H

#include "AssetStore.h"

#define SOL_ALL_SAFETIES_ON 1
#include <sol/sol.hpp>
#include <entt.hpp>

class Game
{
private:
    bool isRunning;

    sol::state lua;

    std::unique_ptr<AssetStore> assetStore;
    std::unique_ptr<entt::registry> registry;

public:
    Game();
    ~Game();

    void Initialize();
    void Run();
    void Update();
    void Render();
    void Destroy();

    static int windowWidth;
    static int windowHeight;
};

#endif
