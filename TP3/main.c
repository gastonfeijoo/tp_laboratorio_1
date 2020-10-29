#include <stdio.h>
#include <stdlib.h>
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
    int i;
    char pathTxt[256];
    strcpy(pathTxt,"data.csv");

    Employee* elementPEmployees;

    pEmployees = ll_newLinkedList();

    controller_loadFromText(pathTxt,pEmployees);

    len = ll_len(pEmployees);

    printf("Cantidad de elementos: %d\n", len);

    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;

    for(i=0;i<len;i++)
    {
        elementPEmployees=(Employee*)ll_get(pEmployees,i);

        employee_getId(elementPEmployees,&id);
        employee_getNombre(elementPEmployees,nombre);
        employee_getHorasTrabajadas(elementPEmployees,&horasTrabajadas);
        employee_getSueldo(elementPEmployees,&sueldo);


        printf("%-4d\t%-15s\t%-4d\t%-4d\t\n",id,nombre,horasTrabajadas,sueldo);
    }

    return 0;
}
