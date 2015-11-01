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
  alfabeto = " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";  

}

RSA::RSA(ZZ _E, ZZ _N)
{
   E = _E;
   N = _N;
   alfabeto = " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
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

    /*
    cout << "p: " << P << endl;
    cout << "q: " << Q << endl;
    cout << "e: " << E << endl;
    cout << "N: " << N << endl;
    */


    claves.append(N); 
    claves.append(E);
    claves.append(D);    
    return claves;
}

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
   string msj_str =  Vector_String(new_msj, digitos_alfabeto);       
   ZZ bloques , uno;
   uno=1;   
   bloques = Numero_Digitos(N)-uno;
   int num_bloques;
   conv(num_bloques, bloques);   
   int longitud_mensaje = msj_str.length();
    int index_mensaje = 0;
    Vec<string> bloquecitos;
   for(int i=0; i<longitud_mensaje; i=i+num_bloques)
   {
     string bloque_auxiliar="";
     for(int j=0; j<num_bloques; j++)
     {
        if(index_mensaje<longitud_mensaje)
        {          
          bloque_auxiliar+= msj_str[index_mensaje];
          index_mensaje++;
        }
        else
        {         
          bloque_auxiliar+="0";
        }
     }
     bloquecitos.append(bloque_auxiliar);     
   }

   string new_msj_cifrado ="";
   for(int i=0; i<bloquecitos.length(); i++)
   {      
      ZZ bloque_value ;
      bloque_value = String_Num(bloquecitos[i]);      
      ZZ bloque_cifrado;
      bloque_cifrado = exponenciacion(bloque_value, E, N);      
      string bloque_cifrado_string = Num_String(bloque_cifrado);      
      string bloque_cifrado_completado = auto_completar(bloque_cifrado_string, num_bloques+1);      
      new_msj_cifrado+= bloque_cifrado_completado;
   }  
   return new_msj_cifrado;
}

string RSA::decifrar_sin_bloques(Vec<ZZ> mensaje_cifrado)
{
   Vec<ZZ> results; 
   for(int i=0; i<mensaje_cifrado.length(); i++)
   {
     ZZ value;
     value = exponenciacion(mensaje_cifrado[i], E, N);
     results.append(value);

   }   
   string decifrado = Num_to_Text(alfabeto, results);
   return decifrado;
}


string RSA::decifrar_con_bloques(string mensaje_cifrado)
{
   ZZ bloques = Numero_Digitos(N);
   int num_bloques;
   conv(num_bloques, bloques);   
   int longitud_mensaje = mensaje_cifrado.length();
   int index = 0;
   string decifrados="";
   for(int i=0; i<longitud_mensaje; i=i+num_bloques)
   {
      string bloquecito =""; 
      for(int j=0; j<num_bloques; j++)
      {         
         bloquecito+=mensaje_cifrado[index];
         index++;
      }      
      ZZ valor_bloquecito;
      valor_bloquecito = String_Num(bloquecito);      
      ZZ valor_bloquecito_decifrado;
      valor_bloquecito_decifrado = exponenciacion(valor_bloquecito, D, N);            
      string valor_bloquecito_decifrado_string = Num_String(valor_bloquecito_decifrado);       
      string valor_bloquecito_decifrado_string_autocompletado = auto_completar(valor_bloquecito_decifrado_string, num_bloques-1);      
      decifrados+=valor_bloquecito_decifrado_string_autocompletado;
   }
   ZZ digitos_alfabeto = Digitos_Alfabeto(alfabeto);   
   int digitos;
   conv(digitos, digitos_alfabeto);   
   index = 0;   
   string mensaje_decifrado="";
   for(int i=0; i<decifrados.length(); i=i+digitos)
   {
      string value=""; 
      for(int j=0; j<digitos; j++)
      {         
         value+=decifrados[index];
         index++;
      }      
      ZZ posicion;
      posicion = String_Num(value);  
      int val_posicion;
      conv(val_posicion, posicion);              
      char a = Find(alfabeto, val_posicion);
      mensaje_decifrado+=a;
   }    
    return mensaje_decifrado;
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