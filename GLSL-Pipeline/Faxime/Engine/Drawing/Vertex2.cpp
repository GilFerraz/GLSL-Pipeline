#include "Vertex2.hpp"

namespace Faxime::Engine::Drawing
{

#pragma region Public Constructors

    Vertex2::Vertex2()
    {
        this->position = Vector2();
        this->color = Color();
        this->uv = UV();
    }

    Vertex2::Vertex2(const Vector2 position)
    {
        this->position = position;
        this->color = Color();
        this->uv = UV();
    }

    Vertex2::Vertex2(const Vector2 position, const Color color)
    {
        this->position = position;
        this->color = color;
        this->uv = UV();
    }

    Vertex2::Vertex2(const Vector2 position, const Color color, const UV uv)
    {
        this->position = position;
        this->color = color;
        this->uv = uv;
    }

#pragma endregion 

#pragma region Public Constructors

    Vertex2::~Vertex2() {}

#pragma endregion 
    
#pragma region Public Property Accessors

    Vector2& Vertex2::GetPosition()
    {
        return position;
    }

    Color& Vertex2::GetColor() 
    {
        return color;
    }

    UV& Vertex2::GetUV()
    {
        return uv;
    }

    //void Vertex2::SetPosition(Vector2 position)
    //{
    //    this->position = position;
    //}

    //void Vertex2::SetColor(Color color)
    //{
    //    this->color = color;
    //}

    //void Vertex2::SetUV(UV uv)
    //{
    //    this->uv = uv;
    //}

#pragma endregion 

}
