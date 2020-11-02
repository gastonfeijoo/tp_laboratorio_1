#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "initStructures.h"
#include "relationshipStructures.h"
#include "functions.h"
#include "utn.h"

//DEFINE logical delete
#define EMPTY 1
#define FULL 0

/*DEFINE VALIDATIONS*/
#define SIZEVALTIPO 3
#define SIZEVALSEXO 2
#define SIZEVALTAMANIO 3


/*****************EMASCOTA*******************/

/** \brief Returns incremented ID from eMascotas structure
 *
 * \param eMascotas entity1[], structure array
 * \param int size1, size of array
 * \param int increment, step value of the increment in ID
 * \return int Incremented ID value
 *
 */
int GetIncrementalID (LinkedList* pArrayListEmployee,int increment)
{
    //usar ll_sort //armar criterios sort
    //sortStructurePetsById(entity1,size1,1);
    return entity1[0].codigo+increment;
}

/** \brief Ask the user for input the values of the field for create a new record
 *
 * \param entity[] eMascotas array to load new record
 * \param entity2[] eRazas array with breeds to validate breed field
 * \param size int size of array
 * \param size2 int size of array
 * \return int -1 if no space is available 0 if successful load
 *
 */
int employeeGetData(LinkedList* pArrayListEmployee)
{
    /*
    //Variables de los elementos //
    eMascotas aux;

    int returnStatus;
    int isValidTipo;
    int isValidSexo;


    getString("\nIngrese el nombre de la mascota: ",aux.nombre);

    aux.edad=getInt("\nIngrese la edad de la mascota: ");

    do
    {
        getString("\nIngrese el tipo de la mascota: ",aux.tipo);
        isValidTipo=ValidateStringTipo(aux.tipo,1);
    }while(isValidTipo==-1);

    do
    {
    aux.sexo=toupper(getChar("\nIngrese el sexo de la mascota (m/f): "));
        isValidSexo=ValidateCharSexo(aux.sexo,1);
    }while(isValidSexo==-1);

    aux.peso=getInt("\nIngrese el peso de la mascota: ");
    printf("Razas disponibles\n");
    PrintStructureBreeds(entity2,size2);
    aux.idRaza=getValidInt("\nIngrese el Id de la Raza:\n ","Opcion Invalida",1,LoadedRecordsStructureBreeds(entity2,size2));
    returnStatus=addDataStructurePets(entity,aux,size);
    return returnStatus;
    */
}


/** \brief Displays a Menu to select the field to modify
 *
 * \param entity1[] eMascotas Array with record to modify
  * \param size1 int Size of eMascotas array
 * \param size2 int Size of eRazas array
 * \param id int ID value to seek and modify
 * \return void
 *
 */
