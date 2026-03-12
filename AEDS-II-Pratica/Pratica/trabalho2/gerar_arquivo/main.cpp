#include <iostream>
#include <time.h>
#include <fstream>


using namespace std;


int main () {
    srand(time(NULL));
    ofstream arquivo ("output.txt");

    for(int i =0; i < 5000000; i++) {
        arquivo << rand() % 100 << " ";
    }

    arquivo.close();
    return 0;
}