#pragma once
#include <iostream>

typedef unsigned char uchar;

#define BITS_SIZE (sizeof(uchar) * 8)

#define SET_BIT_1(tab, pos) (tab[(pos) / BITS_SIZE] |= (1 << ((pos) % BITS_SIZE)))
#define SET_BIT_0(tab, pos) (tab[(pos) / BITS_SIZE] &= ~(1 << ((pos) % BITS_SIZE)))
#define TEST_BIT(tab, pos) ((tab[(pos) / BITS_SIZE] & ((1 << ((pos) % BITS_SIZE)))) != 0)

struct Bitarr{
    uchar * m_Bits;
    unsigned int m_Size;
};

typedef Bitarr* ConstBitarrPtr;

void set_size(Bitarr* bits, unsigned nbits);
void fill_pattern(Bitarr* bits, const char* patern);
void print_bitarray(Bitarr* bits);
void xor_and_set(Bitarr* dest, Bitarr* left, Bitarr* right);
void clear(Bitarr* bits);
int n_set(Bitarr* bits);