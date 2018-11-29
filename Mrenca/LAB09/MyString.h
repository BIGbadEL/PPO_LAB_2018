#pragma once

#include <cstring>
#include <iostream>

/**
 * @class MyString 
 * @breif prost kalsa służąca do przechowywania łańcucha znaków
*/

class MyString{
    public:
      
      /**
       * @fn MyStirng
       * @brief konstruktor tworzacy kalse z łańcucha znaków
       * @param [const char*] łańcuch znaków
      */

      MyString(const char* string);

      /**
       * @fn MyString
       * @breif konstrukotr kopiujący
       * @param [MyString] string do skopiowania
      */

      MyString(const MyString& string);

      /**
       * @fn ~MyString
       * @brief destruktor klasy czyszczący pamięc
      */

      ~MyString();

      /**
       * @fn str
       * @brief getter pozwalający na dostęp do napisu przechwywanego przez kalse
       * @return [char*] wskaźnik na łańcuch znaków
      */

      char* str() const{ return _string; }

      /**
       * @fn append
       * @brief dodaje na koniec string nowy napis
       * @param [MyString] zawierający łańcuch który chcemy dodać na koniec
       * @return [MyString&] referencja do obiektu nad którm aktualnie pracujemy
       *    pozwala to na wywiałanie funkcji w sposób:
       *    string.append("cos").append("jeszcz cos")
      */
      
      MyString& append(MyString string);

      /**
       * @fn insert
       * @brief wstawia nowy łańcuch w podanej pozycji w objekcie na którym go wywołujemy
       * @param [MyString] zawierający łańcuch który chcemy dodać na koniec
       * @return [MyString&] referencja do obiektu nad którm aktualnie pracujemy
       *    pozwala to na wywiałanie funkcji w sposób:
       *    string.insert("cos").insert("jeszcz cos")
      */

      MyString& insert(MyString string, unsigned int pos);
    private:
      char* _string; /**< _string pole w klasie w którym przehcowujemy łańchuch znaków*/
};