void employeeModifyStructDataPets(LinkedList* pArrayListEmployee)
{
    /*
    //INICIALIZO ESTRUCTURA PARA ALMACENAR MODIFICACIONES

    eMascotas aux;

    int userOption;
    int indexToModify;
    indexToModify=findInStructByIdPets(entity1,size1,id);

    if (indexToModify>0)
    {

        printf("\nSeleccione el campo a modificar\n");
        do
        {
            userOption=userMenuOption(6,0,"\n1. Nombre\n2. Edad\n3. Tipo\n4. Sexo\n5. Peso\n6. Raza\n0. Salir","Elija una opcion...","Opcion Invalida...");
            switch(userOption)
            {
            case 1: //nombre
                printf("El nombre actual es : %s\n",entity1[indexToModify].nombre);
                getString("\nIngrese el nuevo nombre de la mascota:\n",aux.nombre);
                strcpy(entity1[indexToModify].nombre,aux.nombre);
                break;
            case 2: //edad
                printf("La edad actual es : %d\n",entity1[indexToModify].edad);
                aux.edad=getInt("\nIngrese la de la mascota:\n");
                entity1[indexToModify].edad=aux.edad;
                break;
            case 3: //tipo
                printf("El tipo actual es : %s\n",entity1[indexToModify].tipo);
                getString("\nIngrese el nuevo tipo de la mascota:\n",aux.tipo);
                strcpy(entity1[indexToModify].tipo,aux.tipo);
                break;
            case 4: // sexo
                printf("El sexo actual es : %c\n",entity1[indexToModify].sexo);
                aux.sexo=toupper(getChar("\nIngrese el sexo de la mascota (m/f): "));
                entity1[indexToModify].sexo=aux.sexo;
                break;
            case 5: //peso
                printf("El peso actual es : %d\n",entity1[indexToModify].peso);
                aux.peso=getInt("\nIngrese el peso de la mascota: ");
                entity1[indexToModify].peso=aux.peso;
                break;
            case 6: //raza
                printf("Listado de Razas disponibles\n");
                PrintStructureBreeds(entity2,size2);
                printf("El codigo de raza actual es : %d\n",entity1[indexToModify].idRaza);
                aux.idRaza=getValidInt("\nIngrese el Id de la Raza:\n ","Opcion Invalida",1,LoadedRecordsStructureBreeds(entity2,size2));
                entity1[indexToModify].idRaza=aux.idRaza;
                break;
            case 0:
                break;

            }
        }while(userOption!=0);
    }
    else
    {
        printf("No se encuentra el ID\n");
    }
    */
}
/** \brief Seeks and marks as deleted the record with ID provided
 *
 * \param entity[] eMascotas Array to seek
 * \param size int size of array
 * \param id int ID to seek and delete
 * \return int -1 if record not found, 0 if record deleted successfully
 *
 */
int removeRecordStructureByIdPets(eMascotas entity[], int size, int id)
{
    int idIndexPosition;
    int returnStatus;
    char userOption;
    idIndexPosition=findInStructByIdPets(entity,size,id); //funcion encontrar por ID
    if (idIndexPosition!=-1)
    {
        do
        {
            userOption=getChar("\nEsta seguro de eliminar el registro? S/N \n");
            userOption=toupper(userOption);
            if (userOption=='S')
            {
                entity[idIndexPosition].isEmpty=EMPTY;
                returnStatus=0;
            }
        }while(userOption!='S' && userOption!='N');
    }
    else
    {
        printf("\nID no Encontrado\n");
        returnStatus=-1;
    }

    return returnStatus;
}

/** \brief Print to console the code and name of all pets loaded
 *
 * \param entity1[] eMascotas array to print
 * \param size1 int size of array
 * \return void
 *
 */
void PrintStructurePets(eMascotas entity1[], int size1)
{
    int i;
    i=0;

    printf("Codigo\tNombre\n");

    for(i=0;i<size1;i++)
    {
        if (entity1[i].isEmpty==FULL)
        {
            printf("%-4d\t%-20s\n",entity1[i].codigo,entity1[i].nombre);
        }
    }
}
/** \brief Prints loaded pets sorted by weight
 *
 * \param entity1[] eMascotas array to print
 * \param size1 int size of array
 * \param order int 0 if ascending order - 1 if descending order
 * \return void
 *
 */
void PrintStructurePetsByWeight(eMascotas entity1[], int size1, int order)
{
    int i;
    i=0;

    if (LoadedRecordsStructurePets(entity1,size1)>0)
    {
        sortStructurePetsByWeight(entity1,size1,order);
        printf("Codigo\tNombre\t\t\tPeso\n");

        for(i=0;i<size1;i++)
        {
            if (entity1[i].isEmpty==FULL)
            {
                printf("%-4d\t%-20s\t%-4d\n",entity1[i].codigo,entity1[i].nombre,entity1[i].peso);
            }
        }
    }
    else
    {
        printf("No hay mascotas cargadas");
    }
}
/** \brief Sort array with loaded record on top
 *
 * \param entity[] eMascotas array to sort
 * \param size int size of array
 * \return int return empty records count
 *
 */
