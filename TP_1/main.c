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
float resultMultiplication;
float resultDivision;
unsigned long resultFactorialFirstOperand;
unsigned long resultFactorialSecondOperand;

int operandOneEnteredFlag;
int operandTwoEnteredFlag;
int resultsCalculated;

//inicializo variables
firstOperand=0;
secondOperand=0;

//inicializo banderas y contadores
operandOneEnteredFlag=0;
operandTwoEnteredFlag=0;
resultsCalculated=0;

do

{ //validar ingreso datos!!

    //menu de usuario y seleccion de opcion
    if (operandOneEnteredFlag && !operandTwoEnteredFlag){
        printf("1. Ingresar 1. Ingresar 1er operando (A=%.2f)\n2. Ingresar 2do Operando(B=X)\n",firstOperand);
    }
    else if (!operandOneEnteredFlag && operandTwoEnteredFlag){
        printf("1. Ingresar 1. Ingresar 1er operando (A=X)\n2. Ingresar 2do Operando(B=%.2f)\n",secondOperand);
    }
    else if (operandOneEnteredFlag && operandTwoEnteredFlag){
        printf("1. Ingresar 1. Ingresar 1er operando (A=%.2f)\n2. Ingresar 2do Operando(B=%.2f)\n",firstOperand,secondOperand);
    }
    else
    {
        printf("1. Ingresar 1. Ingresar 1er operando (A=X)\n2. Ingresar 2do Operando(B=X)\n");
    }

    //opciones 3 a 5 del menu
    printf("3. Calcular todas las operaciones\n4. Informar resultados\n5. Salir\n");
    scanf("%d",&userOption);
    fflush(stdin);

//valido la opcion elegida
    if (userOption<1 || userOption>6)
    {
        system("cls");
        printf("Opcion Invalida\nPresione cualquier tecla para volver al menu principal...");
        getch();
        system("cls");
    }
    // que hace el prg en cada opcion
    switch(userOption)
    {
        //Opcion 1  - Ingresa el primer operando
        case 1:
        system("cls");
        printf("Ingrese el primer operando...");
        scanf("%f",&firstOperand);
        operandOneEnteredFlag=1;
        system("cls");
        break;
        //Opcion 2  - Ingresa el Segundo operando
        case 2:
        system("cls");
        printf("Ingrese el segundo operando...");
        scanf("%f",&secondOperand);
        operandTwoEnteredFlag=1;
        system("cls");
        break;
        //Opcion 3  - Hace los calculos
        case 3:
        system("cls");
        if (operandOneEnteredFlag&&operandTwoEnteredFlag){
            printf("a) Calcular la suma (A+B)\nb) Calcular la resta (A-B)\nc) Calcular la division (A/B)\nd) Calcular la multiplicacion\ne) Calcular el factorial (A*B)\nCalculando");
            resultAddition=SumaDosNumeros(firstOperand,secondOperand);
            resultSubstraction=RestaDosNumeros(firstOperand,secondOperand);
            resultMultiplication=MultiplicacionDosNumeros(firstOperand,secondOperand);
            resultDivision=DivideDosNumeros(firstOperand,secondOperand);
            resultFactorialFirstOperand=CalculaFactorial(firstOperand);
            resultFactorialSecondOperand=CalculaFactorial(secondOperand);
            resultsCalculated=1;
            printf("\nCalculos finalizados...\n");
            Sleep(1000);
        }
        else{
            printf("Faltan Ingresar un operando.\nPresione cualquier tecla para regresar el menu principal");
            getch();
        }
        system("cls");
        break;
        //Opcion 4  - Muestra los resultados
        case 4:
        system("cls");
        if (resultsCalculated==1)
        {
            printf("a) El resultado de la suma es %.2f\nb) El resultado de la resta es %.2f\n",resultAddition,resultSubstraction);
            if (resultDivision!=0){
                printf("c) El resultado de la division es %.2f\n",resultDivision);
            }
            else
            {
                printf("c) No se puede dividir por cero\n");
            }
            printf("d) El resultado de la multiplicacion %.2f\n",resultMultiplication);
            //controla el maximo numero que puede calcular el factorial
            if (firstOperand>12 || resultFactorialFirstOperand==0){
                printf("e) El factorial de %.2f no se puede calcular",firstOperand);
            }
            else
            {
                printf("e) El factorial de %.2f es %lu",firstOperand,resultFactorialFirstOperand);
            }
            if (secondOperand>12||resultFactorialSecondOperand==0)
            {
                printf(" y El factorial de %.2f no se puede calcular",secondOperand);
            }
            else
            {
                printf(" y el factorial de %.2f es %lu",secondOperand,resultFactorialSecondOperand);
            }

        }
        else
        {
            printf("No se elegido la opcion de realizar los calculos...");
        }
        printf("\npresione cualquier tecla para continuar...");
        getch();
        system("cls");
        break;
        //Opcion 5  - Sale del programa
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
