/* 
   Celem zadania jest napisanie strutury pomocnej w reprezentacji ciagu bitow o dowolnej dlugosci
   Reprezentacja ma byc efektywna. Do skladowania bitow nalezy uzyc slow typu unsigned char.
   Mozna uzyc calego lub czesci kodu z laboratorium 1.
   
   Przydatne funkcje to set_size do rezerwacji pamieci i clear do zwolnienia pamieci.
   
   fill_pettern pozwala na wypelnienie wzorcem (uwaga wzorce moga byc roznej dlugosci).
   
   xor_and_set pozwala na wykonanie operacji xor = albo albo na tych ciagach bitowych.

   Kompilowac z opcja -g -Wall to pliku test.
 */
#include <iostream>

#include "bitarr.h"

int main() {
  using namespace std;
  const unsigned nbits = 83;
  Bitarr b1;
  set_size(&b1, nbits);  // przygotowuje miejsce na minimum "nbits" bitow
  fill_pattern(&b1, "0110" ); // wypelnia wzorcem rozpoczynajac od LSB tu: ....01100110

  ConstBitarrPtr c = &b1;
  print_bitarray(c);
  cout << "n-set " << n_set(c) << endl;


  Bitarr b2;
  set_size(&b2, nbits);
  fill_pattern(&b2, "11010" );
  print_bitarray(&b2);

  Bitarr b3;
  set_size(&b3, nbits);
  
  xor_and_set(&b3, c, &b2); // wykonuje operacje xor - daje 1 gdy bity sa rozne 
  print_bitarray(&b3);
  
  
  clear(&b1);
  clear(&b2);
  clear(&b3);
}

/* wynik
110_01100110_01100110_01100110_01100110_01100110_01100110_01100110_01100110_01100110_01100110
n-set 42
010_11010110_10110101_10101101_01101011_01011010_11010110_10110101_10101101_01101011_01011010
100_10110000_11010011_11001011_00001101_00111100_10110000_11010011_11001011_00001101_00111100
 */
