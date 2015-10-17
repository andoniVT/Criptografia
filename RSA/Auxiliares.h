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



#endif