/**
 * Celem zadanie jest nzpisanie klasy StringWrapper
 * Klasa ta posluzyc ma do ulatwienia operacji na napisach, w szczegolnosci append.
 *
 *
 * Nalezey zadbac o poprawne zarzadzanie pamiecia. 
 * UWAGA: Nie wolno uzywac w implementacji klasy std::string. (zadanie nie na temat 0pkt). 
 */

#include <iostream>

#include <string.h>
#include "StringWrapper.h"

using namespace std;

int main() {
  const char* s0 = "Witaj Swiecie";  
  StringWrapper s1("Witaj swiecie");

  if ( StringWrapper::eq(s0, s1) )  
    cout << "Napisy sa identyczne" << endl;

  if ( StringWrapper::eqIcase(s0, s1) )
    cout << "Napisy sa identyczne jesli zaniedbamy wielkosc liter" << endl;

  print(s1);
  s1.append(" tu i teraz,");
  print(s1);
  
  StringWrapper s2(s1);
  s2.append(s1).append("i jeszcze raz!");

  print(s2);
}
/* wynik
Napisy sa identyczne jesli zaniedbamy wielkosc liter
Witaj swiecie
Witaj swiecie tu i teraz,
Witaj swiecie tu i teraz,Witaj swiecie tu i teraz,i jeszcze raz!
 */
