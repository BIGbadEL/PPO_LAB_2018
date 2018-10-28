#include "bitop.h"

void iPrintBit(const unsigned* bits, const int step, const char separator){
    for(int i = BITS_SIZE - 1; i >= 0; i--){
        std::cout << TEST_BIT(bits, i);
        if(i%step == 0 && i != 0) std::cout << separator;
    }
}

void iSetBit(unsigned* bits, const int pos, bool value){
    if(value) SET_BIT_1(bits, pos);
    else SET_BIT_0(bits, pos);
}

void iFlipBit(unsigned* bits, const int pos){
    if(TEST_BIT(bits, pos)) SET_BIT_0(bits, pos);
    else SET_BIT_1(bits, pos);
}

void iAppendBit(unsigned* bits, bool value){
    *bits = (*bits) << 1;
    if(value) SET_BIT_1(bits, 0);
}

int iPullBit(unsigned* bits){
    int result = (*bits)%2;
    *bits = (*bits) >> 1;
    return result;
}

int iGetBit(const unsigned* bits, const int pos){
    return TEST_BIT(bits,pos);
}