
#ifndef _TMAP_TAD_
#define _TMAP_TAD_

#include <iostream>
#include "Array.hpp"

using namespace std;

template<typename K,typename V>
struct Map
{
   Array<K> keys;
   Array<V> values;
   int pos;
};

template<typename K,typename V>
Map<K,V> map()
{
   Map<K,V> m;
   m.keys = array<K>();
   m.values = array<V>();
   m.pos = 0;
   return m;
}

template<typename K>
int _cmpKK(K a, K b)
{
   if(a==b)
      return 0;
   else
      return -1;
}

template<typename K,typename V>
V* mapGet(Map<K,V> m,K k)
{
   V* ret;
   int pos = arrayFind<K>(m.keys,k,_cmpKK);
   if (pos<0)
      ret = NULL;
   else
      ret = &(m.values.arr[pos]);
   return ret;
}

template<typename K,typename V>
V* mapPut(Map<K,V>& m,K k,V v)
{
   K* key = arrayDiscover<K>(m.keys,k,_cmpKK);
   int pos = key - m.keys.arr;
   if(pos<arraySize(m.values)-1)
      m.values.arr[pos] = v;
   else
      arrayAdd<V>(m.values,v);

   return &(m.values.arr[pos]);
}

template<typename K,typename V>
bool mapContains(Map<K,V> m,K k)
{
   int pos = arrayFind<K>(m.keys,k,_cmpKK);
   if(pos<0)
      return false;
   else
      return true;
}

template<typename K,typename V>
V mapRemove(Map<K,V>& m,K k)
{
   V v;
   V* dir = mapGet(m, k);
   int pos = dir - m.values.arr;
   v = arrayRemove(m.values, pos);
   arrayRemove(m.keys, pos);
   return v;
}

template<typename K,typename V>
void mapRemoveAll(Map<K,V>& m)
{
   arrayRemoveAll<K>(m.keys);
   arrayRemoveAll<V>(m.values);
}

template<typename K,typename V>
int mapSize(Map<K,V> m)
{
   return arraySize<V>(m.values);
}

template<typename K,typename V>
bool mapHasNext(Map<K,V> m)
{
   return m.pos < mapSize<K,V>(m);
}

template<typename K,typename V>
K mapNextKey(Map<K,V>& m)
{
   K k;
   k = *arrayGet<K>(m.keys,m.pos);
   m.pos++;
   return k;
}

template<typename K,typename V>
V* mapNextValue(Map<K,V>& m)
{
   V* v;
   v = arrayGet<V>(m.values,m.pos);
   m.pos++;
   return v;
}

template<typename K,typename V>
void mapReset(Map<K,V>& m)
{
   m.pos =0;
}

template<typename K,typename V>
V* mapDiscover(Map<K,V>& m,K k,V v)
{
   V* value = mapGet<K,V>(m,k);

   if(value == NULL)
   {
      value = mapPut<K,V>(m,k,v);
   }

   return value;
}


template<typename K,typename V>
void mapSortByKeys(Map<K,V>& m,int cmpKK(K,K))
{
   K aux1;
   V aux2;
   bool ordenado = false;
   while(!ordenado)
   {
      ordenado = true;
      for(int n = 0; n < mapSize<K,V>(m)-1; n++)
      {
         if(cmpKK(m.keys.arr[n],m.keys.arr[n+1])>0)
         {
            ordenado = false;
            aux1 = m.keys.arr[n+1];
            m.keys.arr[n+1] = m.keys.arr[n];
            m.keys.arr[n] = aux1;

            aux2 = m.values.arr[n+1];
            m.values.arr[n+1] = m.values.arr[n];
            m.values.arr[n] = aux2;
         }
      }
   }
}

template<typename K,typename V>
void mapSortByValues(Map<K,V>& m,int cmpVV(V,V))
{
   V aux1;
   K aux2;
   bool ordenado = false;
   while(!ordenado)
   {
      ordenado = true;
      for(int n = 0; n < mapSize<K,V>(m)-1; n++)
      {
         if(cmpVV(m.values.arr[n],m.values.arr[n+1])>0)
         {
            ordenado = false;
            aux1 = m.values.arr[n+1];
            m.values.arr[n+1] = m.values.arr[n];
            m.values.arr[n] = aux1;

            aux2 = m.keys.arr[n+1];
            m.keys.arr[n+1] = m.keys.arr[n];
            m.keys.arr[n] = aux2;
         }
      }
   }
}

#endif
