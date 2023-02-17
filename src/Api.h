#ifndef API_H
#define API_H

#include <sol/sol.hpp>

class Api
{
public:
    Api();
    ~Api();

    static void Register(sol::state& lua);
};

#endif
