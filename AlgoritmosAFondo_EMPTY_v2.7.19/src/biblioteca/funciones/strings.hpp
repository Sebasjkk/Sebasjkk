#ifndef _TSTRINGS_T_
#define _TSTRINGS_T_

#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int length(string s)
{
   int i=0;
   while(s[i]!='\0')
   {
      i++;
   }
   return i;
}

int charCount(string s,char c)
{
   int i=0,count=0;
   while(s[i]!='\0')
   {
      if(s[i]==c)
         count++;
      i++;
   }
   return count;
}

string substring(string s,int d,int h)
{
   string changed="";
   int i;
   for(i=d;i<h;i++)
   {
      changed+= s[i];
   }
   return changed;
}

string substring(string s,int d) // ok
{
   string changed="";
   int i;
   for(i=d;i<length(s);i++)
   {
      changed+= s[i];
   }
   return changed;
}

int indexOf(string s,char c) // ok
{
   int i=0;
   while(s[i]!='\0')
   {
      if(s[i]==c)
         return i;
      i++;
   }
   return -1;
}

int indexOf(string s,char c,int offSet) // ok
{
   int i=offSet;
   while(s[i]!='\0')
   {
      if(s[i]==c)
         return i;
      i++;
   }
   return -1;
}

int indexOf(string s,string toSearch) // ok
{
   int i=0,n=0;

   while(s[i]!='\0')
   {
      if(s[i]==toSearch[n])
      {
         if(n==length(toSearch)-1)
            return i-n;
         n++;
      }
      else
         n=0;
      i++;
   }
   return -1;
}

int indexOf(string s,string toSearch,int offset) // ok
{
   int i=offset,n=0;

   while(s[i]!='\0')
   {
      if(s[i]==toSearch[n])
      {
         if(n==length(toSearch)-1)
            return i-n;
         n++;
      }
      else
         n=0;
      i++;
   }
   return -1;
}

int lastIndexOf(string s,char c)
{
   int i=0,pos=-1;
   while(s[i]!='\0')
   {
      if(s[i]==c)
         pos=i;
      i++;
   }
   return pos;
}

int indexOfN(string s,char c,int n)
{
   int i=0,pos=-1,cant=0;;
   if(n==0)
      return pos;
   while(s[i]!='\0')
   {
      if(s[i]==c)
      {
         pos=i+1;
         cant++;
         if(cant==n)
            return pos;
      }
      i++;
   }
   return i;
}

int charToInt(char c)
{
   if(c>='0'&&c<='9')
      c = c-'0';
   if(c>='A'&&c<='Z')
      c = c-'A'+10;
   if(c>='a'&&c<='z')
      c = c-'a'+10;
   return c;
}

char intToChar(int i)
{
   if(i>=0&&i<=9)
      i = i+'0';
   if(i>=10&&i<=35)
      i = i+'A'-10;
   return char(i);
}

int getDigit(int n,int i)
{
   int t=10,p=0;
   while(p<i)
   {
      t=t*10;
      p++;
   }
   return n%t/(t/10);
}

int digitCount(int n)
{
   int t=1,i=0;
   while(n/t!=0)
   {
      i++;
      t*=10;
   }
   return i;
}

string intToString(int i)
{
   string num;
   if (i!=0)
   {
      int n=digitCount(i)-1;
      while(n>=0)
      {
         num+=intToChar(getDigit(i,n));
         n--;
      }
   }
   else
      num+="0";
   return num;
}

int stringToInt(string s,int b) // ok
{
   int i=0,num=0;
   while(i<length(s))
   {
      int n=length(s)-i-1, pot=1;
      while(n>0)
      {
         pot=pot*b;
         n--;
      }
      num+=charToInt(char(s[i]))*pot;
      i++;
   }
   return num;
}

int stringToInt(string s) // REVISAR NEGATIVOS DE ACA incluido PARA ARRIBA
{
   int i=0,num=0;
   while(i<length(s))
   {
      int n=length(s)-i-1, pot=1;
      while(n>0)
      {
         pot=pot*10;
         n--;
      }
      num+=charToInt(char(s[i]))*pot;
      i++;
   }
   return num;
}

string charToString(char c)
{
   string carac;
   carac += c;
   return carac;
}

char stringToChar(string s)
{
   char carac = s[0];
   return carac;
}

string stringToString(string s)
{
   return s;
}

string doubleToString(double d) //Solo devuelve hasta 2 decimales
{
   d*=100;
   int entero=int(d)/100, decimal=int(d)%100;
   int n=digitCount(entero)-1;
   string num;
   while(n>=0)
   {
      num+=intToChar(getDigit(entero,n));
      n--;
   }
   num+='.';
   n=digitCount(decimal)-1;
   while(n>=0)
   {
      num+=intToChar(getDigit(decimal,n));
      n--;
   }
   return num;
}

double stringToDouble(string s)
{
   int i=0, poscoma=-1;
   double num=0;

   while(i<length(s))
   {
      if(s[i]=='.')
      {
         poscoma=i;
         i++;
         continue;
      }
      int n=length(s)-i-1;
      double pot=1;
      if(poscoma!=-1)
         pot=pot*10;
      while(n>0)
      {
         pot=pot*10;
         n--;
      }
      num+=charToInt(char(s[i]))*pot;
      i++;
   }
   if(poscoma!=-1)
   {
      poscoma = i-poscoma;
      i=0;
      int pot=1;
      while(i<poscoma)
      {
         pot=pot*10;
         i++;
      }
      num=num/pot;
   }
   return num;
}

