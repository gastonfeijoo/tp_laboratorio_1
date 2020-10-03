#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include "userMenu.h"
#include "strings.h"

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
            system("cls");
        }
    }while(userOption>optionsNumber);

    return userOption;
}

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
