#ifndef _TLIST_TAD_
#define _TLIST_TAD_

#include <iostream>

#include "../../funciones/lists.hpp"

using namespace std;

template<typename T>
struct List
{
   Node<T>* p;
   Node<T>* aux;

   int tam;
   int act;
};

template<typename T>
List<T> list()
{
   List<T> lst={NULL,NULL,0,0};
   return lst;
}

template<typename T>
T* listAdd(List<T>& lst,T e)
{
   lst.tam++;
   Node<T>* ret = add<T>(lst.p, e);
   return &(ret->info);
}

template<typename T>
T* listAddFirst(List<T>& lst,T e)
{
   lst.tam++;
   return addFirst<T>(lst.p, e);
}

template<typename T,typename K>
T listRemove(List<T>& lst,K k,int cmpTK(T,K))
{
   lst.tam--;
   return remove<T>(lst.p, k, cmpTK);
}

template<typename T>
T listRemoveFirst(List<T>& lst)
{
   lst.tam--;
   return removeFirst<T>(lst.p);
}

template<typename T,typename K>
T* listFind(List<T> lst,K k,int cmpTK(T,K))
{
   return find<T>(lst.p,k, cmpTK);
}

template<typename T>
bool listIsEmpty(List<T> lst)
{
   return isEmpty(lst.p);
}

template<typename T>
int listSize(List<T> lst)
{
   return lst.tam;
}

template<typename T>
void listFree(List<T>& lst)
{
   lst.tam = 0;
   free(lst.p);
}

template<typename T>
T* listDiscover(List<T>& lst,T t,int cmpTT)
{
   Node<T>* nodo = find<T>(lst.p, t, cmpTT);

   if(nodo == NULL)
   {
      nodo = add<T>(lst.p, t);
      lst.tam++;
   }

   return &(nodo->info);
}

template<typename T>
T* listOrderedInsert(List<T>& lst,T t,int cmpTT(T,T))
{
   Node<T>* ret = orderedInsert<T>(lst.p,t,cmpTT);
   lst.tam++;
   return &ret->info;
}

template<typename T>
void listSort(List<T>& lst,int cmpTT(T,T))
{
   sort<T>(lst.p,cmpTT);
}

template<typename T>
void listReset(List<T>& lst)
{
   lst.aux = lst.p;
   lst.act = 0;
}

template<typename T>
bool listHasNext(List<T> lst)
{
   return lst.act<lst.tam;
}

template<typename T>
T* listNext(List<T>& lst)
{
   lst.act++;
   if(lst.aux ==NULL)
   {
      lst.aux = lst.p;
   }
   Node<T>* ret = lst.aux;
   lst.aux = lst.aux->sig;
   return &(ret->info);
}

template<typename T>
T* listNext(List<T>& lst,bool& endOfList)
{
   lst.act++;
   if(lst.act == lst.tam)
      endOfList = true;
   Node<T>* ret = lst.aux;
   lst.aux = lst.aux->sig;
   return &(ret->info);
}

#endif
