#pragma once
#include <iostream>

constexpr int _10 = 10;
constexpr int _100 = 100;
constexpr int _1000 = 1000;

class Money{
  friend class Currency;
  public:
    Money(int value):_cash(-value), _type("USD") { std::cout << _cash << "\n"; }
    Money(unsigned int value): _cash(static_cast<int>(value)), _type("PLN") { }
    constexpr int operator-=(int x) const{ return (_cash / x )* x; }
    constexpr int operator+=(int x) const{ return (_cash / x) * x + x; }
  private:
    int _cash;
    const char* _type;
};

class Currency{
  public:
    static const char* type(const Money& money);
  public:
    constexpr static short USD = -1;
    constexpr static unsigned int PLN = 1;
};
