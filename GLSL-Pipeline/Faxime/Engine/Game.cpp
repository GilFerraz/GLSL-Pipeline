#pragma once
#include "Game.hpp"

#include <System/Console.hpp>
#include <System/String.hpp>

#include <iostream>

using namespace System;

namespace Faxime::Engine
{

#pragma region Constructors

    Game::Game() : isRunning(false), window(nullptr), screenWidth(1280), screenHeight(720)
    {
    }

    Game::Game(int screenWidth, int screenHeight) : isRunning(false), window(nullptr)
    {
        Game::screenWidth = screenWidth;
        Game::screenHeight = screenHeight;
    }

#pragma endregion 

#pragma region Destructors

    Game::~Game()
    {
    }

#pragma endregion 

#pragma region Public Instance Methods

    void Game::Run()
    {
        Init();
        sprite.Init(-0.5F, -0.5F, 1.0F, 1.0F);
        GameLoop();
    }

#pragma endregion 

    bool Game::Init()
    {
        // Initializes SDL.
        SDL_Init(SDL_INIT_EVERYTHING);

        // Creates window.
        window = SDL_CreateWindow("GLSL Introduction", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight,
            SDL_WINDOW_OPENGL);
        if (window == nullptr)
        {
            Console::WriteLine("SDL Window failed!");

            return false;
        }

        // Creates the OpenGL context.
        SDL_GLContext glContext = SDL_GL_CreateContext(window);
        if (glContext == nullptr)
        {
            Console::WriteLine("GL Context failed!");
            return false;
        }

        // Only if necessary.
        //glewExperimental = true;

        // Initializes GLEW.
        GLenum glEnum = glewInit();
        if (glEnum != GLEW_OK)
        {
            Console::WriteLine("GLEW failed!");
            return false;
        }

        // Sets the OpenGL to use double buffering.
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

        // Clears the screen buffer.
        glClearColor(1.0F, 1.0F, 1.0F, 1.0F);

        InitShaders();

        return true;
    }

    void Game::InitShaders()
    {
        colorProgram.CompileShaders("Shaders/Faxime/Color.vs", "Shaders/Faxime/Color.fs");

        colorProgram.AddAttribute("vertexPosition");
        colorProgram.AddAttribute("vertexColor");
        colorProgram.AddAttribute("vertexUV");

        colorProgram.LinkShaders();
    }

    void Game::GameLoop()
    {
        isRunning = true;
        while (isRunning)
        {
            ProcessInput();
            
            time += 0.02F;

            DrawScene();
        }
    }

    void Game::DrawScene()
    {
        // Clears GL buffers.
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Draws triangle.
        //glBegin(GL_TRIANGLES);
        //glVertex2f(0.0F, 0.0F);
        //glVertex2f(1.0F, 0.0F);
        //glVertex2f(1.0F, 1.0F);
        //glEnd();

        colorProgram.Use();

        //uniforms
        GLint timeLocation = colorProgram.GetUniformLocation("time");
        //link
        glUniform1f(timeLocation, time);

        sprite.Draw();

        colorProgram.Unuse();

        // Swaps buffers with new scene buffer.
        SDL_GL_SwapWindow(window);
    }

    void Game::ProcessInput()
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                isRunning = false;
                break;
            case SDL_MOUSEMOTION:
                break;
            default:;
            }
        }
    }
}
