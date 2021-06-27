#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


/** \brief Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 *
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 *                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex);


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 *
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 *                      ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex, void* pElement);


LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;

    this = (LinkedList*) malloc(sizeof(LinkedList));

    if(this != NULL)
    {
        this->pFirstNode = NULL;
        this->size = 0;
    }

    return this;
}

int ll_len(LinkedList* this)
{
    int auxReturn = -1;

    if(this != NULL)
    {
        auxReturn = this->size;
    }

    return auxReturn;
}

static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;

    int length;
    int i;

    if(this != NULL && nodeIndex >= 0)
    {
        length = ll_len(this);

        if(length > 0 && nodeIndex < length)
        {
            pNode = this->pFirstNode;

            if(nodeIndex > 0)
            {
				for(i = 0; i < nodeIndex; i++)
				{
					pNode = pNode->pNextNode;
				}
            }
        }
    }

    return pNode;
}

Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}

static int addNode(LinkedList* this, int nodeIndex, void* pElement)
{
    int auxReturn = -1;
    int length;

    Node* pNewNode;
    Node* pPrevNode;

    if(this != NULL && nodeIndex >= 0)
    {
        length = ll_len(this);

        if(nodeIndex <= length)
        {
            pNewNode = (Node*) malloc(sizeof(Node));

            if(pNewNode != NULL)
            {
                pNewNode->pElement = pElement;

                if(nodeIndex == 0)
                {
                    pNewNode->pNextNode = this->pFirstNode;
                	this->pFirstNode = pNewNode;
                }

                else
                {
                    pPrevNode = getNode(this, nodeIndex - 1);

                    if(pPrevNode != NULL)
                    {
                    	pNewNode->pNextNode = pPrevNode->pNextNode;
                    	pPrevNode->pNextNode = pNewNode;
                    }
                }

                this->size++;
                auxReturn = 0;
            }
        }
    }

    return auxReturn;
}

int test_addNode(LinkedList* this, int nodeIndex, void* pElement)
{
    return addNode(this, nodeIndex, pElement);
}

int ll_add(LinkedList* this, void* pElement)
{
    int auxReturn = -1;
    int length;

    if(this != NULL)
    {
        length = ll_len(this);

        auxReturn = addNode(this, length, pElement);
    }

    return auxReturn;
}

void* ll_get(LinkedList* this, int index)
{
    void* auxReturn = NULL;
    Node* pNode;

    int length;

    if(this != NULL && index >= 0)
    {
        length = ll_len(this);

        if(length > 0 && index < length)
        {
            pNode = getNode(this, index);

            if(pNode != NULL)
            {
            	auxReturn = pNode->pElement;
            }
        }
    }

    return auxReturn;
}

int ll_set(LinkedList* this, int index, void* pElement)
{
    int auxReturn = -1;
    int length;

    Node* pNode;

    if(this != NULL && index >= 0)
    {
        length = ll_len(this);

        if(length > 0 && index < length)
        {
            pNode = getNode(this, index);

            if(pNode != NULL)
            {
            	pNode->pElement = pElement;

            	auxReturn = 0;
            }
        }
    }

    return auxReturn;
}

int ll_remove(LinkedList* this, int index)
{
    int auxReturn = -1;
    int length;

    Node* pActualNode;
    Node* pPrevNode;

    if(this != NULL && index >= 0)
    {
        length = ll_len(this);

        if(length > 0 && index < length)
        {
            pActualNode = getNode(this, index);

            if(pActualNode != NULL)
            {
				if(index == 0)
				{
					this->pFirstNode = pActualNode->pNextNode;
				}

				else
				{
					pPrevNode = getNode(this, index - 1);

					if(pPrevNode != NULL)
					{
						pPrevNode->pNextNode = pActualNode->pNextNode;
					}
				}

				free(pActualNode);

				this->size--;
				auxReturn = 0;
            }
        }
    }

    return auxReturn;
}

int ll_clear(LinkedList* this)
{
    int auxReturn = -1;
    int length;
    int i;

    if(this != NULL)
    {
		length = ll_len(this);

		if(length > 0)
		{
			for(i = length - 1; i >= 0; i--)
			{
				if(ll_remove(this, i))
				{
					break;
				}
			}

			if(i == -1)
			{
				auxReturn = 0;
			}
		}
    }

    return auxReturn;
}

int ll_deleteLinkedList(LinkedList* this)
{
    int auxReturn = -1;

    if(this != NULL && !ll_clear(this))
    {
        free(this);

        auxReturn = 0;
    }

    return auxReturn;
}

int ll_indexOf(LinkedList* this, void* pElement)
{
    int auxReturn = -1;
    int length;
    int i;

    void* pAux;

    if(this != NULL)
    {
        length = ll_len(this);

        if(length > 0)
        {
            for(i = 0; i < length; i++)
            {
                pAux = ll_get(this, i);

                if(pAux == pElement)
                {
                    auxReturn = i;
                    break;
                }
            }
        }
    }

    return auxReturn;
}

int ll_isEmpty(LinkedList* this)
{
    int auxReturn = -1;
    int length;

    if(this != NULL)
    {
        length = ll_len(this);

        if(length == 0)
        {
            auxReturn = 1;
        }

        else
        {
            auxReturn = 0;
        }
    }

    return auxReturn;
}

int ll_push(LinkedList* this, int index, void* pElement)
{
    int auxReturn = -1;
    int length;

    if(this != NULL && index >= 0)
    {
        length = ll_len(this);

        if(index <= length)
        {
            auxReturn = addNode(this, index, pElement);
        }
    }

    return auxReturn;
}

void* ll_pop(LinkedList* this, int index)
{
    void* auxReturn = NULL;
    int length;

    if(this != NULL && index >= 0)
    {
        length = ll_len(this);

        if(length > 0 && index < length)
        {
            auxReturn = ll_get(this, index);

            if(ll_remove(this, index))
            {
                auxReturn = NULL;
            }
        }
    }

    return auxReturn;
}

int ll_contains(LinkedList* this, void* pElement)
{
    int auxReturn = -1;
    int index;

    if(this != NULL)
    {
        index = ll_indexOf(this, pElement);

        if(index > -1)
        {
            auxReturn = 1;
        }

        else
        {
            auxReturn = 0;
        }
    }

    return auxReturn;
}

int ll_containsAll(LinkedList* this, LinkedList* this2)
{
    int auxReturn = -1;
    int length;
    int i;

    void* pElement;

    if(this != NULL && this2 != NULL)
    {
        auxReturn = 1;

        length = ll_len(this2);

        for(i = 0; i < length; i++)
        {
            pElement = ll_get(this2, i);

            if(!ll_contains(this, pElement))
            {
                auxReturn = 0;
                break;
            }
        }
    }

    return auxReturn;
}

LinkedList* ll_subList(LinkedList* this, int from, int to)
{
    LinkedList* cloneArray = NULL;

    void* pElement;
    int length;
    int i;

    if(this != NULL && from >= 0 && from < to)
    {
        length = ll_len(this);

        if(from <= length && to <= length)
        {
            cloneArray = ll_newLinkedList();

            if(cloneArray != NULL)
            {
                for(i = from; i < to; i++)
                {
                    pElement = ll_get(this, i);

                    if(ll_add(cloneArray, pElement))
                    {
                        free(cloneArray);
                    	cloneArray = NULL;
                        break;
                    }
                }
            }
        }
    }

    return cloneArray;
}

LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    int length;

    if(this != NULL)
    {
        length = ll_len(this);

        cloneArray = ll_subList(this, 0, length);
    }

    return cloneArray;
}

int ll_sort(LinkedList* this, int (*pFunc)(void*, void*), int order)
{
    int auxReturn = -1;
    int length;
    int i;
    int flagSwap;
    int pFuncReturn;

    void* pElement1;
    void* pElement2;

    if(this != NULL && pFunc != NULL && (order == 1 || order == 0))
    {
        length = ll_len(this);

        if(length > 0)
        {
            do
            {
                flagSwap = 0;

                for(i = 0; i < length - 1; i++)
                {
                    pElement1 = ll_get(this, i);
                    pElement2 = ll_get(this, i + 1);

                    pFuncReturn = pFunc(pElement1, pElement2);

                    if((order == 1 && pFuncReturn == 1) || (order == 0 && pFuncReturn == -1))
                    {
                    	ll_set(this, i, pElement2);
                    	ll_set(this, i + 1, pElement1);

                        flagSwap = 1;
                    }
                }

                length--;

            } while(flagSwap);

            auxReturn = 0;
        }
    }

    return auxReturn;
}
