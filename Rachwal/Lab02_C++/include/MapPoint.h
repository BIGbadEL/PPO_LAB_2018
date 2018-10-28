#pragma once

#include <cstdlib>
#include <string.h>
#include <iostream>

struct MapPoint{
    char* m_Name;
    double m_Longitude;
    double m_Latitude;
};

MapPoint construct(const char *name, double latitude, double longitude);


void print(MapPoint City);
void clear(MapPoint& City);