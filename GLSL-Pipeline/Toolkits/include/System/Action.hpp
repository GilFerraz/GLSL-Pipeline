#pragma once

#include <functional>
#include "DLL.hpp"

namespace System
{
    /**
     * \brief Encapsulates a method that has specified parameters and does not return a value.
     * \tparam Args The type of the parameters of the method that this delegate encapsulates.
     */
    template<typename ...Args>
    class DLLExport Action final
    {
    public:
        typedef std::function<void(Args...)> ActionType;

#pragma region Public Constructors

        Action(ActionType action);

#pragma endregion 

#pragma region Public Destructor

        ~Action();

#pragma endregion 

#pragma region Public Instance Methods

        void Invoke(Args&&... args);

#pragma endregion 

    private:
        ActionType action;
    };

#pragma region Public Constructors

    template <typename ... Args>
    Action<Args...>::Action(ActionType action)
    {
        this->action = action;
    }

#pragma endregion 

#pragma region Public Destructor

    template <typename ... Args>
    Action<Args...>::~Action() {}

#pragma endregion 

#pragma region Public Instance Methods

    template <typename ... Args>
    void Action<Args...>::Invoke(Args&&... args)
    {
        if (&action != nullptr)
        {
            action(args...);
        }
    }

#pragma endregion 
}
