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
 * \param entity1[] eMascotas array used by cases
 * \param entity2[] eRazas array used by cases
 * \param size1 int size of eMascotas Array
 * \param size2 int size of eRazas Array
 * \return void
 *
 */
void MenuMainSwitch(int userOption, LinkedList* pArrayListEmployee, char* pathTxt, char* pathBin)
{

    switch(userOption)
    {
    case 1: //Carga csv txt
        controller_loadFromText(pathTxt,pArrayListEmployee);
        break;
    case 2: //Carga csv bin
        controller_loadFromBinary(pathBin,pArrayListEmployee);
        break;
    case 3: //alta

        break;
    case 4: //modif

        break;
    case 5: //baja

        break;
    case 6: //listar
        controller_ListEmployee(pArrayListEmployee);
        break;
    case 7: //ordenar
        controller_sortEmployee(pArrayListEmployee);
        break;
    case 8: //guardar txt
        controller_saveAsText(pathTxt,pArrayListEmployee);
        break;
    case 9: //guardar bin
        controller_saveAsBinary(pathBin,pArrayListEmployee);
        break;
    }
}
