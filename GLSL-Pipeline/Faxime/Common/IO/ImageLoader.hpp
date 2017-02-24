#pragma once

#include "../../Engine/Drawing/Texture.hpp"
#include <string>

namespace System {
    class String;
}

using namespace System;

namespace Faxime::Common::IO
{
    class ImageLoader
    {
    public:

        /**
         * \brief 
         * \param filePath 
         * \return 
         */
        static Texture LoadPNG(std::string filePath);
    };
}
