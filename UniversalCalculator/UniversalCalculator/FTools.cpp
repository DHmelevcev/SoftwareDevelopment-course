#include "FTools.h"
#include "TException.h"

uint8_t char_to_uint8(const uint8_t c)
{
    if ('0' <= c && c <= '9')
        return c - '0';
    if ('A' <= c && c <= 'Z')
        return c - 'A' + 10;
    if ('a' <= c && c <= 'z')
        return c - 'a' + 10;
    throw TException("Trying convert char: " + std::to_string(c) + " to int");
}

uint8_t uint8_to_char(const uint8_t c)
{
    if (c <= 9)
        return c + '0';
    if (10 <= c && c <= 35)
        return c + 'A' - 10;
    throw TException("Trying convert int: " + std::to_string(c) + " to char");
}

double strtod_base(const std::string& value, const uint8_t base)
{
    double _value = 0;

    if (value.length() == 0)
        return _value;

    size_t dot_pos = value.find('.');
    if (dot_pos == std::string::npos)
        dot_pos = value.length();

    int32_t a;
    uint8_t num;

    for (size_t i = value.length(); i > dot_pos + 1; --i) {
        a = static_cast<int32_t>(dot_pos - (i - 1));
        num = char_to_uint8(value[i - 1]);
        if (num >= base) {
            throw TException(
                "Number: " +
                std::to_string(value[i - 1]) +
                " bigger than base: " +
                std::to_string(base)
            );
        }
        _value += pow(base, a) * num;
    }

    for (size_t i = dot_pos; i > 1; --i) {
        a = static_cast<int32_t>(dot_pos - i);
        num = char_to_uint8(value[i - 1]);
        if (num >= base) {
            throw TException(
                "Number: " +
                std::to_string(value[i - 1]) +
                " bigger than base: " +
                std::to_string(base)
            );
        }
        _value += pow(base, a) * num;
    }

    if (value[0] == '-') {
        _value *= -1.;
        return _value;
    }

    a = static_cast<int32_t>(dot_pos - 1);
    num = char_to_uint8(value[0]);
    if (num >= base) {
        throw TException(
            "Number: " +
            std::to_string(value[0]) +
            " bigger than base: " +
            std::to_string(base)
        );
    }
    _value += pow(base, a) * num;

    return _value;
}

std::string dtostr_base(const double value, const uint8_t base, const uint32_t acc)
{
    uint64_t int_number_10 = static_cast<uint64_t>(std::abs(value));
    double float_number_10 = std::abs(value) - int_number_10;
    std::string int_result;
    std::string float_result;

    if (!int_number_10)
        int_result = '0';
    while (int_number_10) {
        int_result.insert(int_result.begin(), uint8_to_char(static_cast<uint8_t>(int_number_10 % base)));
        int_number_10 /= base;
    }

    for (uint32_t after_dot = 0; after_dot < acc && float_number_10; ++after_dot) {
        float_number_10 *= base;
        float_result.push_back(uint8_to_char(static_cast<uint8_t>(float_number_10)));
        float_number_10 -= static_cast<uint8_t>(float_number_10);
    }
    float_result.erase(float_result.find_last_not_of('0') + 1);

    return (value < 0. ? "-" : "") + int_result + (float_result.size() ? '.' + float_result : "");
}
