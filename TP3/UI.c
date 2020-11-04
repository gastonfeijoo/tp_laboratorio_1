#include <stdlib.h>
#include <stdio.h>
#include "Employee.h"
#include "LinkedList.h"
#include "Controller.h"
#include "utn.h"
#include <string.h>


/** \brief Creates an options menu.
 *
 * \param optionsNumber int number of valid options
 * \param optionText char[] String of menu text
 * \param optionChooseText[] char message to direct the user to select an option
 * \param optionInvalidText[] char message to show if invalid option is selected
 * \return int returns the option selected as integer
 *
 */
int userMenuOption(int optionsNumber, int optionNumberExit, char optionsText[],char optionChooseText[],char optionInvalidText[])
{
    int userOption;

    do
    {
        printf("\n%s\n\n",optionsText);

        printf("%s\n",optionChooseText);

        //cleanStdin();
        scanf("%d",&userOption);

        if (userOption>optionsNumber)
        {
            printf("%s\n",optionInvalidText);

            getchar();
        }

    }while(userOption>optionsNumber && userOption!=optionNumberExit);

    return userOption;
}

/** \brief Takes the user option of a main menu and executes the code for that option
 *
 * \param userOption int user option of a menu
 * \param LinkedList* pArrayListEmployee LinkedList used by cases
 * \param char* pathTxt Path to Data.CSV
 * \param char* pathBin Path to Data.BIN
 * \return void
 *
 */
void MenuMainSwitch(int userOption, LinkedList* pArrayListEmployee, char* pathTxt, char* pathBin)
{
    //FALTAN LOS RETORNOS!!!!!!!!!!!!***********
    int returnLoadTxt;
    int returnLoadBin;
    int returnAdd;
    int returnEdit;
    int returnRemove;
    int returnList;
    int returnSort;
    int returnSaveTxt;
    int returnSaveBin;

    switch(userOption)
    {
    case 1: //Carga csv txt
        returnLoadTxt=controller_loadFromText(pathTxt,pArrayListEmployee);
        if (returnLoadTxt)
        {
            printf("Carga Exitosa\n");
        }
        else
        {
            printf("Carga Fallida\n");
        }
        break;
    case 2: //Carga csv bin
        returnLoadBin=controller_loadFromBinary(pathBin,pArrayListEmployee);
        if (returnLoadBin)
        {
            printf("Carga Exitosa\n");
        }
        else
        {
            printf("Carga Fallida\n");
        }
        break;
    case 3: //alta
        returnAdd=controller_addEmployee(pArrayListEmployee);
        if (returnAdd)
        {
            printf("Carga Exitosa\n");
        }
        else
        {
            printf("Carga Fallida\n");
        }
        break;
    case 4: //modif
        returnEdit=controller_editEmployee(pArrayListEmployee);
        if (returnEdit)
        {
            printf("Modificacion Exitosa\n");
        }
        else
        {
            printf("Modificacion Fallida\n");
        }

        break;
    case 5: //baja
        returnRemove=controller_removeEmployee(pArrayListEmployee);
        if (returnRemove==-1)
        {
            printf("ID no encontrado\n");
        }
        else
        {
            printf("ID eliminado con exito\n");
        }
        break;
    case 6: //listar
        returnList=controller_ListEmployee(pArrayListEmployee);
        if (!returnList)
        {
            printf("Error al listar\n");
        }
        break;
    case 7: //ordenar
        returnSort=controller_sortEmployee(pArrayListEmployee);
        if(returnSort==-1)
        {
            printf("No se pudo ordenar!\n");
        }
        break;
    case 8: //guardar txt
        returnSaveTxt=controller_saveAsText(pathTxt,pArrayListEmployee);
        if (returnSaveTxt)
        {
            printf("Guardado Exitoso\n");
        }
        else
        {
            printf("Guardado Fallido\n");
        }
        break;
    case 9: //guardar bin
        returnSaveBin=controller_saveAsBinary(pathBin,pArrayListEmployee);
        if (returnSaveBin)
        {
            printf("Guardado Exitoso\n");
        }
        else
        {
            printf("Guardado Fallido\n");
        }
        break;
    }
}
