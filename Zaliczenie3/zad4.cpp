#include <omp.h>
#include <iostream>
#include <string>
using namespace std;

int main () {

string buf;
char c = 'a';

// Stworz i zainicjalizuj obiekt typu 
// omp_lock_t
// Nastepnie zabezpiecz za jego pomoca
// operacje w sekcjach, na koniec 
// zwolnij zasoby obiektu omp_lock_t


omp_lock_t lck;   
omp_init_lock(&lck);

#pragma omp parallel num_threads(2)
{
    #pragma omp sections nowait
    {
       #pragma omp section
       {
          omp_set_lock(&lck);
          buf += c++;
          buf += c++;
          omp_unset_lock(&lck);
       }

       #pragma omp section
       {
          omp_set_lock(&lck);
          buf += c++;
          buf += c++;
          omp_unset_lock(&lck);
       }
    }  
} 
omp_destroy_lock(&lck); 
cout << buf << endl;
}
