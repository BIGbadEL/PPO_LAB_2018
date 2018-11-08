#include "Period.h"

Period::Period(Date start, Date stop){
    m_Begining = MIN(start,stop);
    m_End = MAX(start,stop);
}


void Period::print() const{
    std::cout << m_Begining << " - " << m_End;
}

void Period::shiftDays(int shift){
    m_Begining.shiftDays(shift);
    m_End.shiftDays(shift);
}

bool Period::contains(Date data) const{
    if(data > m_Begining && data < m_End) return true;
    return false;
}

bool Period::overlapsWith(Period period) const{
    if(contains(period.m_Begining)) return true;
    if(contains(period.m_End)) return true;
    return false;
}