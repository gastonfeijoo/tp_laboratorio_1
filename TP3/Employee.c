#include <stdlib.h>
#include "Employee.h"
#include <string.h>

Employee* employee_new()
{
        Employee* pEmployee;

        pEmployee=malloc(sizeof(Employee));

        return pEmployee;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* pEmployee;

    pEmployee=employee_new();

    if (pEmployee!=NULL)
    {

    }
}
