#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "strings.h"
#include "userMenu.h"
#define SIZE 1000
int main()
{
    int userOption;
    int returnStatus;

    char * string[10+1];
    int integer;
    float floating;

    Employee payroll[SIZE];
    returnStatus=initEmployees(payroll,SIZE);
    if (returnStatus==0)
    {
        //usa doble llave por el bug GCC bug 53119 ref: https://gcc.gnu.org/bugzilla/show_bug.cgi?id=53119
        char * userMenuOptions[5][30]={{"ALTAS","MODIFICAR","BAJA","INFORMAR","SALIR"}};
        do
        {
            userOption=userMenuOption(5,*userMenuOptions,"Elija una opcion...","Opcion Invalida...");
            switch(userOption)
            {
            case 1:

                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            }
        }while(userOption!=5);
    }
    else
    {
        printf("Tamaño de la estructura invalida");
    }
        return 0;
}
