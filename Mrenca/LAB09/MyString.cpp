#include "MyString.h"


MyString::MyString(const char* string){
    std::cout << "++ creating " << string << "\n";
    _string = new char[strlen(string) + 1];
    strcpy(_string, string);
}

MyString::MyString(const MyString& string){
    std::cout << "++ copping " << string.str() << "\n";
    _string = new char[strlen(string._string) + 1];
    strcpy(_string, string._string);
}

MyString::~MyString(){
    std::cout << "-- deleting " << _string << "\n";
    delete[] _string;
}

MyString& MyString::append(MyString string){
    char* temp = _string;
    _string = new char[strlen(temp) + strlen(string._string) + 1];
    memset(_string, '\0', strlen(temp) + strlen(string._string) + 1);
    strcpy(_string, temp);
    strcat(_string, string._string);
    delete[] temp;
    return *this;
}


MyString& MyString::insert(MyString string, unsigned int pos){
    char* temp = _string;
    _string = new char[strlen(temp) + strlen(string._string) + 1];
    memset(_string, '\0', strlen(temp) + strlen(string._string) + 1);
    strncpy(_string, temp, pos);
    strcat(_string, string._string);
    strcat(_string, temp + pos);
    delete[] temp;
    return *this;
}