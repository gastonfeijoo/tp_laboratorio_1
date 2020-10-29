#include <stdlib.h>
#include "Employee.h"
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

    pEmployee=employee_new();

    if (pEmployee!=NULL)
    {
        //retornos hacer
        employee_setId(pEmployee,atoi(idStr));
        employee_setNombre(pEmployee,nombreStr);
        employee_setHorasTrabajadas(pEmployee,atoi(horasTrabajadasStr));
        employee_setSueldo(pEmployee,atoi(sueldoStr));
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
