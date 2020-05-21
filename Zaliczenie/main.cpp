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
    using namespace std::chrono;
    typedef std::chrono::minutes min;
    
    steady_clock::time_point czas1 = steady_clock::now();
    function();
    steady_clock::time_point czas2 = steady_clock::now();

    duration<double> czas = duration_cast<duration<double>>(czas2 - czas1);
    
    min d = std::chrono::duration_cast<min>(czas);//przelicza na minuty

    auto duration = czas.count();//zapisuje do starej w sekundach

    std::cout << d.count() << " min("<<duration<<"s)\n";
    return 0;

}