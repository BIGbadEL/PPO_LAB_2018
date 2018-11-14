#include "../include/StudentList.h"

void AddStudent( int* numberOfStudents, 
char*** namesList,
char*** surnamesList,
int** yearsList, 
const char* name, 
const char* secName, 
const char* surname, 
int number
){
    (*numberOfStudents)++;
    *namesList = (char**)std::realloc(*namesList, sizeof(*namesList) * (*numberOfStudents));
    *surnamesList = (char**)std::realloc(*surnamesList, sizeof(*surnamesList) * (*numberOfStudents));
    *yearsList = (int*)std::realloc(*yearsList, sizeof(char*) * (*numberOfStudents));


    if(!(*namesList && *surnamesList && *yearsList)) return;

    std::string temp(name);
    temp.append(" ");
    temp.append(secName);

    char *names = (char*)std::malloc(sizeof(char) * temp.length()+1);
    strcpy(names, temp.c_str());



    *(*namesList + (*numberOfStudents - 1)) = names;
    *(*surnamesList + (*numberOfStudents - 1)) = (char*)surname;
    *(*yearsList + *numberOfStudents - 1) = number;

}

void ClearStudents (int *numberOfStudents, char*** namesList,char*** surnamesList, int** yearsList){
    
    for(int i = 0; i < *numberOfStudents; i++) free(*(*namesList + i));
    
    free(*namesList);
    free(*surnamesList);
    free(*yearsList);
    *numberOfStudents = 0;
}

void DeleteStudent(int *numberOfStudents, char*** namesList, char*** surnamesList, int **yearsList, 
const int studentToDeleteListIndex){
    
    (*numberOfStudents)--;

    free(*(*namesList + studentToDeleteListIndex));

    for(int i = studentToDeleteListIndex; i < *numberOfStudents; i++){
        *(*namesList +  i) = *(*namesList + i + 1);
    }

    *namesList = (char**)std::realloc(*namesList, 2 * sizeof(*namesList) * *numberOfStudents);

    for(int i = studentToDeleteListIndex; i < *numberOfStudents - 1; i++){
        *(*surnamesList + i) = *(*surnamesList + i + 1);
        *(*yearsList + i) = *(*yearsList + i + 1);
    }

    *surnamesList = (char**)std::realloc(*surnamesList, sizeof(*surnamesList) * *numberOfStudents);
    *yearsList = (int*)std::realloc(*yearsList, sizeof(*yearsList) * *numberOfStudents);

}