#pragma once

#include "../../../Interface.hpp"
#include "../../Object.hpp"
#include "../../IDisposable.hpp"

namespace System::Collections::Generic
{
    template<typename T = Object>
    interface IEnumerator : IDisposable
    {
#pragma region Public Virtual Properties

        /**
         * \brief
         * \return
         */
        virtual T GetCurrent() = 0;

#pragma endregion 

#pragma region Public Virtual Instance Methods

        /**
         * \brief
         * \return
         */
        virtual bool MoveNext() = 0;

        /**
         * \brief
         */
        virtual void Reset() = 0;

#pragma endregion 

        virtual void Dispose() = 0;
    };
}