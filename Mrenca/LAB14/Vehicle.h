#pragma once
#include <cstring>

class Vehicle{
    public:
        Vehicle(const char * name, int wheels);
        ~Vehicle();
        const char* name() const;
        int numberOfWheels() const;
        void operator=(const Vehicle& veh);
    private:
        void ctor(const char* Char, int wheels);
    protected:
        char* _name;
        int _wheels;
};