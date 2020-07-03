#include <omp.h>
#include <iostream>
#include <list>
using namespace std;

void fun( int t ) {
}

int main () {

    list<string> l { "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","R","S","T","U","V","W" };
    string tmp, buf;

    auto it = l.begin();
#pragma omp parallel num_threads(4)
{

    // Wyslij ponizsze iteracje petli while 
    // do odrebnych zadan (task) ale tak
    // zeby rownolegle wykonanie bylo zabezpieczone
    // przed data race i wynik koncowy poprawny

// tu budowanie taskow
    while ( it != l.end() ) {
// tu delegacja do tasku
buf += *it; // to wyslij do task i zabezpiecz
// tu jeszcze trzeba postawic punkt synchronizacji
       ++it;
    }

}

    cout << buf << endl;;
    // ABCDEFGHIJKLMNOPRSTUVW

}

