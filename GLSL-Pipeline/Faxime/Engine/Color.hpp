#pragma once
#include <GLEW/glew.h>

namespace Faxime::Engine
{
    struct Color
    {
    private:
        GLubyte red;
        GLubyte green;
        GLubyte blue;
        GLubyte alpha;

    public:
        
        Color();
        Color(GLubyte red, GLubyte green, GLubyte blue);
        Color(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha);

        ~Color();
    };
}
