#include "Vehicle.h"

Vehicle::Vehicle(const char* name, int wheels){
    ctor(name, wheels);
}

Vehicle::~Vehicle(){
    delete[] _name;
}

const char* Vehicle::name() const{
    return _name;
}

int Vehicle::numberOfWheels() const{
    return _wheels;
}

void Vehicle::operator=(const Vehicle& veh){
    delete[] _name;
    ctor(veh._name, veh._wheels);
}

void Vehicle::ctor(const char* name, int wheels){
    _name = new char[strlen(name) + 1];
    strcpy(_name, name);
    _wheels = wheels;
}