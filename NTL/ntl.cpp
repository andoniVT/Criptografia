
// g++ -I$HOME/sw/include ntl.cpp -o foo  -L$HOME/sw/lib -lntl  -lm
#include <iostream>
using namespace std;
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <NTL/ZZ.h>
#include <NTL/vector.h>
using namespace std;
using namespace NTL;

ZZ sum(const Vec<ZZ>& v)
{
   ZZ acc;

   acc = 0;

   for (long i = 0; i < v.length(); i++)
      acc += v[i];

   return acc;
}


int main()
{
	
   Vec<ZZ> v;
   ZZ a,b,c;
   a = 2;
   b=3;
   c=4;
   v.append(a);    
   v.append(b);
   v.append(c);

   for(int i=0; i<v.length(); i++)
   {
      cout << v[i] / 2 << endl;
   }


    /*
    ZZ a, b, c; 
    cin >> a; 
    cin >> b; 
    c = (a+1)*(b+1);
    cout << c << "\n";

    
    ZZ acc, val;
    acc = 0;
    while (cin >> val) 
       acc += val*val;
   cout << acc << "\n";*/





	return 0;
}