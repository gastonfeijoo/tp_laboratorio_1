#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "UI.h"

int main()
{
    LinkedList* pEmployees;
    pEmployees = ll_newLinkedList();

    int userOption;
    char pathTxt[256];
    char pathBin[256];

    strcpy(pathTxt,"data.csv");
    strcpy(pathBin,"data.bin");


    do
    {
        userOption=userMenuOption(10,0,"\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n3. Alta de empleado\n4. Modificar datos de empleado\n5. Baja de empleado\n6. Listar empleados\n7. Ordenar empleados\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n0. Salir","Elija una opcion...","Opcion Invalida...");
        MenuMainSwitch(userOption,pEmployees,pathTxt,pathBin);

    }while(userOption!=0);


    return 0;
}
