#pragma once

#include <GLEW/glew.h>

namespace Faxime::Engine::Drawing
{
    struct UV final
    {
    private:
        GLfloat u;
        GLfloat v;

    public:

        UV();

        explicit UV(const GLfloat u);

        UV(const GLfloat u, const GLfloat v);

        ~UV();
    };
}
