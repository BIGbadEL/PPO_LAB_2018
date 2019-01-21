#pragma once

#include <iostream>

class MyComplex{
      friend std::ostream& operator<<(std::ostream& stream, const MyComplex& toPrint);
    public:

      MyComplex(int x = 0, int y = 0): _re(x), _im(y) {
          std::cout << *this << " utworzony na stercie? "; 
          if(_new){
              _new = false;
              _dynamic = true;
          }else{
              _dynamic = false;
          }

          std::cout << _dynamic << '\n';
          
      }

      static size_t no_alocated() noexcept{ return _alocated; }
      
      void* operator new(size_t num);
      void operator delete(void* toDelete);
    private:
      int _re;
      int _im;
      static bool _new;
      bool _dynamic;
      static size_t _alocated;
};


inline std::ostream& operator<<(std::ostream& stream, const MyComplex& toPrint){
    stream << toPrint._re << "+" << toPrint._im << "i";
    return stream;
}

inline void* MyComplex::operator new(size_t num){
    std::cout << "Wywolany operator new \n";
    _alocated += num / sizeof(MyComplex);

    _new = true;
    return ::operator new(sizeof(MyComplex));
}

inline void MyComplex::operator delete(void* toDelete){
    auto p = reinterpret_cast<MyComplex*>(toDelete);
    std::cout << *p;
    if(p->_dynamic){
        std::cout << " usuwanie dynamiczne \n";
        _alocated--;
        ::delete p;
    }else{
        std::cout << " nie był zaalokowany na stercie \n";
    }
}
