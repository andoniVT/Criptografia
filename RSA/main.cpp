
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
	
	cout << "Hello World!" << endl;
   /*
	ZZ x;
	x = RandomBnd(1234567890123456789);
	cout << x << endl;
	*/

   Generador g(20);
   cout << g.aleatorio_simple() << endl ;


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