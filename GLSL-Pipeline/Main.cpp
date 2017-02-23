#pragma once

#include <System/Action.hpp>
#include <System/Console.hpp>
#include <System/String.hpp>
#include <System/Int32.hpp>
#include <System/Collections/Generic/List.hpp>

#include "Faxime/Common/Debug.hpp"
#include "Faxime/Engine/Sprite.hpp"
#include "Faxime/Engine/Game.hpp"

using namespace Faxime::Common;
using namespace Faxime::Engine;

using namespace System;
using namespace System::Collections::Generic;

int main(int argc, char** argv)
{
    //Debug::Log<Game>("Hello world!");

    Action<> action = []() -> void { Console::WriteLine("Action Works." + Int32(1)); };
    action.Invoke();

    Game game;
    game.Run();

    return 0;
}