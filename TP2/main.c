#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "strings.h"
#include "userMenu.h"
#define SIZE 1000

//Get Size of Array: *(&nameEmployee+1)-nameEmployee) - https://www.tutorialspoint.com/find-size-of-array-in-c-cplusplus-without-using-sizeof#:~:text=*(a%2B1)%20%3D%3E,End.

int main()
{
    int userOption;
    int userOptionRemove;
    int returnStatus;
    static int id;
    int returnAddEmployee;
    Employee payroll[SIZE];
    id=1;

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
                //system("cls");
                returnAddEmployee=GetEmployeeData(payroll,SIZE,id);
                if(returnAddEmployee==0)
                {
                    id++;
                }
                else
                {
                    printf("Capacidad maxima de empleados alcanzada\n");
                }
                //system("cls");
                break;
            case 2:
                break;
            case 3:
                printf("Ingrese el ID del empleado que desea eliminar\n");
                userOptionRemove=GetNumberInteger(4);
                removeEmployee(payroll,SIZE,userOptionRemove);
                break;
            case 4:
                printEmployees(payroll,SIZE);
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
