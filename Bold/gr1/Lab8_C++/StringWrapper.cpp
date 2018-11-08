#include "StringWrapper.h"


StringWrapper::StringWrapper(const char* string){
    int length = 0;
    while(string[length] != '\0') length++;
    length++;
    
    m_Length = length;
    m_Elements = new char[length];

    strcpy(m_Elements, string);
}

StringWrapper::StringWrapper(const StringWrapper& string){
    m_Length = string.m_Length;
    m_Elements = new char[m_Length];
    strcpy(m_Elements, string.m_Elements);
}

StringWrapper::~StringWrapper(){
    delete[] m_Elements;
    m_Elements = nullptr;
    m_Length = 0;
}

bool StringWrapper::eq(const char* left, StringWrapper rigth){
    // int iterator = 0;
    // while(iterator < rigth.m_Length){
    //     if(left[iterator] != rigth.m_Elements[iterator]) return false;
    //     iterator++;
    // }
    // return true;

    return !(bool)strcmp(left, rigth.m_Elements);
}

bool StringWrapper::eqIcase(const char* left, StringWrapper rigth){
    return !(bool) strcasecmp(left, rigth.m_Elements);
}

StringWrapper& StringWrapper::append(const char* string){
    int length = 0;
    while(string[length] != '\0') length++;
    length++;
    
    char* temp = new char[length + m_Length + 1];
    strcpy(temp, m_Elements);
    strcat(temp, string);
    delete[] m_Elements;
    m_Elements = temp;
    m_Length += length;
    
    return *this;
}

StringWrapper& StringWrapper::append(const StringWrapper& string){
    char *temp = new char[string.m_Length + m_Length];
    strcpy(temp, m_Elements);
    strcat(temp, string.m_Elements);
    m_Length += string.m_Length;
    delete[] m_Elements;
    m_Elements = temp;

    return *this;
}

void print(StringWrapper toPrint){
    std::cout << toPrint.m_Elements << std::endl;
}
