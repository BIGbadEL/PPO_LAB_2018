#pragma once

#include <iostream>

#define MIN(a,b) ((a < b) ? (a) : (b))
#define MAX(a,b) ((a < b) ? (b) : (a))

class Date{
  private:
    int m_Year;
    int m_Month;
    int m_Day;
  public:
    Date(): m_Year(0), m_Month(0), m_Day(0){ }
    Date(int year, int month, int day):
        m_Year(year), m_Month(month), m_Day(day){ }
    ~Date(){ }

    void shiftDays(int shift){
        m_Day += shift;

        if(m_Day > 30){
            m_Month += m_Day / 30;
            m_Day %= 30;
            if(m_Month > 12){
                m_Year += m_Month / 12;
                m_Month %= 12;
            }
        }

        if(m_Day < 1){
            m_Month -= (-m_Day) / 30 + 1;
            m_Day = 30 -( -m_Day)%31;
            if(m_Month < 1){
                m_Year -= (-m_Month) / 12 + 1;
                m_Month = 12 - (-m_Month)%12;
            }
        }
    }

    friend bool operator<(const Date& left, const Date& right){
        if(left.m_Year * 10000 + left.m_Month * 100 + left.m_Day < right.m_Year * 10000 + right.m_Month * 100 + right.m_Day)
            return true;
        return false;
    }

    friend bool operator>(const Date left, const Date right){
        if(left.m_Year * 10000 + left.m_Month * 100 + left.m_Day > right.m_Year * 10000 + right.m_Month * 100 + right.m_Day)
            return true;
        return false;
    }

    friend std::ostream& operator<<(std::ostream& stream, Date date){
        stream << date.m_Year <<  "." << date.m_Month << "." << date.m_Day;
        return stream;
    }

    friend class Period;
};