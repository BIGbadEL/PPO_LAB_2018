#include "Car.h"

Car::Car(const char* name, const char* plate): Vehicle(name, 4) {
    ctor(plate);
}

Car::Car(const Car& car): Vehicle(car._name, 4){
    ctor(car._plate);
}

void Car::operator=(const Car& car){
    delete[] _plate;
    ctor(car._plate);

    this->Vehicle::operator=(car);

}

void Car::ctor(const char* Char){
    _plate = new char[strlen(Char) + 1];
    strcpy(_plate, Char);
}

Car::~Car(){
    delete[] _plate;
}

const char* Car::plate() const{
    return _plate;
}