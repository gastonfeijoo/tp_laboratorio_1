#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "strings.h"
#include "userMenu.h"
#include "Structures.h"
#define SIZE 1000

//Get Size of Array: *(&nameEmployee+1)-nameEmployee) - https://www.tutorialspoint.com/find-size-of-array-in-c-cplusplus-without-using-sizeof#:~:text=*(a%2B1)%20%3D%3E,End.

int main()
{
    int userOption;
    int userOptionRemove;
    int userOptionModify;
    int returnStatus;
    int payrollHasRecords;
    static int id;
    int returnAddEmployee;
    Employee payroll[SIZE];
    char * userMenuOptions[5][30]={{"ALTAS","MODIFICAR","BAJA","INFORMAR","SALIR"}};
    id=1;
    payrollHasRecords=0;

    returnStatus=initEmployees(payroll,SIZE);
    if (returnStatus==0)
    {
        //usa doble llave por el bug GCC bug 53119 ref: https://gcc.gnu.org/bugzilla/show_bug.cgi?id=53119
        do
        {
            printf("MENU PRINCIPAL\n\n");
            userOption=userMenuOption(5,*userMenuOptions,"Elija una opcion...","Opcion Invalida...");
            payrollHasRecords=CheckStructureIsEmpty(payroll,SIZE);
            if (payrollHasRecords==0 || (payrollHasRecords==-1 && (userOption==1 || userOption==5)))
            {
                switch(userOption)
                {
                case 1:
                    system("cls");
                    returnAddEmployee=GetEmployeeData(payroll,SIZE,id);
                    if(returnAddEmployee==0)
                    {
                        id++;
                    }
                    else
                    {
                        printf("Capacidad maxima de empleados alcanzada\n");
                    }
                    PressAnyKey();
                    break;
                case 2:
                    printf("Ingrese el ID del empleado que desea modificar\n");
                    userOptionModify=GetNumberInteger(4);
                    ModifyEmployeeData(payroll,SIZE,userOptionModify);
                    break;
                case 3:
                    printf("Ingrese el ID del empleado que desea eliminar\n");
                    userOptionRemove=GetNumberInteger(4);
                    removeEmployee(payroll,SIZE,userOptionRemove);
                    PressAnyKey();
                    break;
                case 4:
                    printEmployees(payroll,SIZE);
                    PressAnyKey();
                    break;
                case 5:
                    break;
                }
            }
            else if (userOption>1 || userOption<5)
            {
                printf("Opcion Invalida, no hay empleados en la nomina\n");
                PressAnyKey();
            }
        }while(userOption!=5);
    }
    else
    {
        printf("Tamaño de la estructura invalida");
    }
        return 0;
}
