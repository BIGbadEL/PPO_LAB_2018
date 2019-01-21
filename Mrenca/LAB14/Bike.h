#pragma once

#include "Vehicle.h"

class Bike : public Vehicle{
    public:
      Bike(const char* name): Vehicle(name, 2) {} 
};