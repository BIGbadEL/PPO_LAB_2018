/* Celem zadania jest przecwiczenie przeladowania operatorow.
   
   Klasa Money posiada dwie skladowe, ilosc pieniedzy i nazwe waluty.
   Uwaga: to co zwracaja operatory ?= to nie musi byc tego  samego typu co po ich lewej stronie
   
   Kompilwac z flagami -Wall -g to pliku test
 */

#include "Money.h"

#include <iostream>
int main() {
  using namespace std;
  Money x(1034179*Currency::USD); // w jakis sposob konstruktor z USD musi odroznic PLN
  cout << Currency::type(x) << endl;


  // // zaokraglanie w dol
  cout << (x -=_10) << endl; // do dziesiatek
  cout << (x -=_100) << endl; // do setek
  cout << (x -=_1000) << endl; // do tysiecy
  
  const Money y(5633*Currency::PLN); 
  cout << Currency::type(y) << endl;
  

  // // zaokraglanie w gore
  cout << (y +=_10) << endl; // do dziesiatek
  cout << (y +=_100) << endl; // do setek
  cout << (y +=_1000) << endl; // do tysiecy

}
/* wynik
USD
1034170
1034100
1034000
PLN
5640
5700
6000
 */
