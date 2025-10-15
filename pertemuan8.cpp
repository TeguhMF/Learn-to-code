#include <iostream>
#include <string>
using namespace std;

#define MAX 9
string deque[MAX];
int front = -1, rear = -1;

bool isFull() {
    return (front == 0 && rear == MAX - 1) || (rear + 1 == front);
}

bool isEmpty() {
    return front == -1;
}

void insertKanan(string nama) {
    if (isFull()) {
        cout << "Antrian penuh dari kanan! Proses pengisian dihentikan.\n";
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else if (rear == MAX - 1) {
        rear = 0;
    } else {
        rear++;
    }

    deque[rear] = nama;
}

void tampil() {
    if (isEmpty()) {
        cout << "Antrian kosong\n";
        return;
    }
    cout << "\nIsi Antrian: ";
    int i = front;
    while (true) {
        cout << deque[i] << " ";
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    cout << "\n";
}

int main() {
    string nama;
    cout << "=== Program Double Ended Queue (Pengisian dari kanan, max 9 nama) ===\n";

    for (int i = 1; i <= MAX; i++) {
        if (isFull()) {
            cout << "⚠️  Antrian penuh. Tidak bisa menambah data lagi.\n";
            break;
        }

        cout << "Masukkan nama ke-" << i << ": ";
        getline(cin >> ws, nama);  // ws agar bisa membaca spasi
        insertKanan(nama);
    }

    tampil();

    cout << "\n✅ Pengisian selesai (maksimum 9 nama atau penuh kanan).\n";
    return 0;
}
