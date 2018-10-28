/*
  Tematem zadania jest implementacja wygodnej dwu wymiarowej tablicy bitow.
  Uwaga: Do zapamietania stanu pojedynczego bitu musi byc uzyty tylko jeden bit,
  
   w przeciwnym razie zadanie bedzie nie na temat.
  
  Miejsce na bity prosze zlokowac dynamicznie.
  Podczas alokacji miejsca na bity nalezy uzyc operatora alokacji z c++ a w funkcji clear odpowiedniej dealokacji.
  
  Kompilowac z flagami -Wall -g do pliku wykonywalnego btest
 */


#include "bitarray.h"
#include <iostream>

int main() {

  BitArray b1;
  init(&b1, 35, 21); // rozmiar tablicy w bitach 35 na 21
  {
    for ( unsigned r = 0; r < rows(&b1); ++r) {
      for ( unsigned c = 0; c < cols(&b1); ++c) {
        bool bitValue = (r+c) %3 == 0; // zmienia sie co 3
        set(&b1, r, c, bitValue ); // ustawienie warosci bitu w rzedzie r i kolumnie c
      }
    }

    print(&b1, "b1"); // drukowanie
    clear(&b1); // dealokacja
  }

  BitArray b2;
  BitArray b3;
  init(&b2, 7, 11); 
  init(&b3, rows(&b2), cols(&b2)); 
  {
    for ( unsigned r = 0; r < rows(&b2); ++r) {
      for ( unsigned c = 0; c < cols(&b2); ++c) {
	set(&b2, r, c,  (r*c) %(c+1) == 0); // prawie losowe
	set(&b3, r, c,  (r*c) %(c+2) == 0); // prawie losowe
      }
    }
    print(&b2, "b2");     
    print(&b3, "b3");     
  }
  negate(&b2); // zmiana wartosci bitu
  print(&b2, "b2 po negacji");
  negate(negate(&b2)); // dzialanie bez efektu
  print(&b2, "b2 po podwojnej negacji");
    
  BitArray b4;
  init(&b4, rows(&b2), cols(&b2)); // nowa czysta tablica o rozmiarach z b2
  
  xor_arrays(&b4, (BitArray const*)&b3, (BitArray const*)&b2); // operacja xor na bitach
  print((const BitArray*)&b4, "po operacji XOR");
  
  clear(&b1); // to nie pomylka, clear jest wykonane dwukrotnie na b1
  clear(&b2);
  clear(&b3);
  clear(&b4);

}
/* wynik
b1
100100100100100100100
001001001001001001001
010010010010010010010
100100100100100100100
001001001001001001001
010010010010010010010
100100100100100100100
001001001001001001001
010010010010010010010
100100100100100100100
001001001001001001001
010010010010010010010
100100100100100100100
001001001001001001001
010010010010010010010
100100100100100100100
001001001001001001001
010010010010010010010
100100100100100100100
001001001001001001001
010010010010010010010
100100100100100100100
001001001001001001001
010010010010010010010
100100100100100100100
001001001001001001001
010010010010010010010
100100100100100100100
001001001001001001001
010010010010010010010
100100100100100100100
001001001001001001001
010010010010010010010
100100100100100100100
001001001001001001001
b2
11111111111
10000000000
11000000000
10100000000
11010000000
10001000000
11100100000
b3
11111111111
10000000000
10100000000
11001000000
10100010000
10010000100
11101000001
b2 po negacji
00000000000
01111111111
00111111111
01011111111
00101111111
01110111111
00011011111
b2 po podwojnej negacji
00000000000
01111111111
00111111111
01011111111
00101111111
01110111111
00011011111
po operacji XOR
11111111111
11111111111
10011111111
10010111111
10001101111
11100111011
11110011110
 */