int sortStructureFullElementsPets(eMascotas entity[], int size)
{

    eMascotas aux;
    int returnStatus;

    returnStatus=0;
    int i;
    int j;

    for (i=0;i<size-1;i++)
    {
        for (j=1;j<size;j++)
        {
            if (entity[i].isEmpty<entity[j].isEmpty)
            {
                aux=entity[j];
                entity[j]=entity[i];
                entity[j]=aux;
            }
        }
        if(entity[i].isEmpty==0)
        {
            returnStatus++;
        }
    }
    return returnStatus;

}
/** \brief sort array by id field
 *
 * \param entity[] eMascotas array to sort
 * \param size int size of array
 * \param order int 0 if ascending order - 1 if descending order
 * \return void
 *
 */
void sortStructurePetsById(eMascotas entity[], int size, int order)
{

eMascotas aux;

int recordCount;
int i;
int j;

recordCount=sortStructureFullElementsPets(entity,size);


for (i=0;i<recordCount-1;i++)
{
    for (j=i+1;j<recordCount;j++)
    {
        if (entity[i].codigo>entity[j].codigo && order==0)
        {
            aux=entity[i];
            entity[i]=entity[j];
            entity[j]=aux;
        }
        else if(entity[i].codigo<entity[j].codigo && order==1)
        {
            aux=entity[i];
            entity[i]=entity[j];
            entity[j]=aux;
        }
    }
}
// ordena strings   if (strcmp(entity[i].codigo,entity[j].codigo)>0)


}
/** \brief sort array by weight field
 *
 * \param entity[] eMascotas array to sort
 * \param size int size of array
 * \param order int 0 if ascending order - 1 if descending order
 * \return void
 *
 */
void sortStructurePetsByWeight(eMascotas entity[], int size, int order)
{

eMascotas aux;

int recordCount;
int i;
int j;

recordCount=sortStructureFullElementsPets(entity,size);


for (i=0;i<recordCount-1;i++)
{
    for (j=i+1;j<recordCount;j++)
    {
        if (entity[i].peso>entity[j].peso && order==0)
        {
            aux=entity[i];
            entity[i]=entity[j];
            entity[j]=aux;
        }
        else if(entity[i].peso<entity[j].peso && order==1)
        {
            aux=entity[i];
            entity[i]=entity[j];
            entity[j]=aux;
        }
    }
}
// ordena strings    if (strcmp(entity[i].codigo,entity[j].codigo)>0)


}


/*****************ERAZA*******************/

/** \brief Returns incremented ID from eRazas structure
 *
 * \param eRazas entity1[], structure array
 * \param int size1, size of array
 * \param int increment, step value of the increment in ID
 * \return int Incremented ID value
 *
 */
int GetIncrementalIDBreeds (eRazas entity1[], int size1,int increment)
{
    sortStructureBreedsById(entity1,size1,1);
    return entity1[0].idRaza+increment;
}
/** \brief Ask the user for input the values of the field for create a new record
 *
 * \param entity[] eRazas array to load new record
 * \param size int size of array
 * \return int -1 if no space is available 0 if successful load
 *
 */
int GetDataForBreeds(eRazas entity[],ePais entity2[], int size,int size2)
{
    //Variables de los elementos //
    eRazas aux;

    int returnStatus;
    int isValidTamanio;

    getString("\nIngrese la descripcion de la raza: ",aux.descripcion);

    do
    {
    getString("\nIngrese el tamanio de la raza: ",aux.tamanio);
        isValidTamanio=ValidateStringTamanio(aux.tamanio,1);
    }while(isValidTamanio==-1);

    printf("Listado de paises disponibles\n");
    PrintStructureCountry(entity2,size2);
    getString("\nIngrese el pais de origen de la raza: ",aux.paisOrigen);

    returnStatus=addDataStructureBreeds(entity,aux,size);
    return returnStatus;
}

/** \brief adds user input of data to structure if space is available
 *
 * \param entity[] eRazas array to load
 * \param aux eRazas structure with data entered by user
 * \param size int size of array
 * \return int -1 if no space is available 0 if successful load
 *
 */
