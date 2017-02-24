#include "ImageLoader.hpp"

#include "IOManager.hpp"
#include "../../../PicoPNG.hpp"

#include <System/String.hpp>
#include <System/Console.hpp>
#include <GLEW/glew.h>
#include <vector>

using namespace Faxime::Engine;

namespace Faxime::Common::IO
{
    Texture ImageLoader::LoadPNG(std::string filePath)
    {
        Texture texture;

        std::vector<unsigned char> in;
        std::vector<unsigned char> out;

        unsigned long width;
        unsigned long height;

        if (!IOManager::ReadFileToBuffer(filePath, in))
        {
            Console::WriteLine("Failed to load PNG");
        }

        Int32 errorCode = PicoPNG::DecodePNG(out, width, height, &(in[0]), in.size());

        if (errorCode != 0)
        {
            Console::WriteLine("Decode PNG failed!" + errorCode);
        }

        texture.width = width;
        texture.height = height;

        // Createss a GL Textures.
        glGenTextures(1, &texture.id);

        // Binds Textures.
        glBindTexture(GL_TEXTURE_2D, texture.id);

        // Assigns data to GL Texture.
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &(out[0]));

        // Setup texture parameters.
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);

        // Automatically generates mipmap levels.
        glGenerateMipmap(GL_TEXTURE_2D);

        // Unbinds.
        glBindTexture(GL_TEXTURE_2D, 0);

        return texture;
    }
}
