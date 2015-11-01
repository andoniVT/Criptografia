//#ifndef CIFRADOS_H
//#define CIFRADOS_H

//g++ -I$HOME/sw/include cifrados.cpp -o out  -L$HOME/sw/lib -lntl  -lm


#include <iostream>
using namespace std;
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand (time(NULL));

    /*
    string mensaje = "Hola#amigos#mios#como#estan";
    CarrilValla cv(mensaje, 5);
    mensaje =  cv.cifrar();

    cv.imprime();
    cout << mensaje << endl;*/

    //string mensaje = "Holaamigos";
    //Ruta r (mensaje, 6, 5);
    //Ruta r (mensaje, 3, 4);
    //r.cifrar();
    cout << "Hola mundo!" << endl;



    return 0;
}





//#endif