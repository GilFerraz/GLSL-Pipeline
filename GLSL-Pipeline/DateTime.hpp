#pragma once

#include <chrono>
#include <string>

using namespace std::chrono;

class DateTime
{
public:
    DateTime();
    ~DateTime();

    static std::string ToString(time_point<system_clock> timePoint);
};
