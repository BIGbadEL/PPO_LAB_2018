#pragma once
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include "person.h"


struct person_list{
    person* m_Data;
    int m_Size;
};


struct iterator{
    person_list* m_List;
    char* name;
    char* family;
    int m_Iter;
};

typedef iterator* person_list_iter;

void init_person_list(person_list* list);
void add_person(person_list* list, const char* name, const char* family);
void move_to_next(person_list_iter* iter);
void clean(person_list* list);

bool is_valid(person_list_iter iter);

person_list_iter get_iterator(person_list* list);


