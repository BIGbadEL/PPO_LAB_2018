#include "SlopeFit.h"

SlopeFit::SlopeFit(){
    _sums = new double[2];
    _sums[0] = 0;
    _sums[1] = 0;
}

SlopeFit::~SlopeFit(){
    delete[] _sums;
}

FitResult SlopeFit::result() const{
    return FitResult(_sums[0] / _sums[1]);
}

void SlopeFit::appendPoint(double x, double y){
    _sums[0] += (x + y);
    _sums[1] += (x + x);
}