int addDataStructureBreeds(eRazas entity[],eRazas aux,int size)
{
    int i;
    int returnStatus;

    returnStatus=-1;

    for(i=0;i<size;i++)
    {
        if (entity[i].isEmpty==EMPTY)
        {

            entity[i].idRaza=GetIncrementalIDBreeds(entity,size,1); //id mascota
            strcpy(entity[i].descripcion,aux.descripcion); //descripcion raza
            strcpy(entity[i].tamanio,aux.tamanio); //tamanio
            strcpy(entity[i].paisOrigen,aux.paisOrigen); //pais de origen
            entity[i].isEmpty=FULL;
            returnStatus=0;
            break;
        }
    }
    return returnStatus;
}

/** \brief Returns the space used in array (record count)
 *
 * \param eRazas entity1[] array to check
 * \param int size1 size of array
 * \return count of record with isEmpty FALSE
 *
 */
int LoadedRecordsStructureBreeds (eRazas entity1[],int size1)
{
    int i;
    int recordsQuantity;
    i=0;
    recordsQuantity=0;

    for(i=0;i<size1;i++)
    {
        if (entity1[i].isEmpty==FULL)
        {
            recordsQuantity++;
        }
    }
    return recordsQuantity;

}


/** \brief Prints to console loaded records of breeds
 *
 * \param entity1[] eRazas array to print
 * \param size1 int size of array
 * \return void
 *
 */
void PrintStructureBreeds(eRazas entity1[], int size1)
{
    int i;
    i=0;

    printf("Codigo\tRaza\tTamanio\tPais de Origen\n");


    for(i=0;i<size1;i++)
    {
        if (entity1[i].isEmpty==FULL)
        {
            printf("%-4d\t%-20s\t%-20s\t%-20s\n",entity1[i].idRaza,entity1[i].descripcion,entity1[i].tamanio,entity1[i].paisOrigen);
        }
    }
}

/** \brief Sort array with loaded record on top
  *
  * \param entity[] eRazas array to sort
  * \param size int size of array
  * \return int return empty records count
  *
  */
 int sortStructureFullElementsBreeds(eRazas entity[], int size)
{

    eRazas aux;
    int returnStatus;

    returnStatus=0;
    int i;
    int j;

    for (i=0;i<size-1;i++)
    {
        for (j=1;j<size;j++)
        {
            if (entity[i].isEmpty<entity[j].isEmpty)
            {
                aux=entity[j];
                entity[j]=entity[i];
                entity[j]=aux;
            }
        }
        if(entity[i].isEmpty==0)
        {
            returnStatus++;
        }
    }
    return returnStatus;

}


/** \brief sort array by id field
 *
 * \param entity[] eRazas array to sort
 * \param size int size of array
 * \param order int 0 if ascending order - 1 if descending order
 * \return void
 *
 */
void sortStructureBreedsById(eRazas entity[], int size, int order)
{

eRazas aux;

int recordCount;
int i;
int j;

recordCount=sortStructureFullElementsBreeds(entity,size);


for (i=0;i<recordCount-1;i++)
{
    for (j=i+1;j<recordCount;j++)
    {
        if (entity[i].idRaza>entity[j].idRaza && order==0)
        {
            aux=entity[i];
            entity[i]=entity[j];
            entity[j]=aux;
        }
        else if(entity[i].idRaza<entity[j].idRaza && order==1)
        {
            aux=entity[i];
            entity[i]=entity[j];
            entity[j]=aux;
        }
    }
}
// ordena strings   if (strcmp(entity[i].codigo,entity[j].codigo)>0)

}

void sortStructureBreedsByCountry(eRazas entity[], int size, int order);


/*****************ECOUNTRY*******************/

/** \brief sort array by country field
 *
 * \param entity[] eRazas array to sort
 * \param size int size of array
 * \param order int 0 if ascending order - 1 if descending order
 * \return void
 *
 */
