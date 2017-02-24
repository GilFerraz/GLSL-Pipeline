#include "IOManager.hpp"

#include <fstream>
#include <System/Console.hpp>

namespace Faxime::Engine
{

#pragma region Public Static Methods

    bool IOManager::ReadFileToBuffer(std::string filePath, std::vector<unsigned char>& buffer)
    {
        std::ifstream file(filePath, std::ios::binary);
        if (file.fail())
        {
            Console::WriteLine("Failed to open " + filePath);
            return false;
        }

        // Seek to the end.
        file.seekg(0, std::ios::end);

        // Gets the file size.
        int fileSize = file.tellg();
        file.seekg(0, std::ios::beg);

        // Reads the file.
        fileSize -= file.tellg();

        buffer.resize(fileSize);
        file.read(reinterpret_cast<char*>(&buffer[0]), fileSize);
        file.close();
    }

#pragma endregion 

}
