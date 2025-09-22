// NAMA : TEGUH MAULANA FIRMANSYAH (241011401348) 
// KELAS : 03TPLP035 

#include <iostream>
using namespace std;

int main() {
    int a = 10;
    unsigned int b = 20;
    float c = 3.14f;
    double d = 6.28;
    long e = 1000;
    char f = 'A';
    bool g = true;

    cout << "===== Ukuran Tipe Data =====" << endl;
    cout << "int           : " << sizeof(a) << " byte" << endl;
    cout << "unsigned int  : " << sizeof(b) << " byte" << endl;
    cout << "float         : " << sizeof(c) << " byte" << endl;
    cout << "double        : " << sizeof(d) << " byte" << endl;
    cout << "long          : " << sizeof(e) << " byte" << endl;
    cout << "char          : " << sizeof(f) << " byte" << endl;
    cout << "bool          : " << sizeof(g) << " byte" << endl;

    return 0;
}
