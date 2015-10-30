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
     ZZ lon ;
     lon = Numero_Digitos(value);
     cout << lon << endl;
     mensaje_cifrado.append(value);
   }   
   return mensaje_cifrado;
}

string RSA::cifrar_con_bloques(string mensaje)
{
   ZZ digitos_alfabeto;
   digitos_alfabeto =  Digitos_Alfabeto(alfabeto);
   Vec<ZZ> new_msj;
   new_msj = Text_to_Num(alfabeto, mensaje);      
   //cout << new_msj << endl;
   string msj_str =  Vector_String(new_msj, digitos_alfabeto);   
   
   
   ZZ bloques , uno;
   uno=1;   
   bloques = Numero_Digitos(N)-uno;
   
   Vec<ZZ> msj_a_cifrar;
  
   msj_a_cifrar = Converter(msj_str, bloques);
   //for(int i=0; i<msj_a_cifrar.length(); i++) cout << msj_a_cifrar[i] << " ";
    //cout << endl;

   int longitud = msj_a_cifrar.length();
   ZZ aux1 , aux2;
   Vec<ZZ> msj_cifrado;

   for(int i=0; i<longitud; i++)
   {
      aux1 = msj_a_cifrar[i];
      aux2 = exponenciacion(aux1, E, N);
      msj_cifrado.append(aux2);
   }

   ZZ digitos_N;
   digitos_N = Numero_Digitos(N);
   string new_msj_cifrado = Vector_String(msj_cifrado, digitos_N);

   return new_msj_cifrado;
}

string RSA::decifrar_sin_bloques(Vec<ZZ> mensaje_cifrado)
{
   Vec<ZZ> results; 
   for(int i=0; i<mensaje_cifrado.length(); i++)
   {
     ZZ value;
     value = exponenciacion(mensaje_cifrado[i], D, N);
     results.append(value);

   }   
   string decifrado = Num_to_Text(alfabeto, results);
   return decifrado;
}


string RSA::decifrar_con_bloques(string mensaje_cifrado)
{
   ZZ bloques = Numero_Digitos(N);
   Vec<ZZ> cifra_a_num ;
   cifra_a_num = Converter(mensaje_cifrado, bloques);
   
    int  longitud = cifra_a_num.length();
    ZZ aux1, aux2;
    Vec<ZZ> result_previo;
    for(int i=0; i<longitud; i++)
    {
      aux1 = cifra_a_num[i];
      aux2 = exponenciacion(aux1, D, N);
      result_previo.append(aux2);
    }

    string new_resultado_previo = Vector_String(result_previo, bloques-1);
    ZZ digitos_alfabeto;
    digitos_alfabeto = Digitos_Alfabeto(alfabeto);
    Vec<ZZ> decifrado;
    decifrado = Converter(new_resultado_previo, digitos_alfabeto);
   for(int i=0; i<decifrado.length();i++) cout << decifrado[i] << " "; 

    string res = Num_to_Text(alfabeto, decifrado);
    cout << res << endl;

    cout << endl;
    return "decifrado";
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