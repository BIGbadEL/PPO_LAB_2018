#include "Vector.h"

Vector::Vector(int size){ 
    PreperMemory(size);
    for(int i = 0; i < _size; i++) 
    _data[i] = 0;  
}

Vector::Vector(const Vector& other): _data(new int[other._size]), _size(other._size){
    for(int i = 0; i < _size; i++) _data[i] = other._data[i];
}

void Vector::PreperMemory(int size){
    _size = size;
    _data = new int[_size];
}


Vector Vector::create(int size){
    return Vector(size);
}

void Vector::set(int index, int value){
    _data[index] = value;
}

void Vector::Print() const{
    for(int i = 0; i < _size; i++)
        std::cout << _data[i] << " ";
    std::cout << "\n";
}

Vector Vector::operator+(const Vector& other) const{
    Vector temp(*this);
    
    for(int i = 0; i < _size; i++)
        temp._data[i] += other._data[i];

    return temp;
}

Vector::operator double() const{
    double result = 0;
    for(int i = 0; i < _size; i++)
        result += (_data[i] * _data[i]);
    return sqrt(result);
}

Vector operator*(int x, const Vector& vec){
    Vector temp(vec);
    for(int i = 0; i < vec._size; i++)
        temp._data[i] *= x;
    
    return temp;
}

Vector& Vector::operator=(const Vector& other){
    if( this == &other) return *this;

    delete[] _data;
    PreperMemory(other._size);

    for(int i = 0; i < _size; i++)
        _data[i] = other._data[i];

    return *this;
}
