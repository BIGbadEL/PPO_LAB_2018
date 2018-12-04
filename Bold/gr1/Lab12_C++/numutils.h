#pragma once
#include <climits>

namespace numutils{

    class function{
      public:
        function() = default;
        virtual void operator()(int number) = 0;
        virtual ~function() = default;
    };

    class sum : public function{
      public:
        constexpr sum() = default;
        virtual void operator()(int number) override{ _total += number; }
        constexpr int result() const{ return _total; }
      private:
        int _total = 0;
    };

    class average : public function{
      public:
        average() = default;
        virtual void operator()(int number) override{ _result = _result * _count; _count++; _result = (_result + number) / _count; }
        constexpr double result() const{ return _result; }
      private:
        double _result = 0;
        int _count = 0;
    };

    class minmax : public function{
      public:
        minmax(): _max(INT32_MIN), _min(INT_MAX) {    }
        virtual void operator()(int number) override{ if(_max < number) _max = number;
                                                      if(_min > number) _min = number; }
        constexpr int max() const{ return _max; }
        constexpr int min() const{ return _min; }
      private:
        int _max;
        int _min;
    };
}