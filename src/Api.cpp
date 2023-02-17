#include "Api.h"
#include "Logger.h"

Api::Api()
{

}

Api::~Api()
{

}

void Api::Register(sol::state& lua)
{
    sol::table api = lua.create_named_table("api");

    api.set_function("log", [](const std::string& message) {
        Logger::Log(message);
    });
}
