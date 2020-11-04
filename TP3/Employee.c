#include <stdlib.h>
#include <stdio.h>
#include "Employee.h"
#include "LinkedList.h"
#include "utn.h"
#include <string.h>

/** \brief Employee constructor - Allocates memory for employee structure
 *
 * \return Employee* return pointer to mem address of structure
 *
 */
Employee* employee_new()
{
        Employee* pEmployee;

        pEmployee=malloc(sizeof(Employee));

        return pEmployee;
}

/** \brief Employee constructor - Calls function to allocate memory for employee structure and assigns values to fields
 *
 * \param idStr char* field parsed from txt
 * \param nombreStr char* field parsed from txt
 * \param horasTrabajadasStr char* field parsed from txt
 * \param sueldoStr char* field parsed from txt
 * \return Employee* returns pointer to structure loaded with parameters
 *
 */
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

/** \brief Set value to field
 *
 * \param this Employee*
 * \param id int
 * \return int
 *
 */
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

/** \brief Get value from structure
 *
 * \param this Employee*
 * \param id int* pointer to variable to store data
 * \return int return 0 if failed or 1 is succeeds
 *
 */
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

/** \brief Set value to field
 *
 * \param this Employee*
 * \param char* nombre
 * \return int
 *
 */
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



/** \brief Get value from structure
 *
 * \param this Employee*
 * \param nombre char* pointer to variable to store data
 * \return int return 0 if failed or 1 is succeeds
 *
 */
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

/** \brief Set value to field
 *
 * \param this Employee*
 * \param int horasTrabajadas
 * \return int
 *
 */
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


/** \brief Get value from structure
 *
 * \param this Employee*
 * \param horasTrabajadas int* pointer to variable to store data
 * \return int return 0 if failed or 1 is succeeds
 *
 */
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

/** \brief Set value to field
 *
 * \param this Employee*
 * \param sueldo int
 * \return int
 *
 */
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

/** \brief Sort Criteria to pointer to function by Name
 *
 * \param e1 void*
 * \param e2 void*
 * \return int returns -1 if e1 is less than e2 1 if e1 is greater than e2 and 0 if both are equal
 *
 */
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

/** \brief Sort Criteria to pointer to function by ID
 *
 * \param e1 void*
 * \param e2 void*
 * \return int returns -1 if e1 is less than e2 1 if e1 is greater than e2 and 0 if both are equal
 *
 */
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

/** \brief Prints message
 *
 * \param message char* String with message
 * \return void
 *
 */
void message_user(char* message)
{
    printf("%s\n",message);
}


/** \brief Evaluates a value returned from a function and prints a message if evaluation fails
 *
 * \param returnStatus int values returned from a function
 * \return void
 *
 */
void returnValidation(int returnStatus)
{
    if (!returnStatus)
    {
        message_user("Error!");
    }
}

/** \brief Locates last used ID and adds the increment parameter to obtain a new ID
 *
 * \param pArrayListEmployee LinkedList*
 * \param increment int step of incremente
 * \return int new id
 *
 */
int GetIncrementalID(LinkedList* pArrayListEmployee ,int increment)
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
