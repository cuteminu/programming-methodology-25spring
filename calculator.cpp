#include "calculator.h"
#include <stdexcept>

int Calculator::add(int a, int b)
{
    // TODO
    int result = a + b;

    // Overflow Test
    if (a > 0 && b > 0 && result < 0)
    {
        throw std::overflow_error("Overflow");
    }

    if (a < 0 && b < 0 && result > 0)
    {
        throw std::overflow_error("Underflow");
    }

    return result;
}

int Calculator::sub(int a, int b)
{
    // TODO
    int result = a - b;

    if (a > 0 && b < 0 && result < 0)
        throw std::overflow_error("Overflow");

    if (a < 0 && b > 0 && result > 0)
        throw std::overflow_error("Underflow");
    return result;
}

int Calculator::mul(int a, int b)
{
    // TODO
    int result = a * b;

    if (a > 0 && result < 0)
        throw std::overflow_error("Overflow");

    if (a < 0 && result > 0)
        throw std::overflow_error("Underflow");

    return result;
}

int Calculator::div(int a, int b)
{
    // TODO
    int result = a / b;
    if (b == 0)
        throw std::invalid_argument("Can't be divided by ZERO.");

    if (a < 0 && result < 0)
        throw std::overflow_error("Overflow");

    return result;
}