#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "UI.h"
#include "utn.h"
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int returnStatus;
    int returnClear;
    returnStatus=0;

    if (!ll_isEmpty(pArrayListEmployee))
    {
        returnClear=ll_clear(pArrayListEmployee);
        returnValidation(!returnClear);
    }
    if (returnClear)
    {

        FILE* pFile;

        pFile=fopen(path,"r");

        if (pFile!=NULL)
        {
            parser_EmployeeFromText(pFile,pArrayListEmployee);
            returnStatus=1;
        }

        fclose(pFile);
    }

    return returnStatus;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int returnStatus;
    int returnClear;
    returnStatus=0;

    if (!ll_isEmpty(pArrayListEmployee))
    {
        returnClear=ll_clear(pArrayListEmployee);
        returnValidation(!returnClear);
    }
    if (returnClear)
    {

        FILE* pFile;

        pFile=fopen(path,"rb");

        if (pFile!=NULL)
        {
            parser_EmployeeFromBinary(pFile,pArrayListEmployee);
            returnStatus=1;
        }

        fclose(pFile);
    }
    return returnStatus;
}


int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pAux = employee_new();

    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
    int returnStatus;
    int returnSet;
    int returnLlAdd;
    returnStatus=0;

    id=GetIncrementalID(pArrayListEmployee,1);
    if (id==-1)
    {
        printf("No se pudo obtener un ID!\n");
    }
    else
    {
        getValidString("Ingrese el nombre:\n","Nombre Invalido",nombre);
        horasTrabajadas=getValidInt("Ingrese las horas trabajadas\n","Horas invalidas",0,372);//regla de negocio max 12 hs por dia por 31 dias
        sueldo=getValidInt("Ingrese el sueldo\n","Sueldo Invalido",0,INT_MAX);

        returnSet=employee_setId(pAux,id);
        returnValidation(returnSet);
        if (returnSet)
        {
            returnSet=employee_setNombre(pAux,nombre);
            returnValidation(returnSet);
            if (returnSet)
            {
                returnSet=employee_setHorasTrabajadas(pAux,horasTrabajadas);
                returnValidation(returnSet);
                if (returnSet)
                {
                    returnSet=employee_setSueldo(pAux,sueldo);
                    returnValidation(returnSet);
                    if (returnSet)
                    {
                        returnLlAdd=ll_add(pArrayListEmployee,pAux);
                        if(returnLlAdd==0)
                        {
                            returnStatus=1;
                        }
                    }
                }
            }

        }

    }


    return returnStatus;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pAux=employee_new();
    int idModify;
    int id;
    int returnStatus;

    char nombre[128];
    int horasTrabajadas;
    int sueldo;
    int returnSet;
    int returnLlSet;

    int i;
    int isFoundID;

    returnStatus=0;
    isFoundID=0;

    idModify=getValidInt("Ingrese el ID a modificar\n","ID invalido",0,INT_MAX);

    for (i=0;i<ll_len(pArrayListEmployee);i++)
    {
        pAux=(Employee*)ll_get(pArrayListEmployee,i);
        employee_getId(pAux,&id);
        if (id==idModify)
        {
            isFoundID=1;
            break;
        }

    }
    if (isFoundID)
    {

        getValidString("Ingrese el nombre:\n","Nombre Invalido",nombre);
        horasTrabajadas=getValidInt("Ingrese las horas trabajadas\n","Horas invalidas",0,372);//regla de negocio max 12 hs por dia por 31 dias
        sueldo=getValidInt("Ingrese el sueldo\n","Sueldo Invalido",0,INT_MAX);

        returnSet=employee_setId(pAux,idModify);
        returnValidation(returnSet);
        if (returnSet)
        {
            returnSet=employee_setNombre(pAux,nombre);
            returnValidation(returnSet);
            if (returnSet)
            {
                returnSet=employee_setHorasTrabajadas(pAux,horasTrabajadas);
                returnValidation(returnSet);
                if (returnSet)
                {
                    returnSet=employee_setSueldo(pAux,sueldo);
                    returnValidation(returnSet);
                    if (returnSet)
                    {
                        returnLlSet=ll_set(pArrayListEmployee,i,pAux);


                        if(returnLlSet==0)
                        {
                            returnStatus=1;
                        }
                    }
                }
            }

        }
    }

    return returnStatus;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int returnStatus;
    int idRemove;
    int id;
    int isFoundID;
    int i;
    returnStatus=-1;
    isFoundID=0;
    Employee* pAux=employee_new();

    idRemove=getValidInt("Ingrese el ID a eliminar\n","ID invalido",0,INT_MAX);

    for (i=0;i<ll_len(pArrayListEmployee);i++)
    {
        pAux=(Employee*)ll_get(pArrayListEmployee,i);
        employee_getId(pAux,&id);
        if (id==idRemove)
        {
            isFoundID=1;
            break;
        }

    }
    if (isFoundID)
    {

    returnStatus=ll_remove(pArrayListEmployee,i);
    }

    return returnStatus;
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
        // PONER IF EN RETORNOS********************
        returnGet=employee_getId(elementPEmployees,&id);
        returnValidation(returnGet);
        if (returnGet)
        {
            returnGet=employee_getNombre(elementPEmployees,nombre);
            returnValidation(returnGet);
                if (returnGet)
                {
                    returnGet=employee_getHorasTrabajadas(elementPEmployees,&horasTrabajadas);
                    returnValidation(returnGet);
                    if(returnGet)
                    {
                        returnGet=employee_getSueldo(elementPEmployees,&sueldo);
                        returnValidation(returnGet);
                        printf("%-4d\t%-15s\t%-4d\t%-4d\t\n",id,nombre,horasTrabajadas,sueldo);

                    }
                }
        }
    }
    return returnGet;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int returnSort;
    int orderField;
    int order;

    orderField=userMenuOption(2,0,"1. Por ID\n2. Por Nombre\n0. Salir\n","Elija una opcion...","Opcion Invalida...");
        if (orderField!=0)
        {
            order=userMenuOption(2,0,"1. Ascendente\n2. Descendente\n0. Salir\n","Elija una opcion...","Opcion Invalida...");
            if (order!=0)
            {
                switch (orderField)
                {
                case 1:
                    returnSort=ll_sort(pArrayListEmployee,employee_CompareById,order-1);
                    break;
                case 2:
                    returnSort=ll_sort(pArrayListEmployee,employee_CompareByName,order-1);
                    break;
                }
            }
        }


    return returnSort;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{

    int returnStatus;
    Employee* pAux = employee_new();
    int len;
    int i;

    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
    int returnGet;

    returnStatus=0;

    FILE* pFile;

    pFile=fopen(path,"w");

    len=ll_len(pArrayListEmployee);

    if (pFile!=NULL)
    {
        for(i=0;i<len;i++)
        {
            pAux=(Employee*)ll_get(pArrayListEmployee,i);

            returnGet=employee_getId(pAux,&id);
            returnValidation(returnGet);

            returnGet=employee_getNombre(pAux,nombre);
            returnValidation(returnGet);

            returnGet=employee_getHorasTrabajadas(pAux,&horasTrabajadas);
            returnValidation(returnGet);

            returnGet=employee_getSueldo(pAux,&sueldo);
            returnValidation(returnGet);


            fprintf(pFile,"%d,%s,%d,%d\n",id, nombre, horasTrabajadas, sueldo);

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

