#include "PersonList.h"

PersonList::PersonList(){
    m_Element = nullptr;
    m_Next = nullptr;
}

PersonList::~PersonList(){
    if(m_Element != nullptr) delete m_Element;
    if(m_Next != nullptr) delete m_Next;
}

void PersonList::addPerson(char *name, char* family){
    
    if(m_Element == nullptr){
        m_Element = new Person(name, family);
        return;
    }

    if( m_Next == nullptr){
        m_Next = new PersonList;
        m_Next->addPerson(name, family);
        return;
    }
    PersonList *last;
    PersonList *next = m_Next;
    while(next != nullptr){
        last = next;
        next = next->m_Next;
    }
    
    last->addPerson(name, family);
    return;
}

PersonList::Iterator PersonList::getIterator() const{
    Iterator result;
    result.m_List = (PersonList*)this;
    return result;
}

bool PersonList::Iterator::isValid() const{
    if(m_List == nullptr) return false;
    return true;
}

void PersonList::Iterator::moveToNext(){
    m_List = m_List->m_Next;
}

const Person& PersonList::Iterator::obj() const{
    return *(m_List->m_Element);
}