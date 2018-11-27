#include "MapPoint.h"
#include <iostream>

double abs(double arg){
    if(arg > 0) return arg;
    return -arg;
}

void MapPoint::print() const{
    char _NS = (_lat > 0) ? 'N' : 'S';
    char _EW = (_log > 0) ? 'E' : 'W';
    std::cout << "Point (" << abs(_lat) << _NS << "," << abs(_log) << _EW << ")\n";
}

void MapPoint::move(double x, double y){
    _lat += x;
    _log += y;
}

MapPoint MapPoint::inTheMiddle(const MapPoint& x,  const MapPoint& y){
    return MapPoint((x._lat + y._lat) / 2 , (x._log + y._log) / 2);
}