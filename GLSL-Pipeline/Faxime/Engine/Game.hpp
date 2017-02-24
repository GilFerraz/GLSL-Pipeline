#pragma once

#include "Sprite.hpp"
#include "GLSLProgram.hpp"

#include <SDL/SDL.h>
#include "Drawing/Texture.hpp"

namespace Faxime::Engine
{
    class Game
    {
    private:

#pragma region Private Variables

        bool isRunning;

        SDL_Window* window;
        int screenWidth;
        int screenHeight;

        GLSLProgram colorProgram;
        float time;

        Sprite sprite;
        Texture texture;

#pragma endregion 

#pragma region Private Instance Methods

        bool Init();
        void InitShaders();
        void GameLoop();
        void ProcessInput();
        void DrawScene();

#pragma endregion 

    public:
        Game();
        Game(int screenWidth, int screenHeight);
        ~Game();

#pragma region Public Instance Methods

        void Run();

#pragma endregion 

    };

}
