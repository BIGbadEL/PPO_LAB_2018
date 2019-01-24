#pragma once
#include <cstring>

#include "Dzialanie.h"


class Suma : public Dzialanie {
    public:

     /**
      * @brief Construct a new Suma object
      * 
      * @param components to sum
      * @param ilosc number of components
      */

     Suma(int * liczby, unsigned int ilosc): _liczby(new int[ilosc]), _count(ilosc){
        std::memcpy(_liczby, liczby, sizeof(int) * _count);
     }

     /**
      *  @fn wypisz
      *  @brief prints components
      * 
      */

     void wypisz() const override;

      /**
       *  @fn wylicz
       *  @brief calculate result of a operation
       * 
       *  @return double result
       */

     double wylicz() const override;

     /**
      * @brief Destroy the Suma object
      * 
      */

     ~Suma();

    private:
     int *_liczby;
     unsigned int _count;
};