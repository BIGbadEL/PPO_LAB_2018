/* 
  Celem zadania jest napisanie struktury reprezenujaca tablice dwuwymiarowa.
  Wazne: stworzenie tablicy powinno wymagac pojedynczej alokacji pamieci, 
  to znaczy nalezy zaalokowac pamiec dla wszystkich wierszy/kolumn w kednej instrukcji.  

  Pomocne funkcje, ktore nalezy stworzyc to init (do inicjalizacji),
  diag (do ustawienia wartosci wszystkich el. diagonalnych) ustawienia
  elementow w kolumnie i wierszu a takze do wypisania tablicy.  Uwaga:
  przy implementacji powyzszych prosze sie zastanowic, ktora z funkcji
  mozna uzyc do implementacji innych.

   
  Z uzyciem pomocniczej struktury TabRange 
  (zespol 4 indeksow koluma, wiersz, kolumna, wiersz)
  powinnismy moc ustawiac wartosci w grupach elementow.  

  Takze z uzyciem struktury TabRange powinnismy moc stworzyc nowa tablice z
  czesci elementow innej tablicy jak pokazuje przyklad.
  
  Program nalezy skompilowac do pliku wkonywalnego o nazwie tabtest z flagami -g -Wall
*/
#include <iostream>
using namespace std;

#include "tab.h"
#include "tab.h"

int main() {
  Tab t;  
  init(&t, 7,7, 0.); // tablica 7 x 7 zainicjalizowana wartosciam 0.

  diag(&t, 3.);
  set(&t, 6, 6, 7.);
  TabRange r = {1,1, 3,3}; 
  set_part(&t, r, 9.);
  print(&t);
  
  cout << "jakas inna tablica (niesymetryczna)" << endl;
  Tab t2;
  init(&t2, 3, 7, 2.);
  print (&t2);
  set(&t2, 2, 2, 4.);
  cout << "wycinamy srodek (asymetrycznie) jako nowa tablice" << endl;

  TabRange center = {0,2, 6,4};  
  Tab* c = extract(&t, center);
  print(c);
  clean(c);
  delete c;
  clean(&t);
  clean(&t2);
  cout << "po operacji clean tablica jest pusta (ale mozna na niej wykonac print)" << endl;
  print(&t);
  // brak wyciekow pamieci
}
/* Wynik
| 3 0 0 0 0 0 0 |
| 0 9 9 0 0 0 0 |
| 0 9 9 0 0 0 0 |
| 0 0 0 3 0 0 0 |
| 0 0 0 0 3 0 0 |
| 0 0 0 0 0 3 0 |
| 0 0 0 0 0 0 7 |
jakas inna tablica (niesymetryczna)
| 2 2 2 |
| 2 2 2 |
| 2 2 4 |
| 2 2 2 |
| 2 2 2 |
| 2 2 2 |
| 2 2 2 |
wycinamy srodek (asymetrycznie) jako nowa tablice
| 0 9 9 0 0 0 |
| 0 0 0 3 0 0 |
po operacji clean tablica jest pusta (ale mozna na niej wykonac print)

 */
