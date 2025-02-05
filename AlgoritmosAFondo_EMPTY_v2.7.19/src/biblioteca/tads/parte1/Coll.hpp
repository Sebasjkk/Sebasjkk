#ifndef _TCOLL_T_
#define _TCOLL_T_

#include <iostream>
#include "../../funciones/strings.hpp"

using namespace std;

template<typename T>
struct Coll
{
   string s;
   char sep;
   int pos=0;
};

template<typename T>
Coll<T> coll(char sep)
{
   Coll<T> c;
   c.s = "";
   c.sep = sep;
   return c;
}

template<typename T>
Coll<T> coll()
{
   Coll<T> c;
   c.s = "";
   c.sep = '|';
   return c;
}

template<typename T>
int collSize(Coll<T> c)
{
   return tokenCount(c.s,c.sep);
}

template<typename T>
void collRemoveAll(Coll<T>& c)
{
   c.s="";
}

template<typename T>
void collRemoveAt(Coll<T>& c, int p)
{
   removeTokenAt(c.s,c.sep,p);
}

template<typename T>
int collAdd(Coll<T>& c,T t,string tToString(T))
{
   addToken(c.s,c.sep,tToString(t));
   return collSize(c)-1;
}

template <typename T>
void collSetAt(Coll<T>& c,T t,int p,string tToString(T))
{
   setTokenAt(c.s, c.sep, tToString(t), p);
}

template <typename T>
T collGetAt(Coll<T> c,int p,T tFromString(string))
{
   T t;
   string s= getTokenAt(c.s,c.sep, p);
   t = tFromString(s);
   return t;
}

template <typename T, typename K>
int collFind(Coll<T> c,K k,int cmpTK(T,K),T tFromString(string))
{
   int i=0;
   int p=collSize(c);

   while(i<p)
   {
      if(cmpTK(tFromString(getTokenAt(c.s,c.sep,i)),k)==0)
         return i;
      i++;
   }
   return -1;
}

template <typename T>
void collSort(Coll<T>& c,int cmpTT(T,T),T tFromString(string),string tToString(T))
{
   int cant = collSize(c);
   T a, b, aux;
   while(true)
   {
      bool corte = true;
      for(int i=0;i<cant-1;i++)
      {
         a= collGetAt(c, i, tFromString);
         b= collGetAt(c, i+1, tFromString);
         if(cmpTT(a,b)>0)
         {
            aux= a;
            //a= b;
            collSetAt(c, b, i,tToString);
            //b= aux;
            if(i==cant-2)
            {
               collRemoveAt(c, cant-1);
               collAdd(c,aux,tToString);
            }
            else
               collSetAt(c, aux,i+1,tToString);
            corte = false;
         }
      }
      if(corte==true)
         break;
   }
}

/*
template <typename T>
void collSort(Coll<T>& c,int cmpTT(T,T),T tFromString(string),string tToString(T))
{
   int cant = collSize(c);
   bool corte = true;
   T a, b, aux;
   while(true)
   {

      corte = true;
      for(int i=0;i<cant-1;i++)
      {
         a= collGetAt(c, i, tFromString);
         b= collGetAt(c, i+1, tFromString);
         if(cmpTT(collGetAt(c, i, tFromString),b)>0)
         {
            aux= a;
            //a= b;
            collSetAt(c, b, i,tToString);
            //b= aux;
            collSetAt(c, aux,i+1,tToString);
            collAdd(c,aux,tToString);
            corte = false;
         }
      }
      if(corte==true)
         break;
   }
}
*/
template<typename T>
bool collHasNext(Coll<T> c)
{
   if(c.pos>=collSize(c))
      return false;
   return true;
}

template<typename T>
T collNext(Coll<T>& c,T tFromString(string))
{
   T t;
   t = collGetAt(c,c.pos,tFromString);
   c.pos++;
   return t;
}

template<typename T>
T collNext(Coll<T>& c,bool& endOfColl,T tFromString(string))
{
   T t;
   endOfColl=false;
   t= collGetAt(c,c.pos,tFromString);
   if(!collHasNext(c))
      endOfColl=true;
   c.pos++;
   return t;
}

template<typename T>
void collReset(Coll<T>& c)
{
   c.pos=0;
}

template<typename T>
string collToString(Coll<T> c)
{
   return c.sep+c.s;
}

template<typename T>
Coll<T> collFromString(string s)
{
   Coll<T> c;
   c.sep=s[0];
   c.s=substring(s,1);
   return c;
}

#endif
