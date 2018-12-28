#pragma once
#include "Fraction.h"

class FractionArray{
    public:
      FractionArray(int i): m_data(new Fraction[i]) {   }

      ~FractionArray(){ delete[] m_data; }

      const Fraction& operator[](int i) const{ return m_data[i]; }

      Fraction& operator[](int i) {return m_data[i]; }
      
    private:
      Fraction* m_data;
};
