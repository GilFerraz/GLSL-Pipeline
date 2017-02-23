#pragma once

#include <GLEW/glew.h>

namespace Faxime::Common
{
    struct Vector2
    {
    private:
        GLfloat x;
        GLfloat y;

    public:

#pragma region Public

        Vector2();
        Vector2(GLfloat x);
        Vector2(GLfloat x, GLfloat y);

        ~Vector2();
    };
}
