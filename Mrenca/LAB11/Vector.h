#pragma once
#include <iostream>
#include <cmath>

/**
 * @class Vector
 * @brief klaca implementująca dowolno wymiarowy wektor
*/

class Vector{
    public:

      /**
       * @fn operator *
       * @brief mnoży wektor przez skalar
       * @param [int] skalar 
       * @param [Vector] wektor do pomnożenia
      */

      friend Vector operator*(int x, const Vector& vec);

      /**
       * @fn Vector
       * @brief Tworzy wektor o zadanym wymiarze
       * @param [int] rozmiar
      */

      Vector(int size);

      /**
       * @fn Vector
       * @brief Tworzy wektor na podstawie innego wektora
       * @param [Vector] wektor na  podstawie którego ma być stworzony aktualny 
      */

      Vector(const Vector& other);

      /**
       * @fn ~Vector
       * @brief Destrkutor klasy wektor
      */

      ~Vector(){ delete[] _data; }

      /**
       * @fn create
       * @brief towrzy wketor o zadanym rozmiarze
       * @param [int] size
      */

      static Vector create(int size);

      /**
       * @fn set
       * @brief ustaiwa element o zadnam indeksie na zadaną wartośc
       * @param [int] index
       * @pram [int] wartosc
      */

      void set(int index, int value);

      /**
       * @fn Print
       * @brief wypisuje wketor na ekran
      */

      void Print() const;

      /**
       * @fn operator+
       * @brief realizuje opracje dodawnai wektorów
      */

      Vector operator+(const Vector& other) const;

      /**
       * @fn double()
       * @brief konwerturj wekotr do double - który jest długośćią wkeora
      */

      operator double() const;

      /**
       * @fn operator=
       * @brief operator przypisania 
       * @param [Vector]
      */

      Vector& operator=(const Vector& other);

    private:

      /**
       * @fn PreperMemory
       * @brief alokuje pamięć oraz ustawia licznik elementów wektora
       * @param [int] siez
      */

      void PreperMemory(int size);


    private:
      int* _data; /**< elementy wektora */
      int _size; /**< ilosc elementów */
};

