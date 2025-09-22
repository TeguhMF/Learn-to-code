#include <iostream>
using namespace std;

const int MAX = 10; 
struct Buku {
    int id;
    string judul;
};

Buku rak[MAX];
int top = -1;

bool isFull() {
    return top == MAX - 1;
}
bool isEmpty() {
    return top == -1;
}

void push(Buku b) {
    if (isFull()) {
        cout << "Rak penuh! Tidak bisa menambah buku.\n";
    } else {
        top++;
        rak[top] = b;
        cout << "Buku \"" << b.judul << "\" berhasil ditambahkan.\n";
    }
}

void pop() {
    if (isEmpty()) {
        cout << "Rak kosong! Tidak ada buku yang bisa diambil.\n";
    } else {
        cout << "Buku \"" << rak[top].judul << "\" telah diambil.\n";
        top--;
    }
}

void peek() {
    if (isEmpty()) {
        cout << "Rak kosong! Tidak ada buku di atas.\n";
    } else {
        cout << "Buku teratas: [ID: " << rak[top].id
             << "] " << rak[top].judul << endl;
    }
}
void display() {
    if (isEmpty()) {
        cout << "Rak kosong!\n";
    } else {
        cout << "\nIsi rak buku (dari bawah ke atas):\n";
        for (int i = 0; i <= top; i++) {
            cout << i + 1 << ". [ID: " << rak[i].id
                 << "] " << rak[i].judul << endl;
        }
    }
}

int main() {
    int pilihan;
    do {
        cout << "\n=== MENU PERPUSTAKAAN ===\n";
        cout << "1. Tambah Buku (PUSH)\n";
        cout << "2. Ambil Buku (POP)\n";
        cout << "3. Lihat Buku Teratas (PEEK)\n";
        cout << "4. Tampilkan Semua Buku\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1: {
            Buku b;
            cout << "Masukkan ID Buku: ";
            cin >> b.id;
            cin.ignore();
            cout << "Masukkan Judul Buku: ";
            getline(cin, b.judul);
            push(b);
            break;
        }
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            cout << "Keluar dari program.\n";
            break;
        default:
            cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 5);
    return 0;
}
