#include <stdlib.h>
#include <stdio.h>
#include "Employee.h"
#include "LinkedList.h"
#include "utn.h"
#include <string.h>

Employee* employee_new()
{
        Employee* pEmployee;

        pEmployee=malloc(sizeof(Employee));

        return pEmployee;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* pEmployee;

    int returnSet;


    pEmployee=employee_new();

    if (pEmployee!=NULL)
    {
        returnSet=employee_setId(pEmployee,atoi(idStr));
        returnValidation(returnSet);
        if (returnSet)
        {
            returnSet=employee_setNombre(pEmployee,nombreStr);
            returnValidation(returnSet);
            if (returnSet)
            {
                returnSet=employee_setHorasTrabajadas(pEmployee,atoi(horasTrabajadasStr));
                returnValidation(returnSet);
                if (returnSet)
                {
                    returnSet=employee_setSueldo(pEmployee,atoi(sueldoStr));
                    returnValidation(returnSet);
                }
            }
        }

    }

    return pEmployee;
}

int employee_setId(Employee* this,int id)
{
    int returnStatus;
    returnStatus=0;
    if (this!=NULL && id>0)
    {
        this->id=id;
        returnStatus=1;
    }
    return returnStatus;
}
int employee_getId(Employee* this,int* id)
{
    int returnStatus;
    returnStatus=0;
    if(this!=NULL && id!=NULL)
    {
        *id=this->id;
        returnStatus=1;
    }

    return returnStatus;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int returnStatus;
    returnStatus=0;

    if (this!=NULL && esAlfaNumerico(nombre))
    {
        strcpy(this->nombre,nombre);
        returnStatus=1;
    }
    return returnStatus;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int returnStatus;
    returnStatus=0;

    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        returnStatus=1;
    }

    return returnStatus;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int returnStatus;
    returnStatus=0;

    if (this!=NULL && horasTrabajadas>0)
    {
        this->horasTrabajadas=horasTrabajadas;
        returnStatus=1;
    }
    return returnStatus;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int returnStatus;
    returnStatus=0;

    if(this!=NULL && horasTrabajadas!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        returnStatus=1;
    }

    return returnStatus;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int returnStatus;
    returnStatus=0;

    if (this!=NULL && sueldo>0)
    {
        this->sueldo=sueldo;
        returnStatus=1;
    }
    return returnStatus;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int returnStatus;
    returnStatus=0;

    if(this!=NULL && sueldo!=NULL)
    {
        *sueldo=this->sueldo;
        returnStatus=1;
    }

    return returnStatus;
}

int employee_CompareByName(void* e1, void* e2)
{
    e1=(Employee*)e1;
    e2=(Employee*)e2;

    int returnCompare;
    returnCompare=0;
    int returnGet;
    char nombre1[128];
    char nombre2[128];
    returnGet=employee_getNombre(e1,nombre1);
    returnValidation(returnGet);
    if (returnGet)
    {
        returnGet=employee_getNombre(e2,nombre2);
        returnValidation(returnGet);
        if (returnGet)
        {
            if(strcmp(nombre1,nombre2)>0)
            {
                returnCompare=1;
            }
            else
            {
                if(strcmp(nombre1,nombre2)<0)
                {
                    returnCompare=-1;
                }
            }
        }
    }

    return returnCompare;
}
int employee_CompareById(void* e1, void* e2)
{
    e1=(Employee*)e1;
    e2=(Employee*)e2;
    int returnCompare;
    int returnGet;
    int id1;
    int id2;

    returnCompare=0;

    returnGet=employee_getId(e1,&id1);
    returnValidation(returnGet);
    if (returnGet)
    {
        returnGet=employee_getId(e2,&id2);
        returnValidation(returnGet);
        if (returnGet)
        {
            if(id1>id2)
            {
                returnCompare=1;
            }
            else
            {
                if(id1<id2)
                {
                    returnCompare=-1;
                }
            }
        }
    }
    return returnCompare;
}

void message_user(char* message)
{
    printf("%s\n",message);
}

void returnValidation(int returnStatus)
{
    if (!returnStatus)
    {
        message_user("Error!");
    }
}

int GetIncrementalID (LinkedList* pArrayListEmployee ,int increment)
{

    LinkedList* pEmployeesID;
    Employee* pAux = employee_new();
    int returnSort;
    int returnID;
    int returnGet;
    int returnIsEmpty;
    returnID=1;

    pEmployeesID = ll_newLinkedList();
    pEmployeesID=ll_clone(pArrayListEmployee);


    returnIsEmpty=ll_isEmpty(pEmployeesID);
    //printf("Retorno IsEmpty %d\n",returnIsEmpty);
    if (returnIsEmpty==0)
    {

        returnSort=ll_sort(pEmployeesID,employee_CompareById,0);
        //printf("Retorno Sort %d\n",returnSort);
        if (returnSort==0)
        {
            pAux=ll_get(pEmployeesID,0);
            returnGet=employee_getId(pAux,&returnID);
            returnValidation(returnGet);
            if (returnGet)
            {
                returnID=returnID+increment;
            }
        }
        else
        {
            returnID++;
        }
    }
    return returnID;
}
