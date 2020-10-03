#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "strings.h"


/** \brief Detects Backspace Key pressed in console and backups cursor
 *
 * \param i int
 * \return int
 *
 */
int InputCursorBackspace(int i){
i--;
printf(" \b\b");
return i;
}

/** \brief Enter character into string
 *
 * \param
 * \param
 * \return
 *
 */
int InputCursorValidCharacter (char * string,int i, char aux){
string[i]=aux;
putch(string[i]);
i++;
return i;
}

/** \brief check limit of cursor for shell like input
 *
 * \param
 * \param
 * \return
 *
 */
int InputCursorLimit (int i){
putch(8);
i--;
return i;
}

/** \brief Shell-like function to get Strings The SizeString Parameter sets the limit of character user can enter
 *
 * \param string char*
 * \param sizeString int
 * \return void
 *
 */
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

/** \brief Shell-like function to get a Character
 *
 * \return char
 *
 */
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


/** \brief Shell-like function to get Integer The SizeString Parameter sets the limit of character user can enter
 *
 * \param sizeString int
 * \return int
 *
 */
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

/** \brief Shell-like function to get Floats The SizeString Parameter sets the limit of character user can enter
 *
 * \param sizeString int
 * \return float
 *
 */
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

