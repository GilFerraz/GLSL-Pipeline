#pragma once

#include "DLL.hpp"
#include "Double.hpp"

namespace System
{

#pragma region Forward Declarations

    struct Int16;
    struct Int32;
    struct Int64;
    struct Single;

#pragma endregion 

    /**
     * \brief Provides constants and static methods for trigonometric, logarithmic, and other common mathematical functions.
     */
    class DLLExport Math final
    {
    public:

#pragma region Public Constants

        static const Double E;
        static const Double PI;

#pragma endregion 

#pragma region Public Static Methods

        //static decimal Abs(decimal value);
        static Double Abs(Double value);
        static Int16 Abs(Int16 value);
        static Int32 Abs(Int32 value);
        static Int64 Abs(Int64 value);
        //static sbyte Abs(sbyte value);
        static Single Abs(Single value);
        static Double Acos(Double d);
        static Double Asin(Double d);
        static Double Atan(Double d);
        static Double Atan2(Double y, Double x);
        //static long BigMul(int a, int b);
        //static decimal Ceiling(decimal d);
        //static double Ceiling(double a);
        static Double Cos(Double d);
        static Double Cosh(Double value);
        //static int DivRem(int a, int b, out int result);
        //static long DivRem(long a, long b, out long result);
        //static double Exp(double d);
        //static decimal Floor(decimal d);
        //static double Floor(double d);
        //static double IEEERemainder(double x, double y);
        static Double Log(Double d);
        //static double Log(double a, double newBase);
        static Double Log10(Double d);
        //static byte Max(byte val1, byte val2);
        //static decimal Max(decimal val1, decimal val2);
        //static double Max(double val1, double val2);
        //static short Max(short val1, short val2);
        //static int Max(int val1, int val2);
        //static long Max(long val1, long val2);
        //static sbyte Max(sbyte val1, sbyte val2);
        //static float Max(float val1, float val2);
        //static ushort Max(ushort val1, ushort val2);
        //static uint Max(uint val1, uint val2);
        //static ulong Max(ulong val1, ulong val2);
        //static byte Min(byte val1, byte val2);
        //static decimal Min(decimal val1, decimal val2);
        //static double Min(double val1, double val2);
        //static short Min(short val1, short val2);
        //static int Min(int val1, int val2);
        //static long Min(long val1, long val2);
        //static sbyte Min(sbyte val1, sbyte val2);
        //static float Min(float val1, float val2);
        //static ushort Min(ushort val1, ushort val2);
        //static uint Min(uint val1, uint val2);
        //static ulong Min(ulong val1, ulong val2);
        static Double Pow(Double x, Double y);
        //static decimal Round(decimal d);
        //static decimal Round(decimal d, int decimals);
        //static decimal Round(decimal d, int decimals, MidpointRounding mode);
        //static decimal Round(decimal d, MidpointRounding mode);
        //static double Round(double a);
        //static double Round(double value, int digits);
        //static double Round(double value, int digits, MidpointRounding mode);
        //static double Round(double value, MidpointRounding mode);
        //static int Sign(decimal value);
        //static int Sign(double value);
        //static int Sign(short value);
        //static int Sign(int value);
        //static int Sign(long value);
        //static int Sign(sbyte value);
        //static int Sign(float value);
        static Double Sin(Double a);
        static Double Sinh(Double value);
        static Double Sqrt(Double d);
        //static double Tan(double a);
        //static double Tanh(double value);
        //static decimal Truncate(decimal d);
        //static double Truncate(double d);

#pragma endregion 

    private:
        Math();
        ~Math();
    };
}
