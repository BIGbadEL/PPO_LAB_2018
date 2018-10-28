#include "bitarray.h"
#include <cstring>

void init(BitArray* tab, unsigned int width, unsigned int heigth){
    tab->m_Width = width;
    tab->m_Heigth = heigth;
    

    if(heigth % BITS_SIZE  != 0)
        heigth = heigth / BITS_SIZE  + 1;
    else
        heigth /= BITS_SIZE;

    tab->m_Data = new char*[width];
    for(unsigned int i = 0; i < width; i++){
        tab->m_Data[i] = new char[heigth];
    }

    for(unsigned int i = 0; i < width; i++)
        for(unsigned int j = 0; j < heigth; j++)
            tab->m_Data[i][j] = 0;
}

void set(BitArray* tab, unsigned int row, unsigned int column, bool value){
    if(value == true) SET_BIT_1(tab->m_Data, row, column);
    else SET_BIT_0(tab->m_Data, row, column);  
}

void print(const BitArray* tab, const char* name){
    std::cout << name << std::endl;
    for(unsigned int i = 0; i < rows(tab); i++){
        for(unsigned int j = 0; j < cols(tab); j++){
          std::cout << TEST_BIT(tab->m_Data, i, j);
        }
        std::cout << std::endl;
    }
}

void clear(BitArray* tab){
    if(tab->m_Data == nullptr) return;
    for(unsigned int i = 0; i < tab->m_Width; i++) delete[] tab->m_Data[i];
    delete[] tab->m_Data;
    tab->m_Data = nullptr;
}

BitArray* negate(BitArray* tab){
    for(unsigned int i = 0; i < rows(tab); i++){
        for(unsigned int j = 0; j < cols(tab); j++){
          if(TEST_BIT(tab->m_Data, i, j)) SET_BIT_0(tab->m_Data,i,j);
          else SET_BIT_1(tab->m_Data, i, j);
        }
    }
    return tab;
}

BitArray* xor_arrays(BitArray* result, BitArray const* src_left, BitArray const* src_right){
    for(unsigned int i = 0; i < rows(result); i++){
        for(unsigned int j = 0; j < cols(result); j++){
            if(TEST_BIT(src_left->m_Data,i,j)^TEST_BIT(src_right->m_Data,i,j)) SET_BIT_1(result->m_Data, i, j);
            else SET_BIT_0(result->m_Data, i, j);
        }
    }
    return result;
}