void sortStructureBreedsByCountry(eRazas entity[], int size, int order)
{

eRazas aux;

int recordCount;
int i;
int j;

recordCount=sortStructureFullElementsBreeds(entity,size);


for (i=0;i<recordCount-1;i++)
{
    for (j=i+1;j<recordCount;j++)
    {
        if (strcmp(entity[i].paisOrigen,entity[j].paisOrigen)>0 && order==0)
        {
            aux=entity[i];
            entity[i]=entity[j];
            entity[j]=aux;
        }
        else if(strcmp(entity[i].paisOrigen,entity[j].paisOrigen)<0 && order==1)
        {
            aux=entity[i];
            entity[i]=entity[j];
            entity[j]=aux;
        }
    }
}
// ordena strings    if (strcmp(entity[i].codigo,entity[j].codigo)>0)


}
/** \brief Prints max values of eCountryPetsCount structure
 *
 * \param eCountryPetsCount array - the array to go through
 * \param int array - number of array elements
 * \return int -1 is size is invalid or index of max value found
 *
 */
int arrayPrintMaxValuesCountryPets (eCountryPetsCount array[],int size)
{
    int returnStatus;
    int maxArrayValue;
    int i;
    returnStatus=-1;

    sortStructureCountryPetsByCount(array,size,1);

    i=0;
    if (size>0)
    {
        returnStatus=0;
        maxArrayValue=array[0].petsCount;
        printf("\nPais\t\t\tCant Mascotas\n");
        printf("%-20s\t%-5d\n",array[i].paisOrigen,array[i].petsCount);
        i++;
        while(array[i].petsCount==maxArrayValue)
        {
            printf("%-20s\t%-5d\n",array[i].paisOrigen,array[i].petsCount);
            i++;
        }

    }

    return returnStatus;
}


/** \brief Print to console the code and name of all countries loaded
 *
 * \param entity1[] ePais array to print
 * \param size1 int size of array
 * \return void
 *
 */
void PrintStructureCountry(ePais entity1[], int size1)
{
    int i;
    i=0;

    printf("Pais\t\tContinente\tCod Telefono\n");

    for(i=0;i<size1;i++)
    {
        if (entity1[i].isEmpty==FULL)
        {
            printf("%-10s\t%-10s\t%-4d\n",entity1[i].nombreDePais,entity1[i].continente,entity1[i].codigoTelefonico);
        }
    }
}

/** \brief sort array by count of pets field
 *
 * \param entity[] eCountryPetsCount array to sort
 * \param size int size of array
 * \param order int 0 if ascending order - 1 if descending order
 * \return void
 *
 */
void sortStructureCountryPetsByCount(eCountryPetsCount entity[], int size, int order)
{

eCountryPetsCount aux;

int i;
int j;

for (i=0;i<size-1;i++)
{
    for (j=i+1;j<size;j++)
    {
        if (entity[i].petsCount>entity[j].petsCount && order==0)
        {
            aux=entity[i];
            entity[i]=entity[j];
            entity[j]=aux;
        }
        else if(entity[i].petsCount<entity[j].petsCount && order==1)
        {
            aux=entity[i];
            entity[i]=entity[j];
            entity[j]=aux;
        }
    }
}
// ordena strings   if (strcmp(entity[i].codigo,entity[j].codigo)>0)

}
/** \brief Sort array with loaded record on top
  *
  * \param entity[] ePais array to sort
  * \param size int size of array
  * \return int return empty records count
  *
  */
 int sortStructureFullElementsCountry(ePais entity[], int size)
{

    ePais aux;
    int returnStatus;

    returnStatus=0;
    int i;
    int j;

    for (i=0;i<size-1;i++)
    {
        for (j=1;j<size;j++)
        {
            if (entity[i].isEmpty<entity[j].isEmpty)
            {
                aux=entity[j];
                entity[j]=entity[i];
                entity[j]=aux;
            }
        }
        if(entity[i].isEmpty==0)
        {
            returnStatus++;
        }
    }
    return returnStatus;

}




