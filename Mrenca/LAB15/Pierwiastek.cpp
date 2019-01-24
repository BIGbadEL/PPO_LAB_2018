#include "Pierwiastek.h"

void Pierwiastek::wypisz() const {
    std::cout << "Pierwiastek liczby: " << _a << '\n';
}

double Pierwiastek::wylicz() const {
    return sqrt(_a);
}