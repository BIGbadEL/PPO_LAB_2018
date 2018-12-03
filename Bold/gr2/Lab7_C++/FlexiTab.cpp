#include "FlexiTab.h"
#include "prec/pch.h"


FlexiTab::FlexiTab(const FlexiTab& tab): 
     _first(tab._first),
     _last(tab._last),
     _data(new double[abs(_first - _last)]) 
    {
        memcpy(_data, tab._data, static_cast<long unsigned int>(abs(_first - _last)) * sizeof(double));
    }

FlexiTab::FlexiTab(const FlexiTab& tab, int start, int end): 
     _first(start),
     _last(end),
     _data(new double[abs(start - end)]) 
    {
        memcpy(_data, tab._data + start + abs(tab._first) , static_cast<long unsigned int>(abs(start - end)) * sizeof(double));
    }

void FlexiTab::setAll(double value){
    std::fill(_data, _data + abs(_first - _last), value);
}

double& FlexiTab::at(int index) const{
    return _data[index + abs(_first)];
}

void FlexiTab::print(const FlexiTab& toPrint){
    for(int i = toPrint._first; i < toPrint._last; i++){
        std::cout << i << ":" << toPrint.at(i) << " ";
    }
}