// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Prosze napisac funkcje tworzace i operujace na tablicy. Nalezy
// utworzyc tablice wypelniona od 1 do 6. Nalezy też stworzyc funcje
// "map" i "reduce", ktore przeprowadzają wymagane operacje na elementach.
// "map"
// "reduce"
// tablicy: inkrementacje, sume oraz iloczyn wszystkich elementow.

// Prosze zadbac o dobre zarzadzanie pamiecia.

// Pliku lab03.cpp nie wolno modyfikowac.

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod).

// Makefile dolaczony do rozwiazania powinien tworzyc plik wykonywalny
// o nazwie Lab03. Program nalezy kompilowac z flagami -Wall -g.

// Makefile powinien zawierac rowniez cel "clean", ktory usuwa pliki
// obiektowe i plik wykonywalny.

// Przy wykonaniu zadania nie wolno korzystać z internetu, notatek,
// ani żadnych innych materiałów (w tym własnych wcześniej
// przygotowanych plików)

// Kody źródłowe muszą znajdować się w katalogu ~/oop/lab_LABNR. Prawa
// do tego katalogu muszą być równe 700 (tylko dostęp dla
// właściciela).

// Skonczone zadanie nalezy wyslac na UPEL w formie spakowanego katalogu (lab_03)
// do archiwum lab_03.tar.gz
// tar -czvf lab_03.tar.gz ~/oop/lab_03
#include "table_functions.h"

int main() {
  const int tab_size = 6;
  int *table;
  prepare_table(&table, tab_size); // alokuje tablice i wypelnia liczbami od 1 do 6
  print_table(table, tab_size);
  
  operation_map operation1 = increment;
  operation1(table);
  print_table(table, tab_size);

  map(table, tab_size, operation1);
  print_table(table, tab_size);

  operation_reduce operations[] = {sum_all, product_all};
  int num_operations = sizeof(operations)/sizeof(operation_reduce);
  for (int i = 0; i < num_operations; ++i) {
  	int result = reduce(table, tab_size, operations[i]);
  	print_result(result);
  }
  remove_table(&table, tab_size);
  return 0;
}
/* wynik dzialania programu:
(1, 2, 3, 4, 5, 6)
(2, 2, 3, 4, 5, 6)
(3, 3, 4, 5, 6, 7)
wynik: 28
wynik: 7560
*/
