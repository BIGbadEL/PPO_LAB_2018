#include "Person.h"

Person::Person(){
    m_Name = nullptr;
    m_Family = nullptr;
}

Person::Person(char* name, char* family){

    int length = 0;
    while(name[length] != '\0') length++;
    m_Name = new char[length + 1];
    strcpy(m_Name, name);

    length = 0;
    while(family[length]) length++;
    m_Family = new char[length + 1];
    strcpy(m_Family, family);
}


Person::~Person(){
    // std::cout << "Usuwanie osoby: " << m_Name << " " << m_Family << std::endl;
    if(m_Name != nullptr) 
        delete[] m_Name;
    m_Name = nullptr; 
    if(m_Family != nullptr) 
        delete[] m_Family;
    m_Family = nullptr;
}