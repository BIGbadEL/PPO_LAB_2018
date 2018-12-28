#pragma once
#include <iostream>
#include "Maths.h"

class Fraction{

    friend Fraction operator*(int x, const Fraction& frac);
    friend std::ostream& operator<<(std::ostream& stream, const Fraction& toPrint);

    public:
      constexpr Fraction( int licznik = 0, int mianownik = 1): m_mianownik(mianownik), m_licznik(licznik) { }

      constexpr operator double() const noexcept { 
          return static_cast<double>(m_mianownik) / static_cast<double>(m_licznik); 
        }

      constexpr Fraction operator*(const Fraction& other) const noexcept{
          return Fraction(m_licznik * other.m_licznik, m_mianownik * other.m_mianownik);
      }

      constexpr const Fraction operator+(const Fraction& other) const noexcept{
          return Fraction(m_licznik * other.m_mianownik + other.m_licznik * m_mianownik, m_mianownik * other.m_mianownik);
      }

     const Fraction&  operator=( const Fraction& other){
          m_licznik = other.m_licznik;
          m_mianownik = other.m_mianownik;
          return *this;
      }

      void simplify() noexcept;

      

    private:
      int m_mianownik;
      int m_licznik;
};

std::ostream& operator<<(std::ostream& stream, const Fraction& toPrint){
    stream << toPrint.m_licznik << "/" << toPrint.m_mianownik;
    return stream;
}

Fraction operator*(int x, const Fraction& frac){
    return Fraction(x * frac.m_licznik, frac.m_mianownik);
}

void Fraction::simplify() noexcept{
    int div = Maths::gcd(m_mianownik, m_licznik);
    m_mianownik /= div;
    m_licznik /= div;
}

