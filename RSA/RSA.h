#ifndef RSA_H
#define RSA_H
#include <NTL/ZZ.h>
#include <NTL/vector.h>

using namespace NTL;
#include "Generador.h"


class RSA
{
  private:
	ZZ P, Q, N, phiN, E, D; 
	string alfabeto;    
	int numero_bits;
  Vec <ZZ> mis_claves;


  public:
	RSA(int _numero_bits);
	RSA(ZZ _E, ZZ _N);

	Vec<ZZ> cifrar_sin_bloques(string mensaje);
  string cifrar_con_bloques(string mensaje);


	Vec<ZZ> generar_claves();

	string decifrar_sin_bloques(Vec<ZZ> mensaje_cifrado);
  string decifrar_con_bloques(string mensaje_cifrado);

	void set_E(ZZ numero);
	void set_D(ZZ numero);
	void set_N(ZZ numero);

	~RSA();	
};

RSA::RSA(int _numero_bits)
{
  numero_bits = _numero_bits;
  //mis_claves = generar_claves();
  alfabeto = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ";  

}

RSA::RSA(ZZ _E, ZZ _N)
{
   E = _E;
   N = _N;
   alfabeto = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ";
}

Vec<ZZ> RSA::generar_claves()
{
   Generador g(numero_bits);
    P =  g.aleatorio_simple();
    Q =  g.aleatorio_simple();
    N = P * Q ;
    phiN = (P-1) * (Q-1);
    E = g.aleatorio_simple();
    
    while(E<1 && E>phiN)
      E = g.aleatorio_simple();
    D = Inversa(phiN, E);  
    Vec<ZZ> claves;
    claves.append(N); 
    claves.append(E);
    claves.append(D);    
    return claves;
}

//string RSA::cifrar_sin_bloques(string mensaje)
Vec<ZZ> RSA::cifrar_sin_bloques(string mensaje)
{
   Vec<ZZ> new_mensaje = Text_to_Num(alfabeto, mensaje);   
   Vec<ZZ> mensaje_cifrado;

   for(int i = 0; i<new_mensaje.length(); i++)
   {     
     ZZ value;
     value = exponenciacion (new_mensaje[i] , E , N);
     mensaje_cifrado.append(value);
   }
   
   return mensaje_cifrado;


}

string RSA::cifrar_con_bloques(string mensaje)
{
   
}




string RSA::decifrar_sin_bloques(Vec<ZZ> mensaje_cifrado)
{
   for(int i=0; i<mensaje_cifrado.length(); i++)
   {
     ZZ value;
     value = exponenciacion(mensaje_cifrado[i], D, N);
     cout << value << " ";

   }
   cout << endl;
   return "";
}


string RSA::decifrar_con_bloques(string mensaje_cifrado)
{

}

void RSA::set_E(ZZ numero)
{
    E = numero; 
}

void RSA::set_D(ZZ numero)
{
    D = numero;
}

void RSA::set_N(ZZ numero)
{
   N = numero;
}

RSA::~RSA(){}

#endif