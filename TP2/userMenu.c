#include "userMenu.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

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
