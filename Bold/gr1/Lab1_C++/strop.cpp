#include "strop.h"


void chunk(const char* text, delimited* dest, char separator){
    
    dest->m_Iterator = 0;
    const std::string temp(text);
    std::stringstream ss(temp);
    std::string item;
    while(std::getline(ss, item, separator)){
        dest->m_Strings.push_back(item);
    }

}

bool next(delimited* string){
    string->m_Iterator++;
    if(string->m_Iterator > string->m_Strings.size()){
        return false;
    }
    return true;
}

void part(delimited* string, char buffer[256]){
    strcpy(buffer, string->m_Strings.at(string->m_Iterator - 1).c_str());
}