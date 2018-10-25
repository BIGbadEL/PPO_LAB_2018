#include "ListFunctions.h"


void startList( Pair** pairsList, int listSize){

    #ifdef DEBUG
	std::cout<< "Alokacja pamieci" << std::endl;
	#endif

    *pairsList = (Pair*)std::malloc(sizeof(Pair) * listSize);

    #ifdef DEBUG
	if(*pairsList == NULL) std::cout<< "Error" << std::endl;
	#endif
}

void add(Pair** pairsList, Pair pair, int* listSize, int* pairsNumber){

    #ifdef DEBUG
	std::cout<< "Dodawanie " << *pairsNumber <<  " elementu" << std::endl;
	#endif

    if(*pairsNumber >= *listSize){
        (*listSize)++;
        *pairsList = (Pair*)std::realloc( *pairsList,sizeof(Pair) * (*listSize));
    }

    (*pairsList)[*pairsNumber] = pair;
    (*pairsNumber)++;
}

void printList(Pair* pairsList, int pairsNumber){
    for(int i = 0; i < pairsNumber; i++){
        std::cout << "( " << pairsList[i].val[0] << ", ";
        std::cout << pairsList[i].val[1] << ")\n";
    }
}

void freeList(Pair** pairsList){

    #ifdef DEBUG
	std::cout<< "Zwalnianie pamieci" << std::endl;
	#endif

    free(*pairsList);
}