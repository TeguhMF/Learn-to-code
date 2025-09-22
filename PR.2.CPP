// NAMA : TEGUH MAULANA FIRMANSYAH (241011401348) 
// KELAS : 03TPLP035 

#include <iostream>
using namespace std;

int main () {
    int a = 10;
    unsigned int b = 20;
    float c = 3.14f;
    double d = 6.28;
    long e = 1000;
    char f = 'A';
    bool g = true;

    cout << "\n===== Alamat Variabel =====" << endl;
    cout << "a (int)           : " << &a << endl;
    cout << "b (unsigned int)  : " << &b << endl;
    cout << "c (float)         : " << &c << endl;
    cout << "d (double)        : " << &d << endl;
    cout << "e (long)          : " << &e << endl;
    cout << "f (char)          : " << (void*)&f << endl; 
    cout << "g (bool)          : " << &g << endl;

    return 0;

}