#pragma once

#include <iostream>

#define BITS_SIZE (sizeof(unsigned) * 8)
#define TEST_BIT(x,y) (((x[0] & (1 << y)) != 0))
#define SET_BIT_1(x,y) (x[0] |= (1<<(y)))
#define SET_BIT_0(x,y) (x[0] &= (~(1<<(y))))

void iPrintBit(const unsigned* bits, const int step, const char separator);
void iSetBit(unsigned* bits, const int pos, bool value);
void iFlipBit(unsigned* bits, const int pos);
void iAppendBit(unsigned* bits, bool value);

int iPullBit(unsigned* bits);
int iGetBit(const unsigned* bits, const int pos);