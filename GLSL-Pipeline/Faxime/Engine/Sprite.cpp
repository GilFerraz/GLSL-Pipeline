#include "Sprite.hpp"

#include "Drawing/Vertex2.hpp"

#include <array>
#include <cstddef>
#include <array>
#include <array>

namespace Faxime::Engine
{

#pragma region Constructors

    Sprite::Sprite() : x(0), y(0), width(0), height(0), vertexBufferObjectID(0)
    {
    }

#pragma endregion

#pragma region  Destructor

    Sprite::~Sprite()
    {
        // Destroys the vertex buffer object, if it exists.
        if (vertexBufferObjectID != 0)
        {
            glDeleteBuffers(1, &vertexBufferObjectID);
        }
    }

#pragma endregion

#pragma region Public Instance Methods

    void Sprite::Init(GLfloat x, GLfloat y, GLfloat width, GLfloat height)
    {
        Sprite::x = x;
        Sprite::y = y;
        Sprite::width = width;
        Sprite::height = height;

        // Creates a new vertex buffer object and saves its ID.
        if (vertexBufferObjectID == 0)
        {
            glGenBuffers(1, &vertexBufferObjectID);
        }

        std::array<Vertex2, 6> vertices = CreateVertices();
        //Vertex2* vertices = CreateVertices();

        //link data to buffer
        glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObjectID);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices._Elems, GL_STATIC_DRAW);

        //desligar buffer para n alocar coisas indesejadas
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    void Sprite::Draw() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObjectID);
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex2), reinterpret_cast<void*>(offsetof(Vertex2, GetPosition())));
        glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex2), reinterpret_cast<void*>(offsetof(Vertex2, GetColor())));
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex2), reinterpret_cast<void*>(offsetof(Vertex2, GetUV())));

        glDrawArrays(GL_TRIANGLES, 0, 6);

        glDisableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

#pragma endregion

#pragma region Private Instance Methods

    std::array<Vertex2, 6>& Sprite::CreateVertices() const
    {
        std::array<Vertex2, 6> vertices;

        vertices[0] = Vertex2(Vector2(x + width, y + height), Color(255, 0, 0), UV(1.0F, 1.0F));
        vertices[1] = Vertex2(Vector2(x, y + height), Color(0, 255, 0), UV(0.0F, 1.0F));
        vertices[2] = Vertex2(Vector2(x, y), Color(0, 0, 255), UV(0.0F, 0.0F));

        vertices[3] = Vertex2(Vector2(x, y), Color(0, 0, 255), UV(0.0F, 0.0F));
        vertices[4] = Vertex2(Vector2(x + width, y), Color(0, 255, 0), UV(1.0F, 0.0F));
        vertices[5] = Vertex2(Vector2(x + width, y + height), Color(255, 0, 0), UV(1.0F, 1.0F));

        return vertices;
    }

    //const GLfloat* Sprite::CreateVertices() const
    //{
    //    // 12 = 2(xy) * 2tri
    //    GLfloat vertices[12];
    //
    //    //1st tri
    //    vertices[0].Set = x + width;
    //    vertices[1] = y + height;
    //
    //    vertices[2] = x;
    //    vertices[3] = y + height;
    //
    //    vertices[4] = x;
    //    vertices[5] = y;
    //
    //    //2nd tri
    //    vertices[6] = x;
    //    vertices[7] = y;
    //
    //    vertices[8] = x + width;
    //    vertices[9] = y;
    //
    //    vertices[10] = x + width;
    //    vertices[11] = y + height;
    //
    //    return vertices;
    //}

#pragma endregion

}
