#include "Color.hpp"

namespace Faxime::Engine
{
    Color::Color()
    {
        Color(0, 0, 0, 1);
    }

    Color::Color(GLubyte red, GLubyte green, GLubyte blue)
    {
        Color(red, green, blue, 1);
    }

    Color::Color(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha)
    {
        this->red = red;
        this->green = green;
        this->blue = blue;
        this->alpha = alpha;
    }

    Color::~Color() {}
}
