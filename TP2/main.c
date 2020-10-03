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
    int returnStatus;
    char  * nameEmployee[50+1];
    char * lastNameEmployee[50+1];
    float salaryEmployee;
    int sectorEmployee;
    static int id;

    int returnAddEmployee;

    id=1;

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
                //system("cls");
                printf("\nIngrese el nombre del empleado:\n");
                GetString(nameEmployee,*(&nameEmployee+1)-nameEmployee);
                printf("\nIngrese el apellido del empleado:\n");
                GetString(lastNameEmployee,*(&lastNameEmployee+1)-lastNameEmployee);
                printf("\nIngrese el salario del empleado:\n");
                salaryEmployee=GetNumberFloat(14);
                printf("\nIngrese el Sector del empleado:\n");
                sectorEmployee=GetNumberInteger(4);
                returnAddEmployee=addEmployee(payroll,SIZE,id,nameEmployee,lastNameEmployee,salaryEmployee,sectorEmployee);
                printf("Status de Agregar %d\n",returnAddEmployee);
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
