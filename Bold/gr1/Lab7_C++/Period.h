#pragma once
#include "Date.h"
#include <iostream>

class Period{
  private:
    Date m_Begining;
    Date m_End;
  public:
    Period(Date start, Date stop);

    bool contains(Date data) const;
    bool overlapsWith(Period period) const;

    void print() const;
    void shiftDays(int shift);

    inline Date& begin() { return m_Begining; }
    inline Date& end() { return m_End; }
    inline Date begin() const{ return m_Begining; }
    inline Date end() const{ return m_End; }

};