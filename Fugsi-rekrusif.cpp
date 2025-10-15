// Teguh Maulana Firmansyah (241011401348)
// 14-10-2025
//program fungsi rekursi
#include <iostream>
using namespace std;

int genap(int);
int faktorial(int);
int perkalian(int, int);
int pangkat(int, int);

int main ()
{
    char lagi;
    do {
        int k, x, y;
        
        cout <<"masukan k (untuk genap dan faktorial) = "; cin>>k;
        cout<<" genap ke-" <<k<< " adalah " <<genap(k) << endl;
        cout<<" faktorial dari " <<k<< " adalah " <<faktorial(k) << endl;
        cout << "\nmasukan x untuk perkalian: "; cin >> x;
        cout << "masukan y untuk perkalian: "; cin >> y;
        cout<<" perkalian dari " <<x<< " * " <<y<< " adalah " <<perkalian(x, y) << endl;
        cout << "\nmasukan x (basis) untuk pangkat: "; cin >> x;
        cout << "masukan y (eksponen) untuk pangkat: "; cin >> y;
        cout<<" pangkat dari " <<x<< " pangkat " <<y<< " adalah " <<pangkat(x, y) << endl;
        cout<<"\nlagi y/n = "; cin>>lagi;
    } while (lagi=='y' || lagi=='Y'); 
    
    return 0;
}
int genap(int n)
{
    if (n==1) return 0;
    return (2 + genap(n-1));
}
int faktorial(int n)
{
    if (n <= 1) return 1;
    return n * faktorial(n - 1);
}
int perkalian(int x, int y)
{
    if (y == 0) return 0;
    return x + perkalian(x, y - 1);
}
int pangkat(int a, int b)
{
    if (b == 0) return 1;
    return a * pangkat(a, b - 1);
}
