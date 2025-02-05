#ifndef _TQUEUE_TAD_
#define _TQUEUE_TAD_

#include <iostream>
#include "../../funciones/lists.hpp"

using namespace std;

template<typename T>
struct Queue
{
   Node<T>* q;
   int tam;
};

template<typename T>
Queue<T> queue()
{
   Queue<T> q;
   q.q = NULL;
   q.tam = 0;
   return q;
}

template<typename T>
T* queueEnqueue(Queue<T>& q,T e)
{
   q.tam++;
   return &enqueue(q.q,e)->info;
}

template<typename T>
T queueDequeue(Queue<T>& q)
{
   q.tam--;
   return dequeue(q.q);
}

template<typename T>
bool queueIsEmpty(Queue<T> q)
{
   return q.tam == 0;
}

template<typename T>
int queueSize(Queue<T> q)
{
   return q.tam;
}

#endif
