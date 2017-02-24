#pragma once

#include <System/String.hpp>
#include <vector>

using namespace System;

namespace Faxime::Engine
{
    class IOManager
    {
    public:

#pragma region Public Static Methods

        /**
         * \brief Nao sei o que isto faz.
         * \param filePath 
         * \param buffer 
         * \return 
         */
        static bool ReadFileToBuffer(std::string filePath, std::vector<unsigned char>& buffer);

#pragma endregion 

    };
}