/*****************FUNCIONES USERMENU*******************/

/** \brief Creates an options menu.
 *
 * \param optionsNumber int number of valid options
 * \param optionText char[] String of menu text
 * \param optionChooseText[] char message to direct the user to select an option
 * \param optionInvalidText[] char message to show if invalid option is selected
 * \return int returns the option selected as integer
 *
 */
int userMenuOption(int optionsNumber, int optionNumberExit, char optionsText[],char optionChooseText[],char optionInvalidText[])
{
    int userOption;

    do
    {
        printf("\n%s\n\n",optionsText);

        printf("%s\n",optionChooseText);

        //cleanStdin();
        scanf("%d",&userOption);

        if (userOption>optionsNumber)
        {
            printf("%s\n",optionInvalidText);

            getchar();
        }

    }while(userOption>optionsNumber && userOption!=optionNumberExit);

    return userOption;
}


/** \brief Takes the user option of a main menu and executes the code for that option
 *
 * \param userOption int user option of a menu
 * \param entity1[] eMascotas array used by cases
 * \param entity2[] eRazas array used by cases
 * \param size1 int size of eMascotas Array
 * \param size2 int size of eRazas Array
 * \return void
 *
 */
void MenuMainSwitch(int userOption, eMascotas entity1[], eRazas entity2[] , ePais entity3[], int size1, int size2, int size3)
{
    int returnAddPet;
    int returnAddBreed;
    int userOptionPrint;

    int modifyId;
    int removeId;



    switch(userOption)
    {
    case 1:
        returnAddPet=GetDataForPets(entity1,entity2,size1,size2);  //alta
        if(returnAddPet==-1)
        {
            printf("Capacidad maxima de mascotas alcanzada\n");
        }
        break;
    case 2: //Alta Raza
        returnAddBreed=GetDataForBreeds(entity2,entity3,size2,size3);  //alta
        if(returnAddBreed==-1)
        {
            printf("Capacidad maxima de razas alcanzada\n");
        }
        break;
    case 3: //baja
        if (LoadedRecordsStructurePets(entity1,size1)>0)
        {
            printf("Listado de Mascotas\n");
            sortStructurePetsById(entity1,size1,0);
            PrintStructurePets(entity1,size1);
            removeId=getInt("Ingrese el ID de la mascota a dar de baja:\n");
            removeRecordStructureByIdPets(entity1,size1,removeId);
        }
        else
        {
            printf("No hay mascotas cargadas\n");
        }
        break;
    case 4: //Modificar Mascota
        printf("\nListado de mascotas\n");
        sortStructurePetsById(entity1,size1,0);
        PrintStructurePets(entity1,size1);
        modifyId=getInt("Ingrese el ID de la mascota a modificar: ");
        ModifyStructDataPets(entity1,entity2,size1,size2,modifyId);
        break;
    case 5: //listados
        do
        {
            userOptionPrint=userMenuOption(5,0,"\n1. Lista de Mascotas con Razas y Pais\n2. Lista de Razas con Mascotas\n3. Lista de Mascotas Ordenadas por Peso\n4. Pais con mas mascotas\n5. Lista de Razas con Datos de Pais\n0. Salir","Elija una opcion...","Opcion Invalida...");
            MenuPrintSwitch(userOptionPrint,entity1,entity2,entity3,size1,size2,size3);

        }while(userOptionPrint!=0);
        break;

    }
}

/** \brief Takes the user option of a print menu and executes the code for that option
 *
 * \param userOption int user option of a menu
 * \param entity1[] eMascotas array used by cases
 * \param entity2[] eRazas array used by cases
 * \param size1 int size of eMascotas Array
 * \param size2 int size of eRazas Array
 * \return void
 *
 */
