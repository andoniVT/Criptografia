#ifndef GENERADOR_H
#define GENERADOR_H

#include <NTL/ZZ.h>
#include <NTL/vector.h>

using namespace NTL;

#include "Auxiliares.h"

class Generador
{
 private:	
   ZZ P, Q;
   int bits;
 public:
	Generador(int _bits);
	ZZ aleatorio_simple();
	ZZ lfsr();
	ZZ criba_erathostenes();
	ZZ test_fermat();
	~Generador();	
};

Generador::Generador(int _bits)
{
   bits = _bits;
}

ZZ Generador::aleatorio_simple()
{
  ZZ x;  
  while(true)
  {
  	x = RandomBnd(1234567890123456789); 
  	if(es_Primo(x))
  		return x;
  }
}

ZZ Generador::lfsr()
{

}

ZZ Generador::criba_erathostenes()
{
 
}

ZZ Generador::test_fermat()
{

}

Generador::~Generador()
{

}

#endif