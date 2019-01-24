#include "Dzielenie.h"

double Dzielenie::wylicz() const {
    return _a / _b;
}

void Dzielenie::wypisz() const {
    std::cout << "Dzielenie liczb: " << _a << ' ' <<  _b << '\n';
}