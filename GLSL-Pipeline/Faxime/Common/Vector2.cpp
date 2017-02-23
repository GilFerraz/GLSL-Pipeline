#include "Vector2.hpp"

namespace Faxime::Common
{

#pragma region Public Constructors

    Vector2::Vector2() : x(0.0F), y(0.0F) {}

    Vector2::Vector2(GLfloat x) : x(x), y(0.0F) {}

    Vector2::Vector2(GLfloat x, GLfloat y) : x(x), y(y) {}

#pragma endregion 

#pragma region Public Destructor

    Vector2::~Vector2() {}

#pragma region

}
