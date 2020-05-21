#include <iostream>
#include <omp.h>

using namespace std;

int main(){
    #pragma omp parallel num_threads(8)
    {

        int ID = omp_get_thread_num();
        
        cout << "Watek to: "<< ID << endl;

    }
}
