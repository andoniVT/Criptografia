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

  public:
	RSA(int _numero_bits);
	RSA(ZZ _E, ZZ _N);

	string cifrar(string mensaje);


	Vec<ZZ> generar_claves();
	string decifrar(string mensaje_cifrado);

	void set_E(ZZ numero);
	void set_D(ZZ numero);
	void set_N(ZZ numero);

	~RSA();	
};

RSA::RSA(int _numero_bits)
{

}

RSA::RSA(ZZ _E, ZZ _N)
{

}

string RSA::cifrar(string mensaje)
{

}

Vec<ZZ> RSA::generar_claves()
{

}

string RSA::decifrar(string mensaje_cifrado)
{

}

void RSA::set_E(ZZ numero)
{

}

void RSA::set_D(ZZ numero)
{

}

void RSA::set_N(ZZ numero)
{

}

RSA::~RSA()
{

}



#endif
