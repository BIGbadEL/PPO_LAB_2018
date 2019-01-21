#pragma once
#include "Vehicle.h"

class Car : public Vehicle{
    public:
      Car(const char* name, const char* plate);
      Car(const Car&);
      ~Car();
      void operator=(const Car& car);
      const char* plate() const;
    private:
        void ctor(const char* Char);
    private:
     char * _plate;
};