#include "person_list.h"


void init_person_list(person_list* list){
    list->m_Size = 0;
    list->m_Data = NULL;
}

void add_person(person_list* list,const char* name,const char* family){
    list->m_Size++;
    list->m_Data = (person*)std::realloc(list->m_Data, list->m_Size);
    strcpy(list->m_Data[list->m_Size - 1].name, name);
    strcpy(list->m_Data[list->m_Size - 1].family, family);
}

bool is_valid(person_list_iter iter){
    if(iter->m_Iter < iter->m_List->m_Size + 1)
        return true;
    
    delete iter;
    return false;
}

person_list_iter get_iterator(person_list* list){
    person_list_iter iter = new iterator;
    iter->m_Iter = 1;
    iter->m_List = list;
    iter->name = list->m_Data->name;
    iter->family = list->m_Data->family;

    return iter;
}

void move_to_next(person_list_iter* iter){
    if((*iter)->m_Iter <= (*iter)->m_List->m_Size){
        (*iter)->name = (*iter)->m_List->m_Data[(*iter)->m_Iter].name;
        (*iter)->family = (*iter)->m_List->m_Data[(*iter)->m_Iter].family;
        (*iter)->m_Iter++;
    }
}

void clean(person_list* list){
    free(list->m_Data);
}

