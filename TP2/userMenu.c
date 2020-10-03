#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include "userMenu.h"
#include "strings.h"

/** \brief Creates an options menu.
 *
 * \param optionsNumber int number of options to display
 * \param optionText char** multidimensional array for storing options text. must declared like so
            char * userMenuOptions[5][30]={{"ALTAS","MODIFICAR","BAJA","INFORMAR","SALIR"}};
 * \param optionChooseText[] char message to direct the user to select an option
 * \param optionInvalidText[] char message to show if invalid option is selected
 * \return int returns the option selected as integer
 *
 */
int userMenuOption(int optionsNumber,char **optionText,char optionChooseText[],char optionInvalidText[])
{
    int userOption;
    int i;
    int optionMemAddress;

    do
    {
    for(i=0;i<optionsNumber;i++)
    {
        optionMemAddress=&optionText[i][0];

        printf("%d - %s\n",i+1,optionMemAddress);
    }

    printf("%s\n",optionChooseText);

        userOption=getch()-'0';

        if (userOption>optionsNumber)
        {
            printf("%s\n",optionInvalidText);
            sleep(1);
        }
            system("cls");
    }while(userOption>optionsNumber);

    return userOption;
}

/** \brief Input for Structure Elements
 *
 * \param list Employee* Structure array to load
 * \param size int size of the array
 * \param id int PK element
 * \return int returns value from addEmployee() function
 *
 */
int GetEmployeeData(Employee * list,int size, int id)
{
    char * nameEmployee[50+1];
    char * lastNameEmployee[50+1];
    float salaryEmployee;
    int sectorEmployee;
    int returnStatus;


    printf("\nIngrese el nombre del empleado:\n");
    GetString(nameEmployee,*(&nameEmployee+1)-nameEmployee);
    printf("\nIngrese el apellido del empleado:\n");
    GetString(lastNameEmployee,*(&lastNameEmployee+1)-lastNameEmployee);
    printf("\nIngrese el salario del empleado:\n");
    salaryEmployee=GetNumberFloat(14);
    printf("\nIngrese el Sector del empleado:\n");
    sectorEmployee=GetNumberInteger(4);

    returnStatus=addEmployee(list,size,id,nameEmployee,lastNameEmployee,salaryEmployee,sectorEmployee);
    return returnStatus;
}

/** \brief Modifies values in structure elements
 *
 * \param list Employee* Structure array to modfiy elements
 * \param size int size of array
 * \param id int pk field
 * \return void
 *
 */
void ModifyEmployeeData(Employee * list,int size,int id)
{
    int userOption;
    char * nameEmployee[50+1];
    char * lastNameEmployee[50+1];
    float salaryEmployee;
    int sectorEmployee;
    int returnStatus;
    char * userMenuOptions[5][30]={{"NOMBRE","APELLIDO","SUELDO","SECTOR","VOLVER"}};
    printf("\nSeleccione el campo a modificar\n");
    do
    {
        userOption=userMenuOption(5,*userMenuOptions,"Elija una opcion...","Opcion Invalida...");
        switch(userOption)
        {
        case 1:
            printf("El nombre actual es : %s\n",list[findEmployeeById(list,size,id)].name);
            printf("\nIngrese el nuevo nombre del empleado:\n");
            GetString(nameEmployee,*(&nameEmployee+1)-nameEmployee);
            strcpy(list[findEmployeeById(list,size,id)].name,nameEmployee);
            PressAnyKey();
            break;
        case 2:
            printf("El apellido actual es : %s\n",list[findEmployeeById(list,size,id)].lastName);
            printf("\nIngrese el nuevo apellido del empleado:\n");
            GetString(nameEmployee,*(&nameEmployee+1)-nameEmployee);
            strcpy(list[findEmployeeById(list,size,id)].lastName,nameEmployee);
            PressAnyKey();
            break;
        case 3:
            printf("El sueldo actual es : %.2f\n",list[findEmployeeById(list,size,id)].salary);
            printf("\nIngrese el nuevo sueldo del empleado:\n");
            salaryEmployee=GetNumberFloat(14);
            list[findEmployeeById(list,size,id)].salary=salaryEmployee;
            PressAnyKey();
            break;
        case 4:
            printf("El sector actual es : %d\n",list[findEmployeeById(list,size,id)].sector);
            printf("\nIngrese el nuevo sector del empleado:\n");
            sectorEmployee=GetNumberFloat(14);
            list[findEmployeeById(list,size,id)].sector=sectorEmployee;
            PressAnyKey();
            break;
        case 5:
            break;
        }
    }while(userOption!=5);
}

/** \brief a simple press any key to continue
 *
 * \return void
 *
 */
void PressAnyKey()
{
printf("\nPresione cualquier tecla para continuar\n");
getch();
system("cls");
}
