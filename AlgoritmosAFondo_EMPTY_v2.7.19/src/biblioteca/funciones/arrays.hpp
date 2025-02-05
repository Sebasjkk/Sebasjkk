#ifndef _TARRAYS_T_
#define _TARRAYS_T_

#include <iostream>

template <typename T>
int add(T arr[],int& len,T e)
{
   arr[len]=e;
   len++;
   return len-1;
}

template <typename T>
void insert(T arr[],int& len,T e,int p)
{
   T aux1 = arr[p];
   T aux2;
   arr[p] = e;

   len++;
   for(;p<len; p++)
   {
      aux2 = arr[p+1];
      arr[p+1] = aux1;
      aux1 = aux2;
   }
}

template <typename T>
T remove(T arr[],int& len,int p)
{
   len--;
   T ret = arr[p];
   for(;p<len;p++)
   {
      arr[p]=arr[p+1];
   }
   return ret;
}

template <typename T, typename K>
int find(T arr[],int len,K k,int cmpTK(T,K))
{
   int pos = -1;
   for(int i = 0; i<len; i++)
   {
      if(cmpTK(arr[i],k)==0)
      {
         pos = i;
         break;
      }
   }
   return pos;
}

template <typename T>
int orderedInsert(T arr[],int& len,T e,int cmpTT(T,T))
{
   bool encontrado = false;
   int i;

   for(i=0; i<len; i++)
   {
      if(cmpTT(e,arr[i])<0)
      {
         encontrado = true;
         insert(arr, len, e, i);
         break;
      }
   }
   if(encontrado == false)
   {
      add(arr,len,e);
      i = len-1;
   }
   return i;
}

template <typename T>
void sort(T arr[],int len,int cmpTT(T,T))
{
   T aux1;
   bool ordenado = false;
   while(!ordenado)
   {
      ordenado = true;
      for(int n = 0; n<len-1; n++)
      {
         if(cmpTT(arr[n],arr[n+1])>0)
         {
            ordenado = false;
            aux1 = arr[n+1];
            arr[n+1] = arr[n];
            arr[n] = aux1;
         }
      }
   }
}

#endif
