#pragma once
#include <memory>

class FlexiTab{
    public:
      FlexiTab(int first, int last): _first(first), _last(last), _data( new double[abs(first - last)]) {  std::uninitialized_fill(_data, _data + abs(_first - _last), 0);  }
      FlexiTab(const FlexiTab& tab);
      FlexiTab(const FlexiTab& tab, int start, int end);
      ~FlexiTab(){  delete[] _data; }
      void setAll(double value);
      double& at(int index) const;
      bool inRange(int index) const{ return index >= _first && index < _last; }

      static void print(const FlexiTab& toPrint);
    private:
      const int _first;
      const int _last;
      double* _data;
};