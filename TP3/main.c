#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "UI.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

//break en todas las retornos de las validaciones

int main()
{

  //Crear lista
    LinkedList* pEmployees;
    pEmployees = ll_newLinkedList();


    char pathTxt[256];
    strcpy(pathTxt,"data.csv");
    char pathBin[256];
    strcpy(pathBin,"data.bin");

    int userOption;

    do
    {
        userOption=userMenuOption(10,0,"\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n3. Alta de empleado\n4. Modificar datos de empleado\n5. Baja de empleado\n6. Listar empleados\n7. Ordenar empleados\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n0. Salir","Elija una opcion...","Opcion Invalida...");
        MenuMainSwitch(userOption,pEmployees,pathTxt,pathBin);

    }while(userOption!=0);


    return 0;
}
