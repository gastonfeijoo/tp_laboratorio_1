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
    string[i+1]='\0';
    strdup(&string[0]);
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


/* funciona
void GetString(char *string, int sizeString){

    int i;
    char aux;
    i=0;

    while(i<sizeString-1)
    {
        aux=getch();
        if (i>0 && aux==8)
        {
            //function backspace
            i--;
            printf(" \b\b");
            //
        }
        else
        {
            if(aux>31)
            {
                //function validCharacter
                string[i]=aux;
                putch(string[i]);
                i++;
                //
            }
        }
        if (aux==13)
        {
            break;
        }
        if (i==sizeString-1)
        {
            //function inputlimit
            putch(8);
            i--;
            //
        }
    }
    string[i+1]='\0';
    strdup(&string[0]);
}

int GetNumberInteger(int sizeString){
    //char string[sizeString];

    int i;
    char string[sizeString];
    char aux;
    i=0;

    while(i<=sizeString)
    {
        aux=getch();
        if (i>0 && aux==8)
        {
            i--;
            printf(" \b\b");

        }
        else
        {

            if(isdigit((int)aux) && aux>31)
            {
                string[i]=aux;
                putch(string[i]);
                i++;
            }
        }
        if (aux==13)
        {
            break;
        }
        if (i==sizeString)
        {
            putch(8);
            i--;
        }
    }
    return atoi(string);
}

float GetNumberFloat(int sizeString){
    //char string[sizeString];

    int i;
    char string[sizeString];
    char aux;
    i=0;

    while(i<=sizeString)
    {
        aux=getch();
        if (i>0 && aux==8)
        {
            i--;
            printf(" \b\b");

        }
        else
        {

            if( ( isdigit((int)aux) || aux==46 ) && aux>31)
            {
                string[i]=aux;
                putch(string[i]);
                i++;
            }
        }
        if (aux==13)
        {
            break;
        }
        if (i==sizeString)
        {
            putch(8);
            i--;
        }
    }
    return atof(string);
}
*/
