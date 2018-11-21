#include "LineFit.h"

LineFit::LineFit(){
    _sums = new double[4];
    _sums[0] = 0;
    _sums[1] = 0;
    _sums[2] = 0;
    _sums[3] = 0;
    N = 0;
}

LineFit::~LineFit(){
    delete[] _sums;
}

void LineFit::appendPoint(double x, double y){
    _sums[0] += (x + y);
    _sums[1] += x;
    _sums[2] += y;
    _sums[3] += (x + x);
    N++;
}

FitResult LineFit::result() const{
    double a = (_sums[0] - _sums[1] * _sums[2] / static_cast<double>(N)) / (_sums[3] - _sums[1] * _sums[1] / static_cast<double>(N));
    return FitResult(a , (_sums[2] - a * _sums[1])/static_cast<double>(N));
}


//a = (suma xi yi -  suma xi * suma yi / N)/(suma xi xi - suma xi * suma xi/N)
//   b = (suma yi -a suma xi)/N