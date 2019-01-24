#pragma once
#include <iostream>

class Dzialanie{

    /**
     * @fn wypisz
     * @brief funkcja wypisująca
     * 
     * @param obj dzialanie do wypisania
     */

    friend void wypisz(const Dzialanie& obj);
    public:

      /**
       * @fn wypisz
       * @brief print componets
       * 
       */
    
      virtual void wypisz() const = 0;

     /**
      * @brief calculate result of a operation
      *
      * @return double result
      */

      virtual double wylicz() const = 0;

      /**
       * @brief Destroy the Dzialanie object
       * 
       */

      virtual ~Dzialanie() = default;
};

inline void wypisz(const Dzialanie& obj){
    obj.wypisz();
}