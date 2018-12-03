/* Celem zadania jest naduzycie przeladowania operatorow.
   
   klasa integer definije kilka operatorow, ktore zachowuja sie w sposob nienaturalny dla nich 
   (to jest - modyfikuja obiekt na rzecz ktore sa wywolane).
   
   Po zalaczeniu naglowka "value.h" mamy dostep do dodatkowej zmiennej $ przechowujacej wynik 
   ostatnio wykonanego dzialania. 
   UWAGA: $ jest absolutnie poprawnym identyfikatrem. 

   Kompilowac z flagami -Wall -g to pliku test.   
 */


#include <iostream>
#include "value.h"
int main() {
  using namespace std;
  value::integer x=7;
  cout << x << endl; 
  x-3;
  x*x;
  cout << x << " po paru operacjach " << endl;
  // $ to jest wynik ostaniego dzialania
  cout << value::$ << " ostani wynik "  << endl;
  value::integer y = value::$;
  y * 2;
  cout << value::$ << endl;
  value::integer z = x;
  z/15;  // dzielenie l. calkowitych 
  cout << z  << " " << value::$ << endl;
}
/* wynik 
7
16 po paru operacjach 
16 ostani wynik 
32
1 1
 */