void MenuPrintSwitch(int userOption, eMascotas entity1[], eRazas entity2[] , ePais entity3[], int size1, int size2, int size3)
{
    switch(userOption)
    {
    case 1: //listado de mascotas con pais
        sortStructurePetsById(entity1,size1,0);
        printStructurePetsWithBreeds(entity1,entity2,size1,size2); //listado mascotas
        break;
    case 2: //lista de razas

        printStructureBreedsWithPets(entity2,entity1,size2,size1);  //listado razas

        break;
    case 3: //lista de razas por peso
        PrintStructurePetsByWeight(entity1,size1,0);
        break;
    case 4://pais con mas mascotas
        printStructureBreedsCountryWithMostPets(entity1,entity2,size1,size2,1);
        break;
    case 5: //lista de razas con datos
        printStructureBreedsWithCountryData(entity2,entity3,size2,size3);
        break;
    }
}

/** \brief a simple press any key to continue
 *
 * \return void
 *
 */
void PressAnyKey()
{
printf("\nPresione cualquier tecla para continuar\n");
getchar();

}

/*****************FUNCIONES VALIDATION*******************/

/** \brief Validates user input of Tipo field
 *
 * \param validateValue[] char String to validate
 * \param verbose int 0 does'nt inform the user of the posible values - 1 print posibles values to user if input is invalid
 * \return int -1 if value is invalid - 0 if valid
 *
 */
int ValidateStringTipo(char validateValue[],int verbose)
{
    char validationTipo[SIZEVALTIPO][20]={"gato","perro","raro"};
    int i;
    int isValid;
    i=0;
    isValid=-1;

    for (i=0;i<SIZEVALTIPO;i++)
    {
        if (strcmp(validationTipo[i],validateValue)==0)
        {
            isValid=0;
            if (verbose==0)
            {
                break;
            }
        }
    }
    if (verbose==1 && isValid==-1)
    {
        printf("Datos Invalido - Valores Posibles:\n");
        for (i=0;i<SIZEVALTIPO;i++)
        {
            printf("%s\n",validationTipo[i]);
        }
    }
    return isValid;
}

/** \brief Validates user input of Tipo field
 *
 * \param validateValue[] char String to validate
 * \param verbose int 0 does'nt inform the user of the posible values - 1 print posibles values to user if input is invalid
 * \return int -1 if value is invalid - 0 if valid
 *
 */
int ValidateStringTamanio(char validateValue[],int verbose)
{


    char validationTamanio[SIZEVALTAMANIO][20]={"chico","mediano","grande"};
    int i;
    int isValid;
    i=0;
    isValid=-1;

    for (i=0;i<SIZEVALTAMANIO;i++)
    {
        if (strcmp(validationTamanio[i],validateValue)==0)
        {
            isValid=0;
            if (verbose==0)
            {
                break;
            }
        }
    }
    if (verbose==1 && isValid==-1)
    {
        printf("Datos Invalido - Valores Posibles:\n");
        for (i=0;i<SIZEVALTAMANIO;i++)
        {
            printf("%s\n",validationTamanio[i]);
        }
    }
    return isValid;
}

/** \brief Validates user input of Sexo field
 *
 * \param validateValue char Character to validate
 * \param verbose int 0 does inform the user of the posible values - 1 print posibles values to user if input is invalid
 * \return int -1 if value is invalid - 0 if valid
 *
 */
int ValidateCharSexo(char validateValue,int verbose)
{
    char validationTipo[SIZEVALSEXO]={'M','F'};
    int i;
    int isValid;
    i=0;
    isValid=-1;

    for (i=0;i<SIZEVALTIPO;i++)
    {
        if (validationTipo[i]==validateValue)
        {
            isValid=0;
            if (verbose==0)
            {
                break;
            }
        }
    }
    if (verbose==1 && isValid==-1)
    {
        printf("Datos Invalido - Valores Posibles:\n");
        for (i=0;i<SIZEVALTIPO;i++)
        {
            printf("%c\n",validationTipo[i]);
        }
    }

    return isValid;
}
