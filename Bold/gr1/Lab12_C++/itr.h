#pragma once

class itr{
  public:
    itr(int* x, int length): _tab(x), _pos(0) ,_length_max(length) {  }
    itr(int* begin, int *end): _tab(begin), _pos(0), _length_max(static_cast<int>(end - begin)) {   }
    void operator++(){ _pos++; }
    auto operator*(){ return *(_tab + _pos); }
    operator bool(){ return _pos < _length_max; }
  private:
    int *_tab;
    int _pos;
    const int _length_max;
};

