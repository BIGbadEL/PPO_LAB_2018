#pragma once

#include <iostream>

#define BITS_SIZE (sizeof(char)*8)
#define SET_BIT_1(tab, r, c) (tab[r][c / BITS_SIZE] |= (1 << ((c % BITS_SIZE))))
#define SET_BIT_0(tab, r, c) (tab[r][c / BITS_SIZE] &= (~(1 << (c % BITS_SIZE))))
#define TEST_BIT(tab, r, c)  ((tab[r][c / BITS_SIZE] & (1 << ((c % BITS_SIZE)))) != 0)

struct BitArray{
    unsigned int m_Width;
    unsigned int m_Heigth;
    char** m_Data;
};

void init(BitArray* tab, unsigned int width, unsigned int heigth);
void set(BitArray* tab, unsigned int row, unsigned int column, bool value);
void print(BitArray const* tab, const char* name);
void clear(BitArray* tab);

BitArray* negate(BitArray* tab);
BitArray* xor_arrays(BitArray* result, BitArray const* src_left, BitArray const* src_right);

int get_bit(BitArray *tab, unsigned int row, unsigned int column);

inline const unsigned int rows(const BitArray* tab){ return tab->m_Width; }
inline const unsigned int cols(const BitArray* tab){ return tab->m_Heigth; }