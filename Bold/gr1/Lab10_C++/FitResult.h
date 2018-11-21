#pragma once
#include <string>
#include <cstring>


class FitResult{
  public: 
    FitResult(double a);
    FitResult(double a, double b);
    ~FitResult();
    inline constexpr unsigned int nParams() const { return _param_count; }
    inline constexpr char parameterName(unsigned int i) const{ return _param_names[i]; }
    inline constexpr double parameterValue(unsigned int i) const{ return _param_value[i]; }
    inline std::string expression() const{ return _expresion; }

  private:
    unsigned int _param_count;
    char* _param_names;
    double* _param_value;
    std::string _expresion;
    
};

class Fit{
  public:
    virtual void appendPoint(double x, double y) = 0;
    virtual FitResult result() const = 0;
    virtual ~Fit() { }
  public:
    double* _sums;
};