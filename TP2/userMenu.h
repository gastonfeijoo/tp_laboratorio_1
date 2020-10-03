#ifndef USERMENU_H_INCLUDED
#define USERMENU_H_INCLUDED
#include "ArrayEmployees.h"


#endif


int userMenuOption(int optionsNumber,char **optionText,char optionChooseText[],char optionInvalidText[]);
void userMenuOptionsActions();
int GetEmployeeData(Employee * list,int size, int id);
void ModifyEmployeeData(Employee * list,int size);
