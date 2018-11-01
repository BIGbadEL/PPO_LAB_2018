/*
  Tematem zadania jest lista polaczona, do przechowywania obiektow klasy Person.

  Sama klasa Person ma dwa skladniki, napisy (char*) dla name i family 
  do przechowywania imienia i nazwiska. 
  Do dodawania do listy sluzy metoda addPerson.  
  Po elementach listy mozemy wygodnie iterowac za pomoca iteratora. 
  
  UWAGA: Iteracja zrobiona jest troche inaczej niz w zad 3. Prosze sie upewnic czy 
  zestaw klas pozwoli na takie uzycie.
  UWAGA: Prosze pamietac o poprawnosci const nawet tam gdzie przyklad tego nie wymaga.
  UWAGA: Alokacje nalezy zrobic z uzyciem new/delete.

  Kompilowac do pliku ptest z opcjami -Wall -g. 
 */

#include <iostream>
#include <cstring>


#include "Person.h"
#include "PersonList.h"

int main() {
  using namespace std;
  PersonList plist;
  
  char buffer_name[100];
  char buffer_family[100];
  
  strcpy(buffer_name, "Jan"), strcpy(buffer_family, "Kowalski");
  plist.addPerson( buffer_name, buffer_family);

  strcpy(buffer_name, "Anna"), strcpy(buffer_family, "Nowak");
  plist.addPerson(buffer_name, buffer_family);

  strcpy(buffer_name, "Kleofas"), strcpy(buffer_family, "Iksinski");
  plist.addPerson( buffer_name, buffer_family);

  strcpy(buffer_name, "Agnieszka-Maria"), strcpy(buffer_family, "Kawalerowicz-Rottensteinberger");
  plist.addPerson( buffer_name, buffer_family);


  PersonList::Iterator iter  = plist.getIterator();
  while ( iter.isValid() ) {
    const Person& p = iter.obj();
    cout << p.name() << " " << p.family() << endl;
    iter.moveToNext();
  }
}

/* wynik 
Jan Kowalski
Anna Nowak
Kleofas Iksinski
Agnieszka-Maria Kawalerowicz-Rottensteinberger
 */
