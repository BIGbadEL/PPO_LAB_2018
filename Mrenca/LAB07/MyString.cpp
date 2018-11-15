#include "MyString.h"

MyString::MyString(const char * string){
    _string = new char[strlen(string) + 1];
    strcpy(_string, string);
}

MyString::~MyString(){
    std::cout << "- deleting  " <<_string << std::endl;
    delete[] _string;
}

void MyString::replace(const char * new_string){
    std::cout << "cos";
    delete[] _string;
    _string = new char[strlen(new_string) + 1];
    strcpy(_string, new_string);
}

void MyString::replace(const MyString& new_string){
    delete[] _string;
    _string = new char[strlen(new_string.str()) + 1];
    strcpy(_string, new_string.str());
}

void swap(MyString& left,  MyString& rigth){
    char *temp = new char[strlen(left.str()) + 1];
    strcpy(temp, left.str());
    left.replace(rigth);
    rigth.replace(temp);
    delete[] temp;
}