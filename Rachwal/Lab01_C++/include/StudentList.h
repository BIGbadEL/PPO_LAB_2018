#pragma once

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>

void AddStudent( int* numberOfStudents, 
char*** namesList,
char*** surnamesList,
int** yearsList, 
const char* name, 
const char* secName, 
const char* surname, 
int number
);

void PrintListContent(int numberOfStudents, char** ListName);
void PrintListContent(int numberOfStudents, int* yearsList);
void PrintListContent(int numberOfStudents, char** namesList,char** surnamesList,int* yearsList);
void ClearStudents (int *numberOfStudents, char*** namesList,char*** surnamesList, int** yearsList);
void DeleteStudent(int *numberOfStudents, char*** namesList, char*** surnamesList, int **yearsList, const int studentToDeleteListIndex);
