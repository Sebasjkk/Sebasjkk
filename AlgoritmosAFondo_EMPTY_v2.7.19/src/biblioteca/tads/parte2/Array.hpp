#ifndef _TARR_TAD_
#define _TARR_TAD_

#include <iostream>
#include <stdlib.h>
#include "../../funciones/arrays.hpp"

using namespace std;

template<typename T>
struct Array
{
   T* arr;
   int len;
};

template<typename T>
Array<T> array()
{
   Array<T> ret;
   ret.arr = NULL;
   ret.len = 0;
   return ret;
}

template<typename T>
int arrayAdd(Array<T>& a,T t)
{
   T* arr =new T[a.len+1];
   int i;
   for(i=0;i<a.len;i++)
   {
      arr[i]=a.arr[i];
   }
   arr[i]=t;
   delete  a.arr;

   a.len++;
   a.arr = arr;
   return a.len-1;
}

template<typename T>
T* arrayGet(Array<T> a,int p)
{
   T* dir = &(a.arr[p]);

   return dir;
}

template<typename T>
void arraySet(Array<T>& a,int p,T t)
{
   a.arr[p]=t;
}

template<typename T>
void arrayInsert(Array<T>& a,T t,int p)
{
   Array<T> arr = array<T>();
   a.len++;

   int n=0;
   for(int i =0; i<a.len; i++)
   {
      if(i == p)
      {
         arrayAdd(arr,t);
      }
      else
      {
         arrayAdd(arr,a.arr[n]);
         n++;
      }
   }
   delete a.arr;
   a = arr;

}

template<typename T>
int arraySize(Array<T> a)
{
   return a.len;
}

template<typename T>
T arrayRemove(Array<T>& a,int p)
{
   T t;
   t = arrayGet<T>(a, p);
   a.len--;
   /*
   Array<T> b = array<T>();

   int i =0,n=0;
   while(i<a.len)
   {
      if(i==p)
      {
         t = a.arr[n];
         n++;
      }
      else
      {
         arrayAdd<T>(b,a.arr[n]);
         n++;
      }
      i++;
   }
   delete a.arr;
   a=b;*/
   return t;
}

template<typename T>
void arrayRemoveAll(Array<T>& a)
{
   int i=0;
   while(i<a.len)
   {
      arrayRemove<T>(a,0);
   }
   a.len = 0;
}

template<typename T,typename K>
int arrayFind(Array<T> a,K k,int cmpTK(T,K))
{
   int i=0, ret = -1;
   while(i<a.len)
   {
      T* p = arrayGet<T>(a,i);
      if(cmpTK(*p,k)==0)
      {
         ret= i;
         break;
      }
      i++;
   }
   return ret;
}

template<typename T>
int arrayOrderedInsert(Array<T>& a,T t,int cmpTT(T,T))
{
   arrayAdd<T>(a,t);
   sort<T>(a.arr,a.len,cmpTT);

   return 0;
}

template<typename T>
T* arrayDiscover(Array<T>& a,T t,int cmpTT(T,T))
{
   int pos = arrayFind<T>(a,t,cmpTT);
   if(pos<0)
   {
      arrayAdd<T>(a,t);
      pos = arraySize<T>(a);
   }
   return &(a.arr[pos]);
}


template<typename T>
void arraySort(Array<T>& a,int cmpTT(T,T))
{
   sort<T>(a.arr,arraySize<T>(a),cmpTT);
}

#endif
