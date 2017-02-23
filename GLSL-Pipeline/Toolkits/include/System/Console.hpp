#pragma once

#include "DLL.hpp"
#include "ConsoleColor.hpp"
#include "Object.hpp"
#include "Int64.hpp"

namespace System
{
    class String;
    struct Int32;

    /**
     * \brief Represents the standard input, output, and error streams for console applications. 
     *        This class cannot be inherited.
     */
    class DLLExport Console final
    {
    public:

#pragma region Public Static Properties

        /**
         * \brief Gets the background color of the console.
         * \return The background color of the console.
         */
        static ConsoleColor GetBackgroundColor();


        /**
         * \brief Sets the background color of the console.
         * \param consoleColor A value that specifies the background color of the console; that is, the color that appears behind
         *                     each character. The default is black.
         * \return The background color of the console.
         */
        static ConsoleColor SetBackgroundColor(ConsoleColor consoleColor);

#pragma endregion 

#pragma region Public Static Methods

        /**
         * \brief Reads the next line of characters from the standard input stream.
         * \return The next line of characters from the input stream, or null if no more lines are available.
         */
        static String ReadLine();

        /**
         * \brief Writes the current line terminator to the standard output stream.
         */
        static void WriteLine();
        
        //static void WriteLine(bool value);
        //static void WriteLine(char value);
        //static void WriteLine(char* buffer);
        //static void WriteLine(char* buffer, int index, int count);
        //static void WriteLine(decimal value);
        //static void WriteLine(double value);

        /**
         * \brief Writes the text representation of the specified 32-bit signed integer value, followed by the current line
         *        terminator, to the standard output stream.
         * \param value The value to write.
         */
        static void WriteLine(Int32 value);

        /**
         * \brief 
         * \param value 
         */
        static void WriteLine(Int64 value);
        
        /**
         * \brief 
         * \param value 
         */
        static void WriteLine(Object value);

        //static void WriteLine(float value);

        /**
         * \brief Writes the specified string value, followed by the current line terminator, to the standard output stream.
         * \param value The value to write.
         */
        static void WriteLine(String value);
        
        //static void WriteLine(string format, object arg0);
        //static void WriteLine(string format, object arg0, object arg1);
        //static void WriteLine(string format, object arg0, object arg1, object arg2);
        //static void WriteLine(string format, params object[] arg);
        //static void WriteLine(uint value);
        //static void WriteLine(ulong value);

#pragma endregion 

    private:
        Console();
        ~Console();

        static ConsoleColor consoleColor;
    };
}
