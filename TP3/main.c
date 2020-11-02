#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

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



int main()
{

  //Crear lista
    LinkedList* pEmployees;
    int len;
    char pathTxt[256];
    strcpy(pathTxt,"data.csv");
    char pathBin[256];
    strcpy(pathBin,"data.bin");

    pEmployees = ll_newLinkedList();

    len = ll_len(pEmployees);

  //  controller_loadFromText(pathTxt,pEmployees);
    controller_loadFromBinary(pathBin,pEmployees);
    len = ll_len(pEmployees);

//  controller_saveAsBinary(pathBin,pEmployees);

    printf("Cantidad de elementos: %d\n", len);

    controller_sortEmployee(pEmployees);

    controller_ListEmployee(pEmployees);


    return 0;
}
