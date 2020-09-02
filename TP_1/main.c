#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include "arithmetic.h"
int main()
{

int userOption;
float firstOperand;
float secondOperand;

firstOperand=0;
secondOperand=0;

do
{
    printf("1. Ingresar 1. Ingresar 1er operando (A=%.2f)\n2. Ingresar 2do Operando(B=%.2f)\n3. Calcular todas las operaciones\n4. Informar resultados\n5. Salir\n\n",firstOperand,secondOperand);
    scanf("%d",&userOption);
    fflush(stdin);
    if (userOption<1 || userOption>6)
    {
        system("cls");
        printf("Opcion Invalida\nPresione cualquier tecla para volver al menu principal...");
        getch();
        system("cls");
    }
    switch(userOption)
    {
        case 1:
        system("cls");
        printf("Opcion 1\nPresione cualquier tecla para volver al menu principal...");
        getch();
        system("cls");
        break;

        case 2:
        system("cls");
        printf("Opcion 2\nPresione cualquier tecla para volver al menu principal...");
        getch();
        system("cls");
        break;

        case 3:
        system("cls");
        printf("Opcion 3\nPresione cualquier tecla para volver al menu principal...");
        getch();
        system("cls");
        break;

        case 4:
        system("cls");
        printf("Opcion 4\nPresione cualquier tecla para volver al menu principal...");
        getch();
        system("cls");
        break;

        case 5:
        system("cls");
        printf("Gracias por su cooperacion...");
        break;
    }
} while (userOption!=5);

/*
system("cls");
printf("Presione cualquier tecla para continuar...");
getch();
*/
}
