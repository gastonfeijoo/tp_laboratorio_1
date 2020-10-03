#include "Structures.h"
#define EMPTY 1
#define FULL 0

int CheckStructureIsEmpty (Employee * list, int size)
{
    int i;
    int returnStatus;
    returnStatus=-1;

    for (i=0;i<size;i++)
    {
        if (list[i].isEmpty==FULL)
        {
        returnStatus=0;
        }
    }
    return returnStatus;
}

int sortStructureFullElements(Employee* list, int len)
{

    Employee aux;
    int returnStatus;

    returnStatus=0;
    int i;
    int j;

    for (i=0;i<len-1;i++)
    {
        for (j=1;j<len;j++)
        {
            if (list[i].isEmpty<list[j].isEmpty)
            {
                aux=list[j];
                list[j]=list[i];
                list[j]=aux;
            }
        }
        if(list[i].isEmpty==0)
        {
            returnStatus++;
        }
    }
    return returnStatus;

}

