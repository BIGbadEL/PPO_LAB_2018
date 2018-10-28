#include "../include/MapPoint.h"

MapPoint construct(const char *name, double latitude, double longitude){
    int length  = 0;
    while(name[length] != '\0') length++;

    MapPoint City;
    City.m_Name = new char[length+1];
    strcpy(City.m_Name, name);

    City.m_Longitude = longitude;
    City.m_Latitude = latitude;

    return City;
}

void print(MapPoint City){
    std::cout << "Position of " << City.m_Name << ". Latitude: " << City.m_Latitude << ". Longitude: " << City.m_Longitude << std::endl;
}



void clear(MapPoint& City){
    if(City.m_Name != nullptr) 
        delete[] City.m_Name;
    City.m_Latitude = 0;
    City.m_Longitude = 0;
    City.m_Name = nullptr;
}

