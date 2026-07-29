#include <iostream>
#include <time.h>
#include <fstream>


using namespace std;


int main () {
    srand(time(NULL));
    ofstream arquivo ("entrada_desordenada.txt");

    int QuantNumeros = 500000000;//1.000.000 dá aprox. 4MB

    for(int i =0; i < QuantNumeros; i++) {
        arquivo << rand() % 100 << " ";
    }


    arquivo.close();
    return 0;
}