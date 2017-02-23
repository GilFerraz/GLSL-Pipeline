#include "Debug.hpp"

#include <System/Console.hpp>
#include <System/String.hpp>

using namespace System;

namespace Faxime::Common
{

#pragma region Private Constructors

    Debug::Debug() {}

#pragma endregion 

#pragma region Private Destructor

    Debug::~Debug() {}

#pragma endregion 

#pragma region Private Static Methods

    String Debug::GetCurrentTime()
    {
        return DateTime::ToString(system_clock::now());
    }

#pragma endregion 

}
