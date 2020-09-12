#include "arithmetic.h"
#include <stdio.h>
#include <math.h>

float AddTwoNumbers(float firstOperand,float secondOperand)
{
float result;

result=firstOperand+secondOperand;

return result;
}

float SubstractTwoNumbers(float firstOperand,float secondOperand)
{
float result;

result=firstOperand-secondOperand;

return result;
}

float MultiplyTwoNumbers(float firstOperand,float secondOperand)
{
float result;

result=firstOperand*secondOperand;

return result;
}

float DivideTwoNumbers(float firstOperand,float secondOperand){
    float result;
    if(secondOperand!=0){
        result = (float)firstOperand/(float)secondOperand;
    }
    else{
        result=0;
    }
    return result;
}

unsigned long int CalculateFactorial(float number){

int i;
unsigned long int result;
//revisa si el numero a calcular el factorial es positivo y no tiene decimal. Retorno 0 si no puede calcular
result=0;
if (number<0 || fmodf(number,1)==0){
    result=number;

    if(number==0)
    {
        result=1;
    }
    else if (number>12)
    {
        result=0;
    }
    else
    {
        for (i=number;i>1;i--)
        {
            result=result*(i-1);
        }
    }
}
return result;
}
