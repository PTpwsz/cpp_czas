#include <omp.h>
#include <iostream>
using namespace std;

int main () {

   int i, j, k;
   int suma = 0;

   // Pomimo zabezpieczenia operacji powiekszania zmiennej suma
   // wynik na koncu jest niepoprawny (powinno byc 1000).
   // Jak trzeba zmodyfikowac ponizszy blok (dopisujac
   // odpowiednie klauzule). Ponadto "splaszcz" potrojne
   // petle rowniez za pomoca odpowiedniej klauzuli.

   #pragma omp parallel for collapse(3) reduction(+: suma) num_threads(4) 
   for (i = 0; i < 10; ++i)
     for (j = 0; j < 10; ++j)
     for (k = 0; k < 10; ++k)
       {
           // operacje trzeba zabezpieczyc
           ++suma;
       }

   cout << "Suma = " << suma << endl;
}
