/*
Tematem zadania jest rozszerzanlny wektor integerow z moliwoscia
podania poczatkowego wymiaru jak rowniez podania funkcji (polityki)
roszerzania pamieci.  

Jako sposob przechowywania danych nalezy uzyc tablicy alokowanej
dynamicznie za pomoca operatorow new/delete lub malloc/free.

Pomocna funkcja sluzaca do operowani na wszystkich elementach to for_each_element.
Na wyposarzeniu sa funkcje, ktora ona wywoluje print i zero.


Program ma sie kompilowac do pliku wykonywalnego o nazwie main z opcjami kompilatora -Wall -g
*/
#include <iostream>
using namespace std;

#include "ext.h"


int newsz(int sz) {
  return 2*sz; // rozmiar rosnie dwukrotnie 
}


int main() {
  struct Ext vec1;
  struct Ext vec2;
  init(&vec1);
  init_with_size_and_policy(&vec2, 2, newsz);
  
  for ( int i = 0; i < 20; i++ ) {
    insert(&vec1, i*2);
    insert(&vec2, i*3);
    cout << "rozmiar Lin "<< size(&vec1) << " Exp " << size(&vec2) << " pojemosc Lin " << capacity(&vec1) << " Exp " << capacity(&vec2) << endl;
  }
  cout << "pod indeksem 10 "<< at(&vec1, 10) << " Exp " << at(&vec2, 10) << endl;
  for_each_element(&vec1, print);

  cout << "klonujemy" << endl;
  Ext* vec3 = clone(&vec1);
  for_each_element(vec3, print);
  cout << "zerujemy" << endl;
  for_each_element(vec3, zero);
  cout << "po wyzerowaniu" << endl;
  for_each_element(vec3, print);

  cout << endl;
  clear(&vec1);
  clear(&vec2);
  clear(vec3);
  delete vec3;
}
/* wynik dzialania
rozmiar Lin 1 Exp 1 pojemosc Lin 5 Exp 2
rozmiar Lin 2 Exp 2 pojemosc Lin 5 Exp 2
rozmiar Lin 3 Exp 3 pojemosc Lin 5 Exp 4
rozmiar Lin 4 Exp 4 pojemosc Lin 5 Exp 4
rozmiar Lin 5 Exp 5 pojemosc Lin 5 Exp 8
rozmiar Lin 6 Exp 6 pojemosc Lin 10 Exp 8
rozmiar Lin 7 Exp 7 pojemosc Lin 10 Exp 8
rozmiar Lin 8 Exp 8 pojemosc Lin 10 Exp 8
rozmiar Lin 9 Exp 9 pojemosc Lin 10 Exp 16
rozmiar Lin 10 Exp 10 pojemosc Lin 10 Exp 16
rozmiar Lin 11 Exp 11 pojemosc Lin 15 Exp 16
rozmiar Lin 12 Exp 12 pojemosc Lin 15 Exp 16
rozmiar Lin 13 Exp 13 pojemosc Lin 15 Exp 16
rozmiar Lin 14 Exp 14 pojemosc Lin 15 Exp 16
rozmiar Lin 15 Exp 15 pojemosc Lin 15 Exp 16
rozmiar Lin 16 Exp 16 pojemosc Lin 20 Exp 16
rozmiar Lin 17 Exp 17 pojemosc Lin 20 Exp 32
rozmiar Lin 18 Exp 18 pojemosc Lin 20 Exp 32
rozmiar Lin 19 Exp 19 pojemosc Lin 20 Exp 32
rozmiar Lin 20 Exp 20 pojemosc Lin 20 Exp 32
pod indeksem 10 20 Exp 30
0 2 4 6 8 10 12 14 16 18 20 22 24 26 28 30 32 34 36 38 klonujemy
0 2 4 6 8 10 12 14 16 18 20 22 24 26 28 30 32 34 36 38 zerujemy
po wyzerowaniu
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
 */
