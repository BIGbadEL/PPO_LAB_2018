#include "../include/MapDistance.h"

MapPoint& inTheMiddle(MapPoint& left, MapPoint rigth, const char *name){
    MapPoint result = construct(name, (left.m_Latitude + rigth.m_Latitude) / 2, (left.m_Longitude + rigth.m_Longitude) / 2);
    clear(left);
    left = result;
    return left;
}
void movePoint(MapPoint& City, double latitudeShift, double longitudeShift){
    City.m_Longitude += longitudeShift;
    City.m_Latitude += latitudeShift;
}