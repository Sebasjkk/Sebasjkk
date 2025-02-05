#ifndef _TTOKENS_T_
#define _TTOKENS_T_

#include <iostream>
#include <stdio.h>
#include "strings.hpp"
using namespace std;

int tokenCount(string s,char sep)
{
   int pos= 0, cant= 1;

   if(s=="")
      return 0;

   while(indexOf(s,sep,pos)!=lastIndexOf(s,sep))
   {
      pos=indexOf(s,sep,pos);
      pos++;
      cant++;
   }
   if((indexOf(s,sep,pos)>0)&&pos==0)
      cant++;
   if(pos != 0)
      cant++;
   return cant;
}

void addToken(string& s,char sep,string t)
{
   if(s!="")
      s+=sep+ t;
   else
      s+=t;
}

string getTokenAt(string s,char sep, int i)
{
   int n=0, pos=0, posans=0;

   i++;
   while(n<i)
   {
      posans = pos;
      pos = indexOf(s,sep,pos);
      pos++;
      n++;
   }
   pos--;
   if(pos<0)
   {
      pos = length(s);
   }
   string p = substring(s, posans, pos);

   return p;
}

void removeTokenAt(string& s,char sep, int i)
{
   string n= getTokenAt(s, sep, i);
   if(i==tokenCount(s,sep)&&i==0){}
   else if(i==tokenCount(s,sep)-1)
      n= insertAt(n,0,sep);
   else
      n+=sep;

   i=indexOf(s,n);
   int t=0;
   while(t<length(n))
   {
      s= removeAt(s,i);
      t++;
   }
}
/*
void setTokenAt(string& s,char sep, string t,int i)
{
   removeTokenAt(s,sep,i);
   if(i==tokenCount(s,sep)-1&&i!=0)
   {
      s+=sep;
      i=length(s);
   }     // IDEA, DEBE QUEDAR ARRIBA CADENA VAC�A Y ADENTRO DEL ELSE EL QUE EST� PRIMERO
   else if(i==0&&i==tokenCount(s,sep))       // Cadena vac�a
   {
      addToken(s,sep,t);
      return;
   }
   else
   {
      string n= getTokenAt(s, sep, i);
      i=indexOf(s,n);
      t+=sep;
   }

   int p=length(t);
   while(p>0)
   {
      s= insertAt(s,i,char(t[p-1]));
      p--;
   }
}*/

void setTokenAt(string& s,char sep, string t,int i)
{
   removeTokenAt(s,sep,i);

   if(i==tokenCount(s,sep))
   {
      addToken(s,sep,t);
   }
   else
   {
      t+=sep;
      string n= getTokenAt(s, sep, i);
      i=indexOf(s,n);
      int p=length(t);
      while(p>0)
      {
         s= insertAt(s,i,char(t[p-1]));
         p--;
      }
   }
}

int findToken(string s,char sep, string t)
{
   int i=0;
   int p=tokenCount(s,sep);
   while(i<p)
   {
      if(cmpString(getTokenAt(s,sep,i),t)==0)
         return i;
      i++;
   }
   return -1;
}

#endif

