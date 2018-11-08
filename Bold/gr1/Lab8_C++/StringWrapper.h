#pragma once

#include <cstring>
#include <iostream>

class StringWrapper{
    private:
        char* m_Elements;
        int m_Length;
    public:
        StringWrapper(): m_Elements(nullptr) { }
        StringWrapper(const char* string);
        StringWrapper(const StringWrapper& string);

        ~StringWrapper();

        StringWrapper& append(const char* string);
        StringWrapper& append(const StringWrapper& string);

        static bool eq(const char* left, StringWrapper right);
        static bool eqIcase(const char* left, StringWrapper rigth);

        friend void print(StringWrapper toPrint);
};