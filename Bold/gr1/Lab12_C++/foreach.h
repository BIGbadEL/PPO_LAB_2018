#pragma once
#include "numutils.h"
#include "itr.h"

void foreach( itr iterator, numutils::function& fun ){
    for(;iterator; ++iterator){
        fun(*iterator);
    }
}