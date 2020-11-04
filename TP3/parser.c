#include <stdio.h>
#include <stdlib.h>
#include "UI.h"
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/** \brief reads a TXT file with CSV format and add values to structure. Requests the user to indicate if CSV has header row
 *
 * \param pFile FILE* pointer to file
 * \param pArrayListEmployee LinkedList*  linked list to load
 * \return int return 0 if fails to read and save and 1 if succeeds
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    //probar

    char id[100];
    char nombre[100];
    char horasTrabajadas[100];
    char sueldo[100];
    int rFscanF;
    int returnLlAdd;
    int returnStatus;

    returnStatus=0;
    //elimino encabezados
    if (parser_HasHeader())
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas,sueldo);
    }
    while(!feof(pFile))
    {
        rFscanF=fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas,sueldo);
        //printf("encabezado %s %s %s %s\n",id, nombre, horasTrabajadas,sueldo);//DEBUG
        if (rFscanF==4)
        {
            Employee* pAux = employee_new(); //<-----lo deberia sacar de la estructura iterativa???
            pAux=employee_newParametros(id,nombre,horasTrabajadas,sueldo);
            returnLlAdd=ll_add(pArrayListEmployee,pAux);

            if (returnLlAdd!=0)
            {
                returnStatus=0;
                break;
            }

            returnStatus=1;
        }
        else
        {
            break;
        }
    }

    return returnStatus;

}

/** \brief reads a Binary file and add values to structure
 *
 * \param pFile FILE* FILE* pointer to file
 * \param pArrayListEmployee LinkedList* linked list to load
 * \return int return 0 if fails to read and save and 1 if succeeds
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{

    int rFread;
    int returnStatus;
    int returnLlAdd;
    returnStatus=0;

    while(!feof(pFile))
    {
        Employee* pAux = employee_new();
        rFread=fread(pAux,sizeof(Employee),1,pFile);
        if (rFread==1)
        {
            returnLlAdd=ll_add(pArrayListEmployee,pAux);

            if (returnLlAdd!=0)
            {
                returnStatus=0;
                break;
            }
        }
        else
        {
            break;
        }
    }


    fclose(pFile);


    return returnStatus;
}
/** \brief Request the user to indicate if file has header row
 *
 * \return returns 0 if file doesn't have a header row. 1 if it does.
 *
 */

int parser_HasHeader()
{
    int returnHeader;

    returnHeader=userMenuOption(2,0,"El archivo CSV tiene encabezado?\n1. Si\n2. No\n0. Salir\n","Elija una opcion...","Opcion Invalida...");
    if (returnHeader==2)
    {
        returnHeader=0;
    }
    return returnHeader;
}
