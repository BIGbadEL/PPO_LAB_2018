#pragma once
#include <cmath>

#include "Dzialanie.h"

class Pierwiastek : public Dzialanie {
    public:

        /**
         * @brief Construct a new Pierwiastek object
         * @param a number
         */

        Pierwiastek(int a): _a(a) { }

        /**
         * @fn wypisz
         * @brief prints components
         * 
         */

        void wypisz() const override;

        /**
         * @fn wylicz
         * @brief calculate result of a operation
         * 
         * @return double result
         */

        double wylicz() const;
    private:
        int _a;
};