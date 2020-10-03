#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "strings.h"


int InputCursorBackspace(int i){
i--;
printf(" \b\b");
return i;
}

int InputCursorValidCharacter (char * string,int i, char aux){
string[i]=aux;
putch(string[i]);
i++;
return i;
}

int InputCursorLimit (int i){
putch(8);
i--;
return i;
}

void GetString(char *string, int sizeString){

    int i;
    char aux;
    i=0;

    while(i<sizeString-1)
    {
        aux=getch();
        if (i>0 && aux==8)
        {
            i=InputCursorBackspace(i);
        }
        else
        {
            if(aux>31)
            {
                i=InputCursorValidCharacter(string,i,aux);
            }
        }
        if (aux==13)
        {
            break;
        }
        if (i==sizeString-1)
        {
            i=InputCursorLimit(i);
        }
    }
    string[i]='\0';
    strdup(&string[0]);
}

char GetCharacter(){
    char aux;
    char returnValue;
    int i;
    i=0;
    while(i<1)
    {
        aux=getch();
        if (i>0 && aux==8)
        {
            i=InputCursorBackspace(i);
        }
        else
        {
            if(aux>31)
            {
                putch(aux);
                returnValue=aux;
                i++;
            }
        }
        if (aux==13)
        {
            break;
        }
        if (i==1)
        {
            i=InputCursorLimit(i);
        }
    }
    return returnValue;
}


int GetNumberInteger(int sizeString){
    int i;
    char string[sizeString];
    char aux;
    i=0;

    while(i<=sizeString)
    {
        aux=getch();
        if (i>0 && aux==8)
        {
            i=InputCursorBackspace(i);
        }
        else
        {

            if(isdigit((int)aux) && aux>31)
            {
                i=InputCursorValidCharacter(string,i,aux);
            }
        }
        if (aux==13)
        {
            break;
        }
        if (i==sizeString)
        {
            i=InputCursorLimit(i);
        }
    }
    return atoi(string);
}

float GetNumberFloat(int sizeString){
    int i;
    char string[sizeString];
    char aux;
    i=0;

    while(i<=sizeString)
    {
        aux=getch();
        if (i>0 && aux==8)
        {
            i=InputCursorBackspace(i);
        }
        else
        {

            if( ( isdigit((int)aux) || aux==46 ) && aux>31)
            {
                i=InputCursorValidCharacter(string,i,aux);
            }
        }
        if (aux==13)
        {
            break;
        }
        if (i==sizeString)
        {
            i=InputCursorLimit(i);
        }
    }
    return atof(string);
}

