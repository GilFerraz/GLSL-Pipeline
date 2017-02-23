#include "Vector4.hpp"

namespace Faxime::Common
{

#pragma region Public Constructors

    Vector4::Vector4() : x(0.0F), y(0.0F), z(0.0F), w(0.0f) {}

    Vector4::Vector4(GLfloat x): x(x), y(0.0F), z(0.0F), w(0.0f) {}

#pragma endregion 

}
