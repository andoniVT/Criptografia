
// g++ -I$HOME/sw/include main.cpp -o out  -L$HOME/sw/lib -lntl  -lm
#include <iostream>
using namespace std;
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <NTL/ZZ.h>
#include "RSA.h"


int main()
{

         
   int numero_bits = 64;
   RSA receptor(numero_bits);
   Vec<ZZ> claves;
   claves = receptor.generar_claves();
   ZZ  N, E, D;
   N = claves[0];
   E = claves[1];
   D = claves[2];
    

   RSA emisor(E,N);
   string mensaje = "hola jorge andoni valverde tohalino";
   
   string mensaje_cifrado;
   mensaje_cifrado = emisor.cifrar_con_bloques(mensaje);   
   cout << mensaje_cifrado << endl;
   

   

   cout << "DECIFRADO" << endl;

   string mensaje_decifrado = receptor.decifrar_con_bloques(mensaje_cifrado);
   cout << mensaje_decifrado << endl;

      

   













/*
	ZZ value , a , b , c;
	 a = 1 ; 
	 b = 18912;
	 c = 5;
	*/
	//value = potencia(a,b);
	//value = exponenciacion (a , b , c);

	//cout << es_Primo(a) << endl;

	/*

         //////// EMISOR /////////   (El que va a cifrar el mensaje)
         RSA emisor(E,N);
         emisor.set_E(numero); //  AKI va el "e" del que va a ver el mensaje mensaje q le voy a enviar
         emisor.set_N(numero); //  AKI va el "N" del que va a ver el mensaje mensaje q le voy a enviar
         string mensaje = ""; // Mensaje que el emisor va a cifrar

         string cifrado = emisor.Cifrado(mensaje);
         cout << "Mensaje cifrado: " << cifrado << endl;
			

         
         //////// RECEPTOR /////////      
         RSA receptor;
         string mensaje_cifrado="........." ;
         N,E,D = receptor.genear_claves();
         receptor.set_N(numero);  // Aki va mi "N"  para decifrar solo el mensaje
         receptor.set_D(numero), // Aki va mi "D" para decifrar solo el mensaje
         string mensaje_decifrado = receptor.Decifrado();
         cout << "mensaje decifrado: " << mensaje_decifrado << endl;



	*/




	return 0;
}