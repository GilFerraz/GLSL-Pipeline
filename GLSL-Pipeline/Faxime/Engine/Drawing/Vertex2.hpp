#pragma once

#include "../../Common/Vector2.hpp"
#include "../Color.hpp"
#include "UV.hpp"

using namespace Faxime::Common;

namespace Faxime::Engine::Drawing
{
    class Vertex2
    {
    private:
        Vector2 position;
        Color color;
        UV uv;

    public:

        float puta;

#pragma region Public Constructors

        Vertex2();

        explicit Vertex2(const Vector2 position);

        Vertex2(const Vector2 position, const Color color);

        Vertex2(const Vector2 position, const Color color, const UV uv);

#pragma endregion 


#pragma region Public Destructors

        ~Vertex2();

#pragma endregion 

        //TODO: Should vertex be rewritable after initialization?

        Vector2& GetPosition();
        //void SetPosition(Vector2 position);

        Color& GetColor();
        //void SetColor(Color color);

        UV& GetUV();
        //void SetUV(UV uv);
    };
}
