#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>
#include "arithmetic.h"
int main()
{

int userOption;
float firstOperand;
float secondOperand;
float resultAddition;
float resultSubstraction;

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
        printf("Ingrese el primer operando...");
        scanf("%f",&firstOperand);
        system("cls");
        break;

        case 2:
        system("cls");
        printf("Ingrese el segundo operando...");
        scanf("%f",&secondOperand);
        system("cls");
        break;

        case 3:
        system("cls");
        printf("a) Calcular la suma (A+B)\nb) Calcular la resta (A-B)\nc) Calcular la division (A/B)\nd) Calcular la multiplicacion\ne) Calcular el factorial (A*B)\nCalculando");
        Sleep(1000);
        printf(".");
        Sleep(1000);
        printf(".");
        Sleep(1000);
        printf(".\n");

        resultAddition=SumaDosNumeros(firstOperand,secondOperand);
        resultSubstraction=RestaDosNumeros(firstOperand,secondOperand);

        printf("Calculos finalizados...\n");
        Sleep(2000);
        system("cls");
        break;

        case 4:
        system("cls");
        printf("a) El resultado es %.2f\nb) El resultado es %.2f\n",resultAddition,resultSubstraction);
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
