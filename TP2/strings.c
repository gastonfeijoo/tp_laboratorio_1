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
 * \param array to save string
 * \param char * string index on character to save
 * \param char aux the value obtained to save
 * \return int i return index of next element in the string
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
 * \param  index position of string
 * \return returns index position of string minus one (the backspace)
 *
 */
int InputCursorLimit (int i){
putch(8);
i--;
return i;
}

/** \brief Shell-like function to get Strings The SizeString Parameter sets the limit of character user can enter
 *
 * \param string char* the array to save the characters as a string
 * \param sizeString int the size or length of the input
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
 * \return char returns a char
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
 * \param sizeString int length of input o quantity of digits allowed
 * \return int return integer
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

/** \brief Shell-like function to get Floats The SizeString Parameter sets the limit of character user can enter. The dwcimal part is entered with a period
 *
 * \param sizeString int lenght of the input
 * \return float return floating point number
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

