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
