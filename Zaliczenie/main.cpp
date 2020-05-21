#include <iostream>
#include <chrono>
#include <cmath>
using namespace std;

void function()
{   // funkcja wykonuje jakies bezsensowne, ale obciazajace obliczenia
    double number { 0. };
    #pragma omp parallel for reduction(+:number) num_threads(4)
    for( long long i = 0; i != 200000000; ++i )
    {
       number += sin( static_cast<double>(i) / (i+1) );
    }
}

int main()
{
    // odczytaj czas poczatkowy
    function();
    // odczytaj czas koncowy

    auto duration = 0; // w miejsce 0 wpisz odpowiednie wyrazenie z duration przeliczajacym na minuty

    std::cout << "Czas wykonania: = " << duration << endl;
    return 0;
}