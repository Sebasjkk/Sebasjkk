#ifndef _TLIST_T_
#define _TLIST_T_

#include <iostream>
#include <stdio.h>

template <typename T>
struct Node
{
   T info;
   Node<T>* sig;
};

template <typename T>
Node<T>* _createNode(T e)
{
   Node<T>* nodo = new Node<T>;
   nodo->info = e;
   nodo->sig = NULL;
   return nodo;
}

template <typename T>
Node<T>* add(Node<T>*& p,T e)
{
   Node<T>* nodo = _createNode<T>(e);
   if(p!=NULL)
   {
      Node<T>* aux = p;
      while(aux->sig!=NULL)
      {
         aux = aux->sig;
      }
      aux->sig = nodo;
   }
   else
   {
      p = nodo;
   }
   return nodo;
}

template <typename T>
Node<T>* addFirst(Node<T>*& p,T e)
{
   Node<T>* nodo = _createNode<T>(e);
   Node<T>* aux = p;
   p = nodo;
   p -> sig = aux;
   return p;
}

template <typename T, typename K>
T remove(Node<T>*& p,K k,int cmpTK(T,K))
{
   Node<T>* aux = p;
   Node<T>* ant = NULL;
   T t;
   while(aux->sig != NULL)
   {
      if(cmpTK(aux->info,k)==0)
      {
         t = aux->info;
         if(p == aux)
         {
            p = aux->sig;
         }
         else
         {
            ant->sig = aux->sig;
         }
         delete aux;
         return t;
      }
      ant = aux;
      aux = aux->sig;
   }
   t = aux->info;
   delete aux;
   ant->sig = NULL;
   return t;
}

template <typename T>
T removeFirst(Node<T>*& p)
{
   Node<T>* aux = p->sig;
   T t = p->info;

   delete p;
   p = aux;

   return t;
}

template <typename T, typename K>
Node<T>* find(Node<T>* p,K k,int cmpTK(T,K))
{
   Node<T>* aux = p;
   if(aux != NULL)
   {
      while(aux->sig != NULL)
      {
         if(cmpTK(aux->info,k) == 0)
            return aux;
         aux = aux->sig;
      }
      if(cmpTK(aux->info,k) == 0)
         return aux;
   }
   return NULL;
}

template <typename T>
Node<T>* orderedInsert(Node<T>*& p,T e,int cmpTT(T,T))
{
   Node<T>* aux = p;
   Node<T>* ant = NULL;
   Node<T>* nuevo = new Node<T>();
   nuevo->info = e;
   nuevo->sig = NULL;
   bool encontrado = false;
   if( p!=NULL )
   {
      while( aux!=NULL&&!encontrado )
      {
         if( cmpTT(e,aux->info)<0 )
         {
            if( ant!=NULL )
            {
               ant->sig = nuevo;
               nuevo->sig = aux;
               encontrado = true;
            }
            else
            {
               nuevo = addFirst<T>(p,e);
               encontrado = true;
            }
         }
         ant = aux;
         aux = aux->sig;
      }
      if( aux==NULL&&!encontrado )
      {
         ant->sig = nuevo;
      }
   }
   else
   {
      p = nuevo;
   }
   return nuevo;
}
/*
{
   Node<T>* nodo = _createNode<T>(e);
   Node<T>* ant = NULL;
   Node<T>* aux = p;
   if(aux != NULL)
   {
      if(cmpTT(aux->info,e) > 0)
      {
         nodo->sig = p;
         p = nodo;
         return nodo;
      }
      while(aux->sig != NULL)
      {
         if(cmpTT(aux->info,e) > 0)
         {
            ant->sig = nodo;
            nodo->sig = aux;
            return nodo;
         }
         ant = aux;
         aux = aux->sig;
      }
      if(cmpTT(aux->info,e) > 0)
      {
         aux->sig = nodo;
         return nodo;
      }
   }

   add<T>(p,e);
   return nodo;
}*/

template <typename T>
Node<T>* searchAndInsert(Node<T>*& p,T e,bool& enc,int cmpTT(T,T))
{
   Node <T>* nodo = find(p,e,cmpTT);
   enc = true;
   if(nodo == NULL)
   {
      enc = false;
      nodo = orderedInsert(p,e,cmpTT);
   }
   return nodo;
}

template <typename T>
void sort(Node<T>*& p,int cmpTT(T,T))
{
   Node<T>* aux1 = p;
   Node<T>* aux2 = p;
   Node<T>* ant = aux1;
   bool ordered = true;
   while(aux2->sig != NULL && ordered)
   {
      ordered = true;
      while(aux1->sig != NULL)
      {
         if(cmpTT(ant->info, aux1->info)>0)
         {
            ordered =false;
            T save = ant->info;
            ant->info = aux1->info;
            aux1->info = save;
         }
         ant = aux1;
         aux1 = aux1->sig;
      }
      aux2 = aux2->sig;
   }
}

template <typename T>
bool isEmpty(Node<T>* p)
{
   return p==NULL;
}

template <typename T>
void free(Node<T>*& p)
{
   while(p!=NULL)
   {
      Node<T>* aux=p->sig;
      delete p;
      p = aux;
   }
}

template <typename T>
Node<T>* push(Node<T>*& p,T e)
{
   return addFirst(p,e);
}

template <typename T> T pop(Node<T>*& p)
{
   return removeFirst(p);
}

template <typename T>
Node<T>* enqueue(Node<T>*& p,Node<T>*& q,T e)
{
   //q = add(p,e);
   if(q!=NULL)
   {
      Node<T>* nodo = _createNode<T>(e);
      q->sig = nodo;
      q = nodo;
   }
   else
   {
      q = push(p,e);
   }
   return q;
}

template <typename T>
Node<T>* enqueue(Node<T>*& q,T e)
{
   Node<T>* nodo = _createNode<T>(e);
   if(q!=NULL)
   {
      nodo->sig = q->sig;
      q->sig = nodo;
   }
   else
   {
      q = nodo;
      nodo->sig = nodo;
   }
   q = nodo;
   return nodo;
}

template <typename T>
T dequeue(Node<T>*& p, Node<T>*& q)
{
   T t = p->info;
   Node<T>* aux = p->sig;
   delete p;
   if(p != q)
   {
      p = aux;
   }
   else
   {
      p = NULL;
      q = NULL;
   }

   return t;
}

template <typename T>
T dequeue(Node<T>*& q)
{
   T t = q->sig->info;

   if(q != q->sig)
   {
      Node<T>* aux = q->sig->sig;
      delete q->sig;
      q->sig = aux;
   }
   else
   {
      delete q;
      q = NULL;
   }

   return t;
}

#endif
