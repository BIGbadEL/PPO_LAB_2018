/*
  Tematem zadania jest lista polaczona, do przechowywania struktur Person.
  Sama struktura Person ma dwa skladniki, napisy (char*) name i family 
  do przechowywania imienia i nazwiska. 
  
  Do dodawania do listy sluzy funkcja add_person.  
  
  Do przegladania listy pomocna jest struktura person_list_iter
  (trywialne), do obslugi ktorej sluza trzy funkcje: get_iterator -
  wytwarza, is_valid sprawdza czy iterator pokazuje na strukture
  Person i move_to_next, ktory sluzy do przejscia do nastepnego
  elementu.
  
  Funkcja clean czysci pamiec. Alokacje mozna zobic z uzyciem new/delete lub malloc/free.
  Kompilowac do pliku ptest z opcjami -Wall -g. 
 */

#include <iostream>
#include <cstring>


#include "person.h"
#include "person_list.h"

int main() {
  using namespace std;
  person_list plist;
  init_person_list(&plist);
  
  char buffer_name[100];
  char buffer_family[100];
  
  strcpy(buffer_name, "Jan"), strcpy(buffer_family, "Kowalski");
  add_person(&plist, buffer_name, buffer_family);

  strcpy(buffer_name, "Anna"), strcpy(buffer_family, "Nowak");
  add_person(&plist,  buffer_name, buffer_family);

  strcpy(buffer_name, "Kleofas"), strcpy(buffer_family, "Iksinski");
  add_person(&plist,  buffer_name, buffer_family);

  strcpy(buffer_name, "Agnieszka-Maria"), strcpy(buffer_family, "Kawalerowicz-Rottensteinberger");
  add_person(&plist,  buffer_name, buffer_family);

  person_list_iter iter  = get_iterator(&plist);
  while ( is_valid(iter) ) {
    cout << iter->name << " " << iter->family << endl;
    move_to_next(&iter);
  }
  
  clean(&plist);
}

/* wynik 
Jan Kowalski
Anna Nowak
Kleofas Iksinski
Agnieszka-Maria Kawalerowicz-Rottensteinberger   
 */
