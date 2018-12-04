/*
 * Celem zadanie jest napisanie klasy: itr - to jest iterator sluzacy do
 * przegladania zawartosci tablicy intow. Przyklad uzycia jest na koncu tego kodu.
 * Dodatkowo klasy sum,average,minmax w przestrzeni numutils sluza
 * do zbierania statystyk z przegladniecia tablicy. 
 * Klasy te powinny byc ze soba powiazane tak by nie trzeba bylo pisac 
 * funkcji foreach dla kazdej z nich. (np zeby mozna bylo dopisac klase minmaxABS)
 *
 * Skompilowac z flagami -g -Wall do pliku test.
 */

#include <iostream>
#include "foreach.h"
#include "itr.h"
#include "numutils.h"

int main() {
  using namespace std;
  int array[7] = {2,2,3,3,7,1,0};
 
  numutils::sum sum1;
  numutils::average average;
  numutils::minmax minmax;
  
  foreach(itr(array, 7), sum1);
  sum1(2); // dodajemy jeszcze jeden
  cout << sum1.result() << endl;

  foreach(itr(array, 7), average);
  cout << average.result() << endl;

  foreach(itr(array+1, array+5), minmax);
  cout << minmax.min() << " " << minmax.max() << endl;
  
  
  cout << " wypiszmy " << endl;
  for ( itr it = itr(array, 7) ; it ; ++it )  {
    cout << *it << endl;
  }
}
/* wynik
20
2.57143
2 7
 wypiszmy 
2
2
3
3
7
1
0
 */
