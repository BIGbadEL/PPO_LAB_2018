#pragma once

#include <string.h>
#include <iostream>
class Person{
    private:
        char* m_Name;
        char* m_Family;
    public:
        Person();
        Person(char* name, char* family);
        ~Person();
        inline const char* name() const{ return m_Name; }
        inline const char* family() const{ return m_Family; }
};