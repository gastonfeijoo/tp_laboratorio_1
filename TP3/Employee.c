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
        returnSet=employee_setNombre(pEmployee,nombreStr);
        returnValidation(returnSet);
        returnSet=employee_setHorasTrabajadas(pEmployee,atoi(horasTrabajadasStr));
        returnValidation(returnSet);
        returnSet=employee_setSueldo(pEmployee,atoi(sueldoStr));

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
    //printf("employee_setId - %d _",this->id);//debug
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

int employee_CompareByName(Employee* e1, Employee* e2)
{
    int returnCompare;
    returnCompare=0;

    if(strcmp(e1->nombre,e2->nombre)>0)
    {
        returnCompare=1;
    }
    else
    {
        if(strcmp(e1->nombre,e2->nombre)<0)
        {
            returnCompare=-1;
        }
    }
    return returnCompare;
}
int employee_CompareById(Employee* e1, Employee* e2)
{
    int returnCompare;
    returnCompare=0;

    if(e1->id>e2->id)
    {
        returnCompare=1;
    }
    else
    {
        if(e1->id<e2->id)
        {
            returnCompare=-1;
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
