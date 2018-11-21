#include "FitResult.h"

FitResult::FitResult(double a){
    _param_count = 1;
    _param_names = new char[2];
    strcpy(_param_names, "a");
    _param_value = new double[1];
    _param_value[0] = a;
    _expresion = std::string("y = a x");
}

FitResult::FitResult(double a, double b){
    _param_count = 2;
    _param_names = new char[3];
    strcpy(_param_names, "ab");
    _param_value = new double[2];
    _param_value[0] = a;
    _param_value[1] = b;

    _expresion = std::string("y = a x + b");
}

FitResult::~FitResult(){
    delete[] _param_names;
    delete[] _param_value;
}