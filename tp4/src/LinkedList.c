#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"

static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;

    this = (LinkedList*) malloc(sizeof(LinkedList));
    if(this!=NULL)
    {
        this->size = 0;
        this->pFirstNode = NULL;
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        returnAux = this->size;
    }


    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    /*
            utest_startTest(getNodeTestCase01,getNodeTestSetup,">Caso [Verifica retorno con parametros correctos]");
            utest_startTest(getNodeTestCase02,getNodeTestSetup,">Caso [Solicitar el primer nodo]");
            utest_startTest(getNodeTestCase03,getNodeTestSetup,">Caso [Solicitar el ultimo nodo]");
            utest_startTest(getNodeTestCase04,getNodeTestSetup,">Caso [Solicita nodo fuera de indice]");
            utest_startTest(getNodeTestCase05,getNodeTestSetup,">Caso [Solicita nodo pasando una lista NULL]");
    */


    Node* pNode = NULL;

    int lenLl;
    int i;
    i=0;

    lenLl=ll_len(this);

    if (nodeIndex<lenLl)
    {

        pNode=this->pFirstNode;
        while(pNode!=NULL)
        {
            if (i==nodeIndex)
            {
                break;
            }
            i++;
            pNode=pNode->pNextNode;
        }

    }

    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{

int returnAux = -1;
    Node* prev;
    Node* next;
    Node* newNode;

    int lenLl;
    lenLl=ll_len(this);

    if(lenLl!=-1 && nodeIndex>-1 && nodeIndex<=lenLl)
    {

        newNode=(Node*) malloc(sizeof(Node));
        newNode->pElement=pElement;

        if(nodeIndex==0)
        {
            //no hay nodos en la LL
            newNode->pNextNode=NULL;
            this->pFirstNode=newNode;
        }
        else
        {
            prev=getNode(this,nodeIndex-1);
            next=getNode(this,nodeIndex);

            prev->pNextNode=newNode;
            newNode->pNextNode=next;

        }
        this->size++;
        returnAux=0;

    }

    return returnAux;
}



/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int lenLl;

    lenLl=ll_len(this);


    returnAux=addNode(this,lenLl,pElement);


    return returnAux;
}
//  ******* OJO CORREGIR *******************
/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* aux;
    int lenLl;
    lenLl=ll_len(this);

    if(this!=NULL && index>-1 && index<=lenLl)
    {
        aux=getNode(this,index);
        if(aux!=NULL)
        {
            returnAux=aux->pElement;
        }
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* actual;
//    int cantidad;

    actual=getNode(this,index);

    if (actual!=NULL)
    {
        actual->pElement=pElement;
        returnAux=0;
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{

int returnAux = -1;
    Node* prev;
    Node* actual;
    Node* next;

    int lenLl;
    lenLl=ll_len(this);

    if(lenLl!=-1 && index>-1 && index<lenLl)
    {

        if(index==0)
        {
            //no hay nodos en la LL
            this->pFirstNode=NULL;
        }
        else
        {
            prev=getNode(this,index-1);
            actual=getNode(this,index);

            next=actual->pNextNode;
            prev->pNextNode=next;
        }
        free(actual);
        this->size--;
        returnAux=0;

    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int sizeLL;
    int i;

    sizeLL=ll_len(this);

    if(sizeLL!=-1)
    {
        for(i=0;i<=sizeLL;i++)
        {
            ll_remove(this,i);
        }
        returnAux=0;

    }


    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    int sizeLL;
    int returnClear;
    sizeLL=ll_len(this);

    if(sizeLL!=-1)
    {
        returnClear=ll_clear(this);
        if (returnClear==0)
        {
            free(this);
            returnAux=0;
        }
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i;
    Node* nodo;
    int sizeLL;

    sizeLL=ll_len(this);

    if (sizeLL!=-1)
    {
        for(i=0;i<sizeLL;i++)
        {
            nodo=getNode(this,i);
            if (nodo!=NULL && pElement==nodo->pElement)
            {
                returnAux=i;
            }
        }
    }


    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        if( ll_len(this))
        {
            returnAux = 0;
        }
        else
        {
            returnAux = 1;
        }
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    int sizeLL;

    sizeLL=ll_len(this);

    if(this!=NULL && index>-1 && index<=sizeLL)
    {
        returnAux=addNode(this,index,pElement);
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
//    Node* nodo;
    int sizeLL;
    int returnRemove;

    sizeLL=ll_len(this);

    if(this!=NULL && index>-1 && index<sizeLL)
    {
        returnAux=ll_get(this,index);
        returnRemove=ll_remove(this,index);
        if (returnRemove==-1)
        {
            returnAux=NULL;
        }
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if (this!=NULL)
    {
        returnAux=ll_indexOf(this,pElement);
        if (returnAux!=-1)
        {
            returnAux=1;
        }
        else
        {
            returnAux=0;
        }
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int i;
    //Node* nodo;
    void* pElement;
    int sizeLL;

    sizeLL=ll_len(this2);

    if (this!=NULL && sizeLL!=-1)
    {
        returnAux=0;
        for(i=0;i<sizeLL;i++)
        {
            pElement=ll_get(this2,i);

            returnAux=ll_contains(this,pElement);
            if(returnAux==1||returnAux==-1)
            {
                break;
            }
        }
    }


    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int i;
    int returnAdd;
    void* pElement;

    int sizeLL;
    sizeLL=ll_len(this);

    if(sizeLL!=-1&&(from>-1&&from<=sizeLL)&&(to>from&&to<=sizeLL))
    {
        cloneArray=ll_newLinkedList();
        for(i=from;i<to;i++)
        {
            pElement=ll_get(this,i);
            returnAdd=ll_add(cloneArray,pElement);
        }


    }


    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    int i;
    int sizeLL;
    sizeLL=ll_len(this);

    if(sizeLL!=-1)
    {
        cloneArray=ll_newLinkedList();
        for(i=0;i<sizeLL;i++)
        {
            cloneArray=ll_subList(this,0,sizeLL);
        }


    }


    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux =-1;
    void* pAux;
    Node* node1;
    Node* node2;

    int i;
    int k;
    int returnSort;
    int sizeLL;
    sizeLL=ll_len(this);
    if(sizeLL!=-1&&pFunc!=NULL&&(order==0||order==1))
    {

        for(i=0;i<sizeLL-1;i++)
        {
            for(k=i+1;k<sizeLL;k++)
            {
                node1=getNode(this,i);
                node2=getNode(this,k);

                returnSort=pFunc(node1->pElement,node2->pElement);

                if(returnSort==-1 && order==0)
                {
                //menor
                pAux=node1->pElement;
                node1->pElement=node2->pElement;
                node2->pElement=pAux;

                }
                else
                {
                    if(returnSort==1 && order==1)
                    {
                        //mayor
                        pAux=node2->pElement;
                        node2->pElement=node1->pElement;
                        node1->pElement=pAux;
                    }

                }
            }
        }
        returnAux=0;
    }



    return returnAux;
}

