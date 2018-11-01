#pragma once

#include "Person.h"



class PersonList{
    private:
        Person* m_Element;
        PersonList *m_Next;
        
    public:
        struct Iterator{
            PersonList *m_List;

            bool isValid() const;
            void moveToNext();
            const Person& obj() const; 
        };

    public:
        PersonList();
        void addPerson(char *name, char* family);
        ~PersonList();

        Iterator getIterator() const;

};
