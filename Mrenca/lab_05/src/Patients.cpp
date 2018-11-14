#include "Patients.h"

void startList(Patients* list){
    list->_first = nullptr;
}

void add(Patients* list, char name, char surname, int time){
    if(list->_first == nullptr){
        list->_first = new Patient(name, surname, time);
        return;
    }

    Patient* temp = list->_first;
    while(temp->_next != nullptr) temp = temp->_next;
    temp->_next = new Patient(name, surname, time);

}

void printList(Patients list){
    Patient* temp = list._first;

    while(temp != nullptr){
        std::cout << temp->_name << " " << temp->_surname << " czas: " << temp->timeLeft << std::endl;
        temp = temp->_next;
    }
}

Patient* pop(Patients* list){
    if(list->_first == nullptr) return nullptr;
    Patient* temp = list->_first;
    list->_first = list->_first->_next;
    return temp;
}

void decrementTime(Patient* element){
    if(element == nullptr) return;
    element->timeLeft --;
}

void deletePatient( Patient* element){
    if(element == nullptr) return;
    delete element;
    element = nullptr;
}

void freeList(Patients* list){
    Patient* toDelete = list->_first;
    while(toDelete != nullptr){
        Patient* temp = toDelete->_next;
        delete toDelete;
        toDelete = temp;
    }

}

int getTime(Patient* element){
    if(element == nullptr) return 0;
    return element->timeLeft;
}