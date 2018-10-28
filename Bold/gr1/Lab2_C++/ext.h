#pragma once
#include <string.h>

typedef int(*fun)(int);
typedef void(*for_each)(int *);

struct Ext{
    int* m_Data;
    int m_Size;
    int m_Iterator;
    fun m_Policy;
};

void init(Ext* vec);
void init_with_size_and_policy(Ext* vec, int size, fun policy);
void resize_default(Ext* vec, int new_size);
void insert(Ext* vec, int position);
void print(int* element);
void zero(int *element);
void for_each_element(Ext* vec, for_each action);
void clear(Ext* vec);

Ext* clone(Ext* vec);


const int at(Ext* vec, int position);

inline const int size(Ext* vec) { return vec->m_Iterator; }
inline const int capacity(Ext* vec) { return vec->m_Size; }

