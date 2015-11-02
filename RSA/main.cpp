
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

   //string texto = read_file("Textos/texto.txt");
   //cout << texto << endl;
   //write_file("Textos/prueba.txt", texto);


   
   int numero_bits = 64;
   RSA receptor(numero_bits);
   Vec<ZZ> claves;
   claves = receptor.generar_claves();
   ZZ  N, E, D;
   N = claves[0];
   E = claves[1];
   D = claves[2];
    

   RSA emisor(E,N);
   //string mensaje = "hola jorge andoni valverde tohalino";
   string mensaje = read_file("Textos/texto.txt");
   
   string mensaje_cifrado;
   mensaje_cifrado = emisor.cifrar_con_bloques(mensaje);   
   cout << mensaje_cifrado << endl;
   write_file("Textos/cifrado.txt", mensaje_cifrado);
   

   

   cout << "DECIFRADO" << endl;

   string mensaje_decifrado = receptor.decifrar_con_bloques(mensaje_cifrado);
   cout << mensaje_decifrado << endl;
   write_file("Textos/decifrado.txt", mensaje_decifrado);

   

      


	return 0;
}