bool isEmpty(string s)
{
   if(s=="")
      return true;
   else
      return false;
}

bool startsWith(string s,string x)
{
   if (indexOf(s,x)==0)
      return true;
   else
      return false;
}

bool endsWith(string s,string x)
{
   int pos=length(s)-length(x);
   if(indexOf(s,x,pos)==pos)
      return true;
   else
      return false;
}

bool contains(string s,char c)
{
   if(lastIndexOf(s,c)>=0)
      return true;
   else
      return false;
}

string replace(string s,char oldChar,char newChar) //COMPLETAR
{
   int i=0;
   string cambiada;
   while(s[i]!='\0')
   {
      if(s[i]==oldChar)
         cambiada+=newChar;
      else
         cambiada+=s[i];
      i++;
   }
      return cambiada;
}

string removeAt(string s,int pos)
{
   int i=0;
   string cambiada;
   while(s[i]!='\0')
   {
      if(i!=pos)
         cambiada += s[i];
      i++;
   }
      return cambiada;
}

string insertAt(string s,int pos,char c)
{
   int i=0;
   string cambiada;
   bool nul=false;         //MEDIO ASQUEROSO PERO BUENO
   if(s[pos]=='\0')
   {
      s+=c;
      nul=true;
   }
   while(s[i]!='\0')
   {
      if(i==pos)
         cambiada+=c;
      cambiada += s[i];
      i++;
   }
   if(nul)
      cambiada = removeAt(cambiada,length(cambiada)-1);
   return cambiada;
}

string ltrim(string s)
{
   int i=0;
   bool inicio=true;
   string cambiada;
   while(s[i]!='\0')
   {
      if(s[i]==' '&&inicio)
         cambiada+="";
      else
      {
         cambiada+=s[i];
         inicio=false;
      }
      i++;
   }
      return cambiada;
}

string rtrim(string s)
{
   string cambiada;
   int espacio=0,i=0,largo=length(s);
   while(s[i]!='\0')
   {
      if(s[i]==' ')
         espacio++;
      else
         espacio=0;
      i++;
   }
   i=0;
   if(espacio!=0)
   {
      while(i<largo-espacio)
      {
         cambiada += s[i];
         i++;
      }
   }
   else
      return s;
   return cambiada;
}

string trim(string s)
{
   string cambiada;
   cambiada= rtrim(s);
   cambiada= ltrim(cambiada);
   return cambiada;
}

string replicate(char c,int n)
{
   string palabra;
   int i=0;
   while(i<n)
   {
      palabra+=c;
      i++;
   }
   return palabra;
}

string spaces(int n)
{
   return replicate(' ',n);
}

string lpad(string s,int n,char c)
{
   string cambiada;
   int i=0,cantidad= n-length(s);
   if(cantidad>0)
      cambiada = replicate(c,cantidad);
   while(s[i]!='\0')
   {
      cambiada+=s[i];
      i++;
   }
   return cambiada;
}

string rpad(string s,int n,char c)
{
   string cambiada;
   int i=0,cantidad= n-length(s);
   while(s[i]!='\0')
   {
      cambiada+=s[i];
      i++;
   }
   if(cantidad>0)
      cambiada += replicate(c,cantidad);
   return cambiada;
}

string cpad(string s,int n,char c)
{
   string cambiada;
   int i=0,cantidad= n-length(s);
   if(cantidad>0)
   {
      if(cantidad%2==0)
         cambiada = replicate(c,cantidad/2);
      else
         cambiada = replicate(c,(cantidad+1)/2);
   }
   while(s[i]!='\0')
   {
      cambiada+=s[i];
      i++;
   }
   if(cantidad>0)
      cambiada += replicate(c,cantidad/2);

   return cambiada;
}

bool isDigit(char c)
{
   bool verdad=false;
   if((c>='0')&&(c<='9'))
      verdad=true;
   return verdad;
}

bool isLetter(char c)
{
   bool verdad=false;
   if(((c>='A')&&(c<='Z'))||((c>='a')&&(c<='z')))
      verdad=true;
   return verdad;
}

bool isUpperCase(char c)
{
   bool verdad=false;
   if((c>='A')&&(c<='Z'))
      verdad=true;
   return verdad;
}

bool isLowerCase(char c)
{
   bool verdad=false;
   if((c>='a')&&(c<='z'))
      verdad=true;
   return verdad;
}

char toUpperCase(char c)
{
   if(isLowerCase(c))
      c=c-32;
   return c;
}

char toLowerCase(char c)
{
   if(isUpperCase(c))
      c=c+32;
   return c;
}

string toUpperCase(string s)
{
   string cambiado;
   int i=0;
   while(s[i]!='\0')
   {
      cambiado+=toUpperCase(char(s[i]));
      i++;
   }
   return cambiado;
}

string toLowerCase(string s)
{
   string cambiado;
   int i=0;
   while(s[i]!='\0')
   {
      cambiado+=toLowerCase(char(s[i]));
      i++;
   }
   return cambiado;
}

int cmpString(string a,string b)
{
   int i=0;

   if(length(a)>length(b))
      return 1;
   else if (length(a)<length(b))
      return -1;
   else
   {
      while(a[i]!='\0')
      {
         if(int(char(a[i]))<int(char(b[i])))
            return -1;
         if(int(char(a[i]))>int(char(b[i])))
            return 1;
         i++;
      }
   }
   return 0;
}

int cmpDouble(double a,double b)
{
   return a-b;
}

#endif
