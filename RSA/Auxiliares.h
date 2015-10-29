#ifndef AUXILIARES_H
#define AUXILIARES_H

#include <NTL/ZZ.h>
#include <NTL/vector.h>

using namespace NTL;

ZZ potencia (ZZ num1 , ZZ num2)
{
    ZZ r;
    r = 1;
    for (long long i = 0 ; i < num2; i++)
    {
        r = r * num1;
    }
    return r;
}

ZZ exponenciacion (ZZ a , ZZ p , ZZ n)
{
   ZZ t , expo , unidad;
   expo = 2;
   unidad = 1;
    if(p == 0)
        return unidad;
    if(p % 2 == 0)
    {
       t = exponenciacion(a, p/2, n);
       return (potencia(t, expo)) % n;
    }
    t = exponenciacion(a, (p-1)/2, n);
    return (a*(potencia(t, expo) % n)) % n;
}

bool es_Primo (ZZ numero)
 {
    ZZ y , expo;
    expo = 2;
    if (numero <= 2 && numero >= 0)
        return true;
    else
    {
        y = exponenciacion (expo,numero-1,numero);
        if (y == 1)
            return true;
    }
    return false;
 }

 Vec<ZZ> Euclides_Extendido(ZZ a , ZZ b)
{
  int i;
  i = 0;
    Vec <ZZ> k, n, q, r, vec;
    k.append(a);
    n.append(b);
    
    do{
     
        q.append(k[i] / n[i]);
        r.append(k[i] - q[i] * n[i]);
        k.append(n[i]);
        n.append(r[i]);
        i++;
    }while (r[i-1] != 0);
    i--;
    vec.append(n[i]);
    Vec <ZZ> x , z; 
    x.SetLength(i+1);
    z.SetLength(i+1);
            
    ZZ a1,b1;
    x[i] = 0;
    z[i] = 1;
    i--;
    
    while(i >= 0)
    {
        x[i] = z[i+1];
        z[i] = x[i+1] - q[i]*z[i+1];         
        a1 = x[i];
        b1 = z[i];
        i--;
    }
    vec.append(a1);
    vec.append(b1);
    return vec;    
}

ZZ Inversa(ZZ mod, ZZ a)
{
  Vec <ZZ> inv; 
  inv = Euclides_Extendido(mod , a);
  ZZ inver;
  inver =  inv[2];
  if (inver < 0)     
     {
        inver = mod + inver;
        return inver;
     }
   else return inver;
}

Vec<ZZ> Text_to_Num(string alfabeto, string mensaje)
{
   Vec<ZZ> result;

   for(int i=0; i<mensaje.length(); i++) 
   {
     ZZ numero;
     numero = alfabeto.find(mensaje[i]);
     result.append(numero);
   }
   return result;        
}




#endif