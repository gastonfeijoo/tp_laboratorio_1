#ifndef UI_H_INCLUDED
#define UI_H_INCLUDED
#include "LinkedList.h"
int userMenuOption(int optionsNumber, int optionNumberExit, char optionsText[],char optionChooseText[],char optionInvalidText[]);
void MenuMainSwitch(int userOption, LinkedList* pArrayListEmployee, char* pathTxt, char* pathBin);

#endif // UI_H_INCLUDED
