#include "Structures.h"
#define EMPTY 1
#define FULL 0

/** \brief Check if a structure is empty
 *
 * \param
 * \param
 * \return
 *
 */
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

/** \brief Sort structure by isempty element. Puts full elements first and return record count
 *
 * \param list Employee*
 * \param len int
 * \return int
 *
 */
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

