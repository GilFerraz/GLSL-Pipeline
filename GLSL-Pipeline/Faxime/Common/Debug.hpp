#pragma once

#include "../../DateTime.hpp"

#include <System/String.hpp>
#include <System/Console.hpp>

using namespace System;

namespace Faxime::Common
{
    class Debug
    {
    public:
        template <class T>
        static void Log(String value);

        template <class T>
        static void LogWarning(String value);

        template <class T>
        static void LogError(String value);

    private:
        Debug();
        ~Debug();

        template <class T>
        static void Log(String prefix, String debugType, String log);

        static String GetCurrentTime();
    };

#pragma region Public Static Methods

    template <class T>
    void Debug::Log(String value)
    {
        Log<T>("", "DEBUG", value);
    }

    template <class T>
    void Debug::LogWarning(String value)
    {
    }

    template <class T>
    void Debug::LogError(String value)
    {
    }

#pragma endregion

#pragma region Private Static Methods

    template <class T>
    void Debug::Log(String prefix, String debugType, String log)
    {
        String currentTime = GetCurrentTime();
        String className = typeid(T).name();

        Console::WriteLine(prefix + " " + debugType + " [" + currentTime + "]" + " " + "[" + className + "]" + " " + log);
    }

#pragma endregion 

}
