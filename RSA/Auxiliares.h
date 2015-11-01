#ifndef AUXILIARES_H
#define AUXILIARES_H

#include <NTL/ZZ.h>
#include <NTL/vector.h>
#include <sstream>
#include <string>

using namespace NTL;


ZZ generar_aleatorio(ZZ abajo, ZZ arriba)
{
    ZZ x;
    x = RandomBnd(arriba);        
    if(x < abajo) x = x + abajo; 
    return x;
}

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

string Num_to_Text(string alfabeto, Vec<ZZ> mensaje)
{
   int tam = mensaje.length();
   string tmp;
   for(int i=0; i<tam; i++)
   {
      ZZ value;
      value =  mensaje[i];
      long  val;
      conv(val, value);
      tmp.push_back(alfabeto[val]);   
   }
   return tmp;
}

char Find(string alfabeto, int posicion)
{    
    return alfabeto[posicion];
}

ZZ Numero_Digitos(ZZ num)
{
    ZZ c;
    c=1;
    while(num>=10)
    {
        c++;
        num = num/10;
    }
    return c;
}

ZZ Digitos_Alfabeto(string alfabeto)
{
  ZZ longitud;
  longitud = alfabeto.length();
  ZZ result;
  result = Numero_Digitos(longitud);  
  return result;
}

string Vector_String(Vec<ZZ> vec, ZZ r)
{
    string auxiliar="";
    ZZ x , y , aux;
    aux = 10;
    x = potencia (aux , r-1);    
    y = Numero_Digitos(x);
    for(int i=0; i<vec.length(); i++)
    {
        string s;
        stringstream buffer;
        buffer << vec[i];
        s = buffer.str();
        ZZ ti;
        ti = Numero_Digitos(vec[i]);
        
        while(ti<y)
        {
            s.insert(0, "0");
            ti++;
        }
        auxiliar+=s;
    }
    return auxiliar;
}

ZZ Vec_Num(Vec<ZZ> valores)
{
    ZZ aux , resultado , pot;
    pot=10;
    aux=0;
    int longitud = valores.length() , auxiliar = longitud-1;
    ZZ value;
    conv(value, auxiliar);
    for(int i=0; i<longitud; i++)
    {
        resultado = valores[i] * potencia(pot, value);
        auxiliar--;
        aux = resultado + aux;
    }
    return aux;
}


Vec<ZZ> Converter(string vec, ZZ bloques)
{
    int bloquess; 
    conv(bloquess, bloques);    
    int longitud = vec.length();
    Vec<ZZ> result_bloques, result_converter;
    ZZ auxiliar , convertido;
    string mi_aux;
    
    for(int i=0; i<longitud; i=i+bloquess)
    {
        for(int j=i; j<i+bloquess; j++)
        {
            if(j>=longitud) break;

            mi_aux = vec[j];            
            conv(auxiliar, mi_aux.c_str());
            //cout << mi_aux <<" - " << auxiliar << endl;            
            result_bloques.append(auxiliar);
        }
        convertido = Vec_Num(result_bloques);        
        result_converter.append(convertido);
        result_bloques.SetLength(0);
    }
    return result_converter;
}

ZZ String_Num(string numero)
{
   ZZ result;
   conv(result, numero.c_str());
   return result;
}

string Num_String(ZZ numero)
{
    string result;     
    stringstream buffer;
    buffer << numero;
    result = buffer.str();
    return result;
}

string auto_completar(string value, int n)
{
    int faltan = n - value.length();
    string result = "";
    for(int i=0; i<faltan; i++)
    {
        result+="0";
    }
    return result + value;
}



#endif