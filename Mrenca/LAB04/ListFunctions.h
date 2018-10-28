#pragma once
#include "Pair.h"
#include <iostream>
#include <stdlib.h>


void startList(Pair** pairsList,int listSize);
void add(Pair** pairsList, Pair pair1, int* listSize, int* pairsNumber);
void printList(Pair* pairsList, int pairsNumber);
void freeList(Pair** pairsList);

