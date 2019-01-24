#include "Suma.h"

Suma::~Suma(){
    delete[] _liczby;
}

void Suma::wypisz() const{
    std::cout << "Suma liczb:";

    for(unsigned int  i = 0; i < _count; ++i) 
        std::cout << ' ' << _liczby[i];

    std::cout << '\n';
}

double Suma::wylicz() const{
    int result = 0;
    for(unsigned i = 0; i < _count; ++i)
        result += _liczby[i];
    return result;
}
