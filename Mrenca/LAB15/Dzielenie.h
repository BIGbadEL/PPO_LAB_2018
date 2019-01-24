#pragma once

#include "Dzialanie.h"

class Dzielenie : public Dzialanie{
    public:

    /**
     * @brief Construct a new Dzielenie object
     * 
     * @param a number
     * @param b number
     */

     Dzielenie(int a, int b): _a(a), _b(b) {}

    /**
     * @fn wypisz
     * @brief print components
     * 
     */

     void wypisz() const override;

    /**
     * @fn wylicz
     * @brief calculate result of a operation
     * 
     * @return double result
     */

     double wylicz() const override;

    private:
     int _a;
     int _b;
};