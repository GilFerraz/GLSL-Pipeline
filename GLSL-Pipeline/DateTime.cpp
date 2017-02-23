#pragma once

#include "DateTime.hpp"

DateTime::DateTime()
{
}

DateTime::~DateTime()
{
}

std::string DateTime::ToString(time_point<system_clock> timePoint)
{
    time_t now_c = system_clock::to_time_t(timePoint);

    tm now_tm;
    localtime_s(&now_tm, &now_c);

    char buff[32];
    if (strftime(buff, sizeof buff, "%c", &now_tm)) {
        return (buff);
    }

    puts("strftime failed");
    return nullptr;
}
