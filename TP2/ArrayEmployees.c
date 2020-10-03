#include "ArrayEmployees.h"
#include "strings.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#define EMPTY 1
#define FULL 0

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees(Employee* list, int len)
{

    int returnStatus;
    if(len>0)
    {
        int i;
        i=0;
        for(i=0;i<len;i++)
        {
            list[i].isEmpty=EMPTY;
        }
        returnStatus=0;
    }
    else
    {
        returnStatus=-1;
    }

    return returnStatus;
}

/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*
UTN FRA – Tecnicatura Superior en Programación. http://www.sistemas-utnfra.com.ar 4
Programación I – Laboratorio I
*/
int addEmployee(Employee* list, int len, int id, char name[],char
lastName[],float salary,int sector)
{
    int i;
    int returnStatus;

    returnStatus=-1;

    for(i=0;i<len;i++)
    {
        if (list[i].isEmpty==EMPTY)
        {

            list[i].id=id;
            list[i].salary=salary;
            list[i].sector=sector;
            list[i].isEmpty=FULL;
            strcpy(list[i].name,name);
            strcpy(list[i].lastName,lastName);
            returnStatus=0;


            break;
        }
    }

return returnStatus;
}

/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int findEmployeeById(Employee* list, int len,int id)
{
    int i;
    int returnStatus;
    i=0;
    returnStatus=-1;
    for (i=0;i<len;i++)
    {
        if (list[i].id==id && list[i].isEmpty==FULL)
        {
            returnStatus=i;
        }
    }
    return returnStatus;
}

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int removeEmployee(Employee* list, int len, int id)
{
    int idIndexPosition;
    int returnStatus;
    char userOption;
    idIndexPosition=findEmployeeById(list,len,id);
    if (idIndexPosition!=-1)
    {
        do
        {
            printf("Esta seguro de eliminar el legajo? S/N \n");
            userOption=GetCharacter();
            userOption=toupper(userOption);
            if (userOption=='S')
            {
                list[idIndexPosition].isEmpty=EMPTY;
                returnStatus=0;
            }
        }while(userOption!='S' && userOption!='N');
    }
    else
    {
        printf("Legajo no Encontrado \n");
        returnStatus=-1;
    }

    return returnStatus;
}

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(Employee* list, int len, int order)
{
return 0;
}

/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int
*
*/
int printEmployees(Employee* list, int length)
{
    int i;
    int emptyListingFlag;
    i=0;
    emptyListingFlag=0;

    printf("Nomina de empleados\n\n");
    printf("ID    Nombre                                             Apellido                                           Salario        Sector\n");
    for(i=0;i<length;i++)
    {
        if (list[i].isEmpty==FULL)
        {
            printf("%-4d  %-50s %-50s %-14.2f %-8d\n",list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].sector);
            emptyListingFlag=1;
        }
    }
    printf("Fin de la nomina\n\n");
    if (emptyListingFlag==0)
    {
        printf("No hay empleados en la nomina\n");
    }
    return 0;
}
