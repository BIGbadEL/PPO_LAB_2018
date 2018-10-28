/**
Celem zadania jest napisanie wydajnej funkcji do dzielenia napisu na czesci.

Nalezy napisac plik naglowkowy i zrodlowy tak aby ponizszy kod kompilowal sie i wykonywal.
Kodu poizej nie mozna zmienic. 

Prosze zauwazyc ze jednoczesnie odbywa sie  podzial dwoch napisow i
uzycie zmiennych globalnych uniemozliwi prawidlowe rozwiazanie problemu.
Funkcja chunk przygotowuje pomocniczą strukturę "delimited".
Funkcja next zwraca wartość "true" jeśli w napisie jest następna część pod-napisu
i jednocześnie przygotowuje "delimited" do pobrania tego podnapisu. 
Funkcja part kopiuje do bufora bierzącą część napisu.
Program należy skompilować do pliku o nazwie "test".

Prosze napisac, w miare mozliwosci, prosty makefile, 
ktory po napisaniu "make" skompiluje program a po napisaniu "make clean" usunie program wykonywalny i zbedne pliki obiektowe.
Od przyszlych zajec makefile jest wymagany (jego brak bedzie jednoznaczny z tym ze program sie nie kompiluje.)

 */
#include <iostream>
#include "strop.h"


int main () {

  delimited d1;
  delimited d2;
  const char* test1 = "Ala ma kota a kot ma mysz";
  const char* test2 = "To zadanie, bardzo proste, juz zrobilem";

  chunk(test1, &d1, ' ');
  chunk(test2, &d2, ',');

  char buffer[256];

  while ( next(&d1) and next(&d2) ) {
    part(&d1, buffer);
    std::cout << "-- >" << buffer <<"<";
  
    part(&d2, buffer);
    std::cout << ">" << buffer << "<"<< std::endl;
  }
}
/* wynik
-- >Ala<>To zadanie<
-- >ma<> bardzo proste<
-- >kota<> juz zrobilem<

 */
