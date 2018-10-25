#pragma once
#include <stdlib.h>
#include <iostream>


typedef void (*operation_map) (int*);
typedef int (*operation_reduce)(int*, const int);


void prepare_table(int** tab, const int size);
void print_table(int* tab, const int size);
void increment(int *tab);
void map(int *tab, const int size, operation_map operation);
void print_result(int result);
void remove_table(int **tab, const int size);
int sum_all(int *tab, const int size);
int product_all(int *tab, const int size);
int reduce(int *tab, const int size, operation_reduce operation);