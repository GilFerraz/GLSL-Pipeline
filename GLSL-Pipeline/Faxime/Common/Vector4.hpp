#pragma once

#include <GLEW/glew.h>

namespace Faxime::Common
{
    struct Vector4
    {
        Vector4();
        Vector4(GLfloat x);
        Vector4(GLfloat x, GLfloat y);
        Vector4(GLfloat x, GLfloat y, GLfloat z);
        Vector4(GLfloat x, GLfloat y, GLfloat z, GLfloat w);

#pragma region Public Properties

        GLfloat GetX();
        GLfloat GetY();
        GLfloat GetZ();
        GLfloat GetW();

#pragma endregion 

    private:

#pragma region Private Variables

        GLfloat x;
        GLfloat y;
        GLfloat z;
        GLfloat w;

#pragma endregion 

    };
}
