/*
Celem zadania jest napisanie klas Date i Period  sluzacych do opisywania daty (rok, miesiac, dzien) i okresu miedzy dwoma datami. 

W prosty sposob mozna porownac czy jedna data a jest wczesniejsza niz b:
a.rok*10000 + a.miesiac*100 + a.dzien < b.rok*10000 + ...
Natomiast dwa okesy nakladaja sie jesli poczatek lub koniec jednego zawiera sie w drugim.

Przsuwanie dat najlatwiej zaimplementowac "po jedym dniu". 
Gdy dochodzimy do konca miesiaca licznik miesiecy zwiekszamy o 1.
Gdy dochodzimy do konca roku lcznik lat zwiekszamy o 1. 
Analogicznie podczas przesuwania dat w tyl.
(Inna implementacja np. uzywajaca dnia od poczatku roku jest rowniez dobra.)

Skompilowac z flagami -g -Wall do pliku i nazwie ptest.
 */
#include <iostream>
#include "Date.h"
#include "Period.h"
#include "Period.h"


int main () {
  using namespace std;
  const Period p1(Date(2014, 11, 23), Date(2014, 11, 25));
  const Period p2(Date(2014, 11, 17), Date(2014, 11, 24));
  Period p3(Date(2014, 11, 28), Date(2014, 11, 30));

  const Date endOfp2 = p2.end();
  cout << "Koniec p2 zawiera sie w p3? "  << p3.contains(endOfp2) << endl;

  p1.print(); 
  cout <<   (p1.overlapsWith( p2 ) ? " Naklada sie " : " Nie naklada sie ") ;
  p2.print();
  cout << endl;
  p3.print();
  cout << endl << " + 26 " << endl;
  p3.shiftDays(26);
  p3.print(); 
  cout << endl << " poczatek i koniec przesuniete inaczej "<< endl;
  p3.begin().shiftDays(-14);
  p3.end().shiftDays(18);
  p3.print(); 


  cout << endl << " p1 i p3 " <<  (p1.overlapsWith( p3 ) ? " Naklada sie " : " Nie naklada sie "); 
  cout <<  endl << " p2 i p3 " <<  (p2.overlapsWith( p3 ) ? " Naklada sie " : " Nie naklada sie "); 
  cout << endl;


}
/* wynik
Koniec p2 zawiera sie w p3? 0
2014.11.23 - 2014.11.25 Naklada sie 2014.11.17 - 2014.11.24
2014.11.28 - 2014.11.30
 + 26 
2014.12.24 - 2014.12.26
 poczatek i koniec przesuniete inaczej 
2014.12.10 - 2015.1.13
 p1 i p3  Nie naklada sie 
 p2 i p3  Nie naklada sie 
 */
