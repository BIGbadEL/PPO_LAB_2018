#include "../include/StudentList.h"

void PrintListContent(int numberOfStudents, char** ListName){
    for(int i = 0; i < numberOfStudents; i++){
        std::cout << *(ListName + i) ;//<< " ";
        //std::cout << *(ListName + i + 1) << std::endl;
    }
}

void PrintListContent(int numberOfStudents, int* yearsList){
    for(int i = 0; i < numberOfStudents; i++){
        std::cout << *(yearsList + i) << std::endl;
    }
}

void PrintListContent(int numberOfStudents, char** namesList,char** surnamesList,int* yearsList){
    for(int i = 0; i < numberOfStudents; i++){
        std::cout << *(namesList + i) << " "; //<< " " << *(namesList + 2*i + 1);
        std::cout << *(surnamesList + i) << " ";
        std::cout << "years " << *(yearsList + i);
        std::cout << "\n";
    }
}

