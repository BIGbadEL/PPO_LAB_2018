#include "table_functions.h"

#include <stdlib.h>
#include <iostream>



void prepare_table(int** tab, const int size){
    (*tab) = new int[size];
    for(int i = 0; i < size; i++) (*tab)[i] = i + 1; 
}

void print_table(int* tab, const int size){
    std::cout << "(";
    for(int i = 0; i < size; i++){ 
        std::cout << tab[i]; 
        if(i != size - 1) std::cout << ", ";
    }
    std::cout << ")\n";
}

void increment(int *tab){
    (*tab)++;
}

void map(int *tab, const int size, operation_map operation){
    for(int i = 0; i < size; i++){
        operation(tab+i);
    }
}

int sum_all(int *tab, const int size){
    int sum = 0;
    for(int i = 0; i < size; i++){
        sum += tab[i];
    }
    return sum;
}

int product_all(int *tab, const int size){
    int product = 1;
    for(int i = 0; i < size; i++){
        product *= tab[i];
    }
    return product;
}

int reduce(int *tab, const int size, operation_reduce operation){
    return operation(tab, size);
}

void print_result(int result){
    std::cout << result << std::endl;
}

void remove_table(int **tab, const int size){
    delete[] (*tab); 
}