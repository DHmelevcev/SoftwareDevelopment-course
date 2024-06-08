#pragma once
#include <string>

uint8_t char_to_uint8(const uint8_t c);

uint8_t uint8_to_char(const uint8_t c);

double strtod_base(const std::string& value, const uint8_t base);

std::string dtostr_base(const double value, const uint8_t base, const uint32_t acc = 15);

template<typename type_t>
constexpr type_t GCD(type_t value1, type_t value2) noexcept
{
    while (value2)
    {
        type_t temp = value2;
        value2 = value1 % value2;
        value1 = temp;
    }

    return value1;
}
