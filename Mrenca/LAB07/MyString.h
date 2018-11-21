#pragma once
#include <cstring>
#include <iostream>

/**
 * @class MyString 
 * @brief Służy do przetrzymywania łańcucha znaków oraz podstawocyh operacji na nim
*/

class MyString{
  public:

    /**
     * @fn MyString
     * @breif konstruje obiekt klasy MyString
     * @param string -> stały wskaźnik na łańuch znaków
    */

    MyString(const char * string);

    /**
     * @fn ~MyString 
     * @brieg Destruktor klasy MyString uswa obiekty i czysci pamięć
    */

    ~MyString();

    /**
     * @fn replace
     * @brief zmienia string na ten podany w argumencie
     * @param new_string -> nowy string
    */

    void replace(const char * new_string);

    /**
     * @fn replace
     * @brief zmienia string na ten podany w argumencie
     * @param new_string -> obiekt klasy MyString
    */

    void replace(const MyString& new_string);

    /**
     * @fn str
     * @brief zwraca łańcuch znaków
     * @return const wskaźnik na łańcuch znaków
    */

    inline constexpr char* str() const { return _string; }
  private:
     char* _string; /**< wskaźnik na łańcuch znaków */
};

/**
 * @fn swap
 * @brief zmiania łańcuchy znaków w dwóch obiektach MyString
 * @param left -> obiekt klasy MyString do zamiany
 * @param right -> obiekt klasy MyString do zaminy
*/

void swap(MyString& left,  MyString& rigth);

