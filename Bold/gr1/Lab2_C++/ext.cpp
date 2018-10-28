#include "ext.h"
#include <iostream>
void init(Ext* vec){
    vec->m_Policy = nullptr;
    vec->m_Size = 0;
    vec->m_Data = new int[1];
    vec->m_Iterator = 0;
}

void init_with_size_and_policy(Ext* vec, int size, fun policy){
    vec->m_Size = size;
    vec->m_Policy = policy;
    vec->m_Data = new int[size];
    vec->m_Iterator = 0;
}

void resize_default(Ext* vec, int new_size){
    int * new_data = new int[new_size];
    memcpy(new_data, vec->m_Data, vec->m_Size * sizeof(int));

    vec->m_Size = new_size;
    delete[] vec->m_Data;
    vec->m_Data = new_data;
}

void insert(Ext* vec, int data){
    if(vec->m_Iterator < vec->m_Size){
        vec->m_Data[vec->m_Iterator] = data;
        vec->m_Iterator++;
    }else{
        if(vec->m_Policy == nullptr) resize_default(vec, vec->m_Size + 1);
        else resize_default(vec, vec->m_Policy(vec->m_Size));
        vec->m_Data[vec->m_Iterator] = data;
        vec->m_Iterator++;
    }
}

void print(int* element){
    std::cout << *element << " ";
}
void zero(int *element){
    *element = 0;
}

void for_each_element(Ext* vec, for_each action){
    for(int i = 0; i < vec->m_Iterator; i++) action(vec->m_Data + i);
}

const int at(Ext* vec, int position){
    if(position >= vec->m_Iterator) return 0;
    return vec->m_Data[position];
}

Ext* clone(Ext* vec){
    Ext* dest = new Ext;
    memcpy(dest, vec, sizeof(Ext));
    return dest;
}

void clear(Ext* vec){
    delete[] vec->m_Data;
}