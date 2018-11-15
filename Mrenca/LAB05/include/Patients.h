#pragma once
#include <iostream>

/**
 * @struct Patient
 * @brief Strukrura przetrzymująca pacjenta
*/

struct Patient{
    char _name;     /**< imie pacjenta                  */
    char _surname;  /**< nazwisko pacjenta              */
    int timeLeft;   /**< czas pozostały końca wizywy    */
    Patient* _next; /**< wskaźnik na kolejnego pacjenta */

    /**
     * @fn Patient 
     * @brief Generuje Pacjenta
     * @param name -> imie pacjenta
     * @param surname -> naziwko pacjenta
     * @param time -> czas potrzebny do obsługi pacjenta
    */

    Patient(char name, char surname, int time): _name(name), _surname(surname), timeLeft(time){ _next = nullptr; } // Tworzy pacjęta
};

/**
 * @class Patients
 * @brief Lista pacjentów
*/

class Patients{
    public:
        Patient* _first;
};

/**
 * @fn getTime
 * @brief pobiera czas pozostały pacjentowi
 * @param element -> pacjent
 * @return zwraca czas w  int
*/

int getTime(Patient* element);

/**
 * @fn startList
 * @brief inicjalizuje początkową warości dla składników listy
 * @param list -> wskaźnik na liste którą należy zainicjalizoać
*/

void startList(Patients* list); 

/**
 * @fn add
 * @brif dodaje pacjenta do listy
 * @param list -> wskaźnik na liste do której chcemy dodać pacjenta
 * @param name -> imie dodawanego pacjenta
 * @param surname -> nazwiako dodawango pacjenta
 * @param time -> czas potrzebny na obsłurzenie pacjenta
 * 
*/

void add(Patients* list, char name, char surname, int time); 

/**
 * @fn printList
 * @brief wypisuje wszytkich pacjętów na ekran
 * @param list -> list do wypisania
*/

void printList(Patients list); 

/**
 * @fn pop
 * @brief pobiera pierwszego pacjenta w kolejca
 * @param list -> wskaźnik na kolejke z której chemy pobrać pacjenta
 * @reutrn wskaźnik na kolejnego pacjeta
*/

Patient* pop(Patients* list); 

/**
 * @fn decrementTime
 * @brief oblicza upływ czasu podczas wizyty
 * @param element -> wskaźnik na aktualnie obsługiwanego
*/

void decrementTime(Patient* element); 

/**
 * @fn deletePatient
 * @biref usuwa pacjenta i czyści pamięć
 * @param element -> pacjent do usunięia
*/

void deletePatient( Patient* element);

/**
 * @fn freeList
 * @brief usuwa paciętów pozostałych na liście oraz czyści pamięć
 * @param list -> wskaźnik na liste do usunięcia
*/

void freeList(Patients* list); 