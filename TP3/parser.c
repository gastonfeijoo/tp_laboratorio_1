#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    //probar

    char id[100];
    char nombre[100];
    char horasTrabajadas[100];
    char sueldo[100];
    int rFscanF;


    //ya viene abierto
    //pFile=fopen("data.csv","r");

    if (pFile==NULL)
    {
        return -1;
    }
    while(!feof(pFile))
    {
        rFscanF=fscanf(pFile, "%[^,],%[^,],%[^,],%[^,]\n", id, nombre, horasTrabajadas,sueldo);
        if (rFscanF==4)
        {
            Employee* pAux = employee_new();

            //usar el constructor por parametros
            employee_setId(pAux,atoi(id));
            employee_setNombre(pAux,nombre);
            employee_setHorasTrabajadas(pAux,atoi(horasTrabajadas));
            employee_setSueldo(pAux,atoi(sueldo));
            //
            ll_add(pArrayListEmployee,pAux);
        }
        else
        {
            break;
        }
    }

    fclose(pFile);

    return 1;

}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{


    char id[100];
    char nombre[100];
    char horasTrabajadas[100];
    char sueldo[100];
    int rFread;



    pFile=fopen("data.csv","r");

    if (pFile==NULL)
    {
        return -1;
    }
    while(!feof(pFile))
    {
        rFread=fread(pFile, "%[^,],%[^,],%[^,],%[^,]\n", id, nombre, horasTrabajadas,sueldo);
        if (rFread==4)
        {
            Employee* pAux = employee_new();
            employee_setId(pAux,atoi(id));
            employee_setNombre(pAux,nombre);
            employee_setHorasTrabajadas(pAux,atoi(horasTrabajadas));
            employee_setSueldo(pAux,atoi(sueldo));
            ll_add(pArrayListEmployee,pAux);
        }
        else
        {
            break;
        }
    }

    fclose(pFile);


    return 1;
}
