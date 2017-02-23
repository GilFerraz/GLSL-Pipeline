#pragma once

#include <GLEW/glew.h>
#include <array>

namespace Faxime::Engine::Drawing
{
    class Vertex2;
}

using namespace Faxime::Engine::Drawing;

namespace Faxime::Engine
{
    class Sprite
    {
    public:
        Sprite();
        ~Sprite();

        void Init(GLfloat x, GLfloat y, GLfloat width, GLfloat height);
        void Draw() const;

    private:
        GLfloat x;
        GLfloat y;
        
        GLfloat width;
        GLfloat height;

        GLuint vertexBufferObjectID;

        //const GLfloat* CreateVertices() const;
        std::array<Vertex2, 6>& CreateVertices() const;
    };
}
