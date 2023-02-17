#include "Game.h"
#include "Logger.h"
#include "Api.h"

#include <raylib.h>
#include <rlImGui.h>

int Game::windowWidth = 800;
int Game::windowHeight = 600;

Game::Game()
{
    isRunning = false;
    assetStore = std::make_unique<AssetStore>();
    registry = std::make_unique<entt::registry>();
}

Game::~Game()
{

}

void Game::Initialize()
{
    SetTraceLogLevel(LOG_NONE);
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(windowWidth, windowHeight, "GE by Vinny Horgan");
    SetTargetFPS(60);
    SetExitKey(KEY_NULL);

    InitAudioDevice();

    rlImGuiSetup(true);

    isRunning = true;

    Api::Register(lua);

    lua.open_libraries(sol::lib::base, sol::lib::math, sol::lib::os);

    sol::load_result result = lua.load_file("demo/main.lua");
    if (!result.valid())
    {
        sol::error err = result;
        std::string errorMessage = err.what();
        Logger::Err("Error loading lua script: " + errorMessage);

        isRunning = false;
    }
    else
    {
        lua.script_file("demo/main.lua");
    }
}

void Game::Update()
{
    if (WindowShouldClose())
    {
        isRunning = false;
    }

    lua["api"]["update"]();
}

void Game::Render()
{
    BeginDrawing();

    ClearBackground(BLACK);

    rlImGuiBegin();

    lua["api"]["draw"]();

    ImGui::ShowDemoWindow();

    rlImGuiEnd();

    EndDrawing();
}

void Game::Run()
{
    while (isRunning)
    {
        Update();
        Render();
    }
}

void Game::Destroy()
{
    rlImGuiShutdown();

    CloseAudioDevice();
    CloseWindow();
}
