#include <iostream>
#include <chrono>
#include <cmath>

#include <ctime>
#include <ratio>

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
cout<<"adsf";

}