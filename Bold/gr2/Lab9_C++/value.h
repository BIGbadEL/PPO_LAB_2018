#pragma once
#include <string>
#include <iostream>

namespace value{

    static int $;

    class integer{
        friend std::ostream& operator<<(std::ostream& , const integer& toPrint);
      public:
        constexpr integer(int val): _value(val) {}
        constexpr void operator-(int right){ _value-=right; $ = _value; }
        constexpr void operator*(const integer& right){ _value *= right._value; $ = _value; }
        constexpr void operator/(int right){ _value /= right; $ = _value; }
      private:
        int _value;
    };
}