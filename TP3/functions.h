#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_


#include "initStructures.h"
#include "relationshipStructures.h"
#include "functions.h"

#endif /* FUNCTIONS_H_ */

//agrupar por estructuras
// funciones que retornen la estructura

/*****************EMASCOTA*******************/
int GetIncrementalIDPets(eMascotas entity1[], int size1,int increment);

int GetDataForPets(eMascotas entity[], eRazas entity2[], int size, int size2);
int addDataStructurePets(eMascotas entity[],eMascotas aux,int size);
int LoadedRecordsStructurePets(eMascotas entity1[],int size1);
int findInStructByIdPets(eMascotas entity[], int size,int id);
void ModifyStructDataPets(eMascotas entity1[],eRazas entity2[],int size1,int size2,int id);
int removeRecordStructureByIdPets(eMascotas entity[], int size, int id);
void PrintStructurePets(eMascotas entity1[], int size1);
void PrintStructurePetsByWeight(eMascotas entity1[], int size1, int order);
int sortStructureFullElementsPets(eMascotas entity[], int size);
void sortStructurePetsById(eMascotas entity[], int size, int order);
void sortStructurePetsByWeight(eMascotas entity[], int size, int order);





/*****************FUNCIONES USERMENU*******************/

int userMenuOption(int optionsNumber, int optionNumberExit, char optionsText[],char optionChooseText[],char optionInvalidText[]);
void MenuMainSwitch(int userOption, eMascotas entity1[], eRazas entity2[] , ePais entity3[], int size1, int size2, int size3);
void MenuPrintSwitch(int userOption, eMascotas entity1[], eRazas entity2[] , ePais entity3[], int size1, int size2, int size3);
void PressAnyKey();

/*****************FUNCIONES VALIDATION*******************/

int ValidateStringTipo(char validateValue[],int verbose);
int ValidateCharSexo(char validateValue,int verbose);
int ValidateStringTamanio(char validateValue[],int verbose);

