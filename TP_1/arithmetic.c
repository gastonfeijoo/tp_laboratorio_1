#include "arithmetic.h"
#include <stdio.h>

float SumaDosNumeros(float firstOperand,float secondOperand)
{
int result;

result=firstOperand+secondOperand;

return result;
}

float RestaDosNumeros(float firstOperand,float secondOperand)
{
int result;

result=firstOperand-secondOperand;

return result;
}

float MultiplicacionDosNumeros(float firstOperand,float secondOperand)
{
int result;

result=firstOperand*secondOperand;

return result;
}

float DivideDosNumeros(float firstOperand,float secondOperand){
    float result;
    if(secondOperand!=0){
        result = (float)firstOperand/(float)secondOperand;
    }
    else{
        printf("No se puede dividir por 0");
        result=0;
    }
    return result;
}

unsigned long long int CalculaFactorial(float number){

int i;
unsigned long long int result;

result=number;

if(number==0){
    result=1;
}
else{
    for (i=number;i>1;i--){
        result=result*(i-1);
    }

}
return result;
}
