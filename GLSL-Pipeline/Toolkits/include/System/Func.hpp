#pragma once

#include "DLL.hpp"
#include <functional>

namespace System
{
    /**
     * \brief Encapsulates a method that has specified parameters and returns a value of the type specified by the TResult
     *        parameter. Unlike in other .NET languages, the first paramenter correspondes to TResult.
     * \tparam TResult The type of the return value of the method that this delegate encapsulates.
     * \tparam Args The parameters of the method that this delegate encapsulates.
     */
    template<typename TResult, typename ...Args>
    class DLLExport Func final
    {
    public:
        typedef std::function<TResult(Args...)> FuncType;

        Func(FuncType func);
        ~Func();

#pragma region Public Instance Methods

        TResult Invoke(Args&&... args);

#pragma endregion 

    private:
        FuncType func;
    };

    template <typename TResult, typename ... Args>
    Func<TResult, Args...>::Func(FuncType func)
    {
        this->func = func;
    }

    template <typename TResult, typename ... Args>
    Func<TResult, Args...>::~Func()
    {
    }

#pragma region Public Instance Methods

    template <typename TResult, typename ... Args>
    TResult Func<TResult, Args...>::Invoke(Args&&... args)
    {
        if (&func != nullptr)
        {
            return func(args...);
        }
        return nullptr;
    }

#pragma endregion 
}
