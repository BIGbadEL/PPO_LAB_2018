#include "value.h"

namespace value{
    std::ostream& operator<<(std::ostream& stream, const integer& toPrint){
        stream << toPrint._value;
        return stream;
    }
}