#pragma once
#include <string.h>
#include <vector>
#include <string>
#include <sstream>

struct delimited{
    std::vector<std::string> m_Strings;
    unsigned int m_Iterator;
};

void chunk(const char* text, delimited* dest, char separator);

bool next(delimited* string);

void part(delimited* string, char buffer[256]);