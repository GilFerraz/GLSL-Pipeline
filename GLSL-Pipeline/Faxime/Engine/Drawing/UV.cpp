#include "UV.hpp"

namespace Faxime::Engine::Drawing
{

#pragma region Public Constructors

    UV::UV()
    {
        UV(0.0F, 0.0F);
    }

    UV::UV(const GLfloat u)
    {
        UV(u, 0.0F);
    }

    UV::UV(const GLfloat u, const GLfloat v)
    {
        this->u = u;
        this->v = v;
    }

#pragma endregion 

#pragma region Public Destructor

    UV::~UV()
    {
    }

#pragma endregion 

}
