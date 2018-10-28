#include "bitarr.h"

void set_size(Bitarr* bits,unsigned nbits){
    bits->m_Size = nbits;
    if(nbits % BITS_SIZE == 0) bits->m_Bits = new uchar[nbits / BITS_SIZE];
    else bits->m_Bits = new uchar[(nbits / BITS_SIZE + 1)];
}

void fill_pattern(Bitarr* bits, const char* patern){
    int pat_length = 0;
    while(patern[pat_length] != '\0') pat_length++;

    int position = (int)bits->m_Size - 1;
    while(position >= 0){
        for(int j = pat_length - 1; j >= 0; j--){
            if(patern[j] == '1') SET_BIT_1(bits->m_Bits, position);
            else SET_BIT_0(bits->m_Bits, position);
            position--;

            if(position == -1) break;
        }
    }
    
}

void print_bitarray(Bitarr* bits){
    int size = (int)bits->m_Size - 1;
    int temp = (int)bits->m_Size;

    for(; size >= 0; size--){
        std::cout << TEST_BIT(bits->m_Bits, temp - size - 1);
        if((size % BITS_SIZE) == 0 && size != 0) std::cout << "_";
    }
    std::cout << "\n";
}

int n_set(Bitarr* bits){
    int result = 0;
    for(unsigned i = 0; i < bits->m_Size; i++){
        if(TEST_BIT(bits->m_Bits, i)) result++;
    }
    return result;
}

void xor_and_set(Bitarr* dest, Bitarr* left, Bitarr* right){
    for(unsigned i = 0; i < dest->m_Size; i++){
        if(TEST_BIT(left->m_Bits, i) ^ TEST_BIT(right->m_Bits, i)) SET_BIT_1(dest->m_Bits, i);
        else SET_BIT_0(dest->m_Bits,i);
    }
}

void clear(Bitarr* bits){
    delete[] bits->m_Bits;
    bits->m_Bits = nullptr;
    bits->m_Size = 0;
}