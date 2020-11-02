#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int returnStatus;
    returnStatus=0;

    FILE* pFile;

    pFile=fopen(path,"r");

    if (pFile!=NULL)
    {
        parser_EmployeeFromText(pFile,pArrayListEmployee);
        returnStatus=1;
    }

    fclose(pFile);

    return returnStatus;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int returnStatus;
    returnStatus=0;

    FILE* pFile;

    pFile=fopen(path,"rb");

    if (pFile!=NULL)
    {
        parser_EmployeeFromBinary(pFile,pArrayListEmployee);
        returnStatus=1;
    }

    fclose(pFile);

    return returnStatus;
}


int controller_addEmployee(LinkedList* pArrayListEmployee)
{

    return 1;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int returnGet;
    int len;
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
    Employee* elementPEmployees;

    len = ll_len(pArrayListEmployee);
    for(int i=0;i<len;i++)
    {
        elementPEmployees=(Employee*)ll_get(pArrayListEmployee,i);

        returnGet=employee_getId(elementPEmployees,&id);
        returnValidation(returnGet);
        returnGet=employee_getNombre(elementPEmployees,nombre);
        returnValidation(returnGet);
        returnGet=employee_getHorasTrabajadas(elementPEmployees,&horasTrabajadas);
        returnValidation(returnGet);
        returnGet=employee_getSueldo(elementPEmployees,&sueldo);
        returnValidation(returnGet);
        if (returnGet)
        {
            printf("%-4d\t%-15s\t%-4d\t%-4d\t\n",id,nombre,horasTrabajadas,sueldo);
        }
    }
    return returnGet;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int returnSort;

    //returnSort=ll_sort(pArrayListEmployee,employee_CompareById,1);
    returnSort=ll_sort(pArrayListEmployee,employee_CompareByName,1);

    return returnSort;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{

    int returnStatus;
    Employee* pAux = employee_new();
    int len;
    int i;

    returnStatus=0;

    FILE* pFile;

    pFile=fopen(path,"w");

    len=ll_len(pArrayListEmployee);

    if (pFile!=NULL)
    {
        for(i=0;i<len;i++)
        {
            pAux=(Employee*)ll_get(pArrayListEmployee,i);
            fwrite(pAux,sizeof(Employee),1,pFile);
            returnStatus=1;
        }
    }

    fclose(pFile);

    return returnStatus;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int returnStatus;
    Employee* pAux = employee_new();
    int len;
    int i;

    returnStatus=0;

    FILE* pFile;

    pFile=fopen(path,"wb");

    len=ll_len(pArrayListEmployee);

    if (pFile!=NULL)
    {
        for(i=0;i<len;i++)
        {
            pAux=(Employee*)ll_get(pArrayListEmployee,i);
            fwrite(pAux,sizeof(Employee),1,pFile);
            returnStatus=1;

        }
    }

    fclose(pFile);

    return returnStatus;

}

