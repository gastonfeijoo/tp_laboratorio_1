#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

/*
1-
a-crear un linkedlist ,
b-agregarles 5 elementos,
c-mostrar la cantidad de elementos cargados
*/

int main()
{

  //Crear lista
    LinkedList* miLista;
    int len;
    int i;
    Node* nodeMiLista;
    Employee* elementMiLista;
    miLista = ll_newLinkedList();

    len = ll_len(miLista);

    printf("Cantidad de elementos: %d\n", len);

    Employee* e1;
    Employee* e2;
    Employee* e3;
    Employee* e4;
    Employee* e5;

    e1 = (Employee*) malloc(sizeof(Employee));
    e1->id = 100;
    e1->horasTrabajadas = 80;
    e1->sueldo = 80000;
    strcpy(e1->nombre, "Pedro1");

    e2 = (Employee*) malloc(sizeof(Employee));
    e2->id = 200;
    e2->horasTrabajadas = 80;
    e2->sueldo = 80000;
    strcpy(e2->nombre, "Pedro2");

    e3 = (Employee*) malloc(sizeof(Employee));
    e3->id = 300;
    e3->horasTrabajadas = 80;
    e3->sueldo = 80000;
    strcpy(e3->nombre, "Pedro3");

    e4 = (Employee*) malloc(sizeof(Employee));
    e4->id = 400;
    e4->horasTrabajadas = 80;
    e4->sueldo = 80000;
    strcpy(e4->nombre, "Pedro4");

    e5 = (Employee*) malloc(sizeof(Employee));
    e5->id = 500;
    e5->horasTrabajadas = 80;
    e5->sueldo = 80000;
    strcpy(e5->nombre, "Pedro5");

    ll_add(miLista, e1);
    ll_add(miLista, e2);
    ll_add(miLista, e3);
    ll_add(miLista, e4);
    ll_add(miLista, e5);



    len = ll_len(miLista);

    printf("Cantidad de elementos: %d\n", len);

    /*Agrego mas empleados...(3 mas)*/

    /*Recorro la lista con un for*/
    // Utilizo GET para obtener el dato y luego mostrarlo

    //llamo la funcion en la iteracion si estoy borrando
    //sino uso el len


    //CON EL METODO REMOVE ELIMINAR UN ELEMENTO

    for(i=0;i<len;i++)
    {
        elementMiLista=(Employee*) ll_get(miLista,i);
        printf("%-4d\t%-15s\t%-4d\t%-4d\t\n",elementMiLista->id,elementMiLista->nombre,elementMiLista->sueldo,elementMiLista->horasTrabajadas);
    }

    int indexToRemove;
    int removeLl;
    indexToRemove=4;

    removeLl=ll_remove(miLista,indexToRemove);

    if (removeLl==-1)
    {
        printf("No se encontro el empleado para eliminar\n");
    }
    else
    {


        printf("retorno remove: %d\n",removeLl);

            for(i=0;i<ll_get(miLista,i);i++)
        {
            elementMiLista=(Employee*) ll_get(miLista,i);
            printf("%-4d\t%-15s\t%-4d\t%-4d\t\n",elementMiLista->id,elementMiLista->nombre,elementMiLista->sueldo,elementMiLista->horasTrabajadas);
        }
    }


    //int ll_set(LinkedList* this, int index,void* pElement); //reemplaza un elemento por otro Modificacion


    //USO DE SET

    int setGetIndex=0;
    elementMiLista=(Employee*) ll_get(miLista,setGetIndex);

    int setRetorno;
    int setIndex=1;

    setRetorno=ll_set(miLista,setIndex,elementMiLista);

    if (setRetorno==-1)
    {
        printf("No se encontro el empleado para eliminar\n");
    }
    else
    {


        printf("retorno set: %d\n",setRetorno);

            for(i=0;i<ll_get(miLista,i);i++)
        {
            elementMiLista=(Employee*) ll_get(miLista,i);
            printf("%-4d\t%-15s\t%-4d\t%-4d\t\n",elementMiLista->id,elementMiLista->nombre,elementMiLista->sueldo,elementMiLista->horasTrabajadas);
        }
    }

//USO DE PUSH

//int ll_push(LinkedList* this, int index, void* pElement); //ingresa un elemente entre dos elementos


    setGetIndex=3;

    elementMiLista=(Employee*) ll_get(miLista,setGetIndex);

    int pushRetorno;
    int pushIndex=1;

    pushRetorno=ll_set(miLista,pushIndex,elementMiLista);

    if (setRetorno==-1)
    {
        printf("No se encontro el empleado para insertar\n");
    }
    else
    {


        printf("retorno push: %d\n",setRetorno);

            for(i=0;i<ll_get(miLista,i);i++)
        {
            elementMiLista=(Employee*) ll_get(miLista,i);
            printf("%-4d\t%-15s\t%-4d\t%-4d\t\n",elementMiLista->id,elementMiLista->nombre,elementMiLista->sueldo,elementMiLista->horasTrabajadas);
        }
    }

//USO DE POP
//void* ll_pop(LinkedList* this,int index); //remueve pero devuelve el dato

    Employee* pushPop;
    int popIndex=1;

    pushPop=(Employee*) ll_pop(miLista,popIndex);

    if (pushPop==NULL)
    {
        printf("No se encontro el empleado para eliminar y devolver\n");
    }
    else
    {
        printf("Retorno POP\n%-4d\t%-15s\t%-4d\t%-4d\t\n\n",pushPop->id,pushPop->nombre,pushPop->sueldo,pushPop->horasTrabajadas);

            for(i=0;i<ll_get(miLista,i);i++)
        {
            elementMiLista=(Employee*) ll_get(miLista,i);
            printf("%-4d\t%-15s\t%-4d\t%-4d\t\n",elementMiLista->id,elementMiLista->nombre,elementMiLista->sueldo,elementMiLista->horasTrabajadas);
        }
    }

    // Clear limpia lista
    // deletell destructor
    //index of indice de elemento
    //isempty como len pero para saber si hay lugar


    //llsort

    //crear funcion criterio para el segundo argumento del sort
    //esa funcion levanta dos empleados y los compara por el campo que quiero
    /*
    int employee_CompareByID(Employee* unEmpleado,Employee* otroEmpleado)
    {
    int retorno
    0 igual 1 mayor -1 menor
    if(unEmpleado->id>otroEmpleado->id)
    {

    }

    y asi

    return retorno
    }

    ll_sort(miLista,employee_CompareById,0); //va sin parentesis porque la funcion la llama el sort

    */

    return 0;
}
