#include <iostream>
#include <string>
using namespace std;
#define MAX 5
string queue[MAX];
int FRONT = -1, REAR = -1;

void display() {
    if (FRONT == -1)
        cout << "Queue kosong.\n";
    else {
        cout << "Isi Queue: ";
        for (int i = FRONT; i <= REAR; i++) {
            if (i == FRONT) cout << "[F->" << queue[i] << "] ";
            else if (i == REAR) cout << "[R->" << queue[i] << "] ";
            else cout << "[" << queue[i] << "] ";
        }
        cout << endl;
    }
}
void insert(string data) {
    if (REAR == MAX - 1)
        cout << "Queue penuh, tidak bisa INSERT \"" << data << "\"\n";
    else {
        if (FRONT == -1) FRONT = 0;
        REAR++;
        queue[REAR] = data;
        cout << "INSERT \"" << data << "\" berhasil.\n";
    }
}
void remove() {
    if (FRONT == -1)
        cout << "Queue kosong, tidak bisa DELETE.\n";
    else {
        cout << "DELETE \"" << queue[FRONT] << "\" berhasil.\n";
        if (FRONT == REAR) {
            FRONT = -1; REAR = -1;
        } else FRONT++;
    }
}
void reset() {
    FRONT = -1; REAR = -1;
    cout << "Queue berhasil di-reset.\n";
}

int main() {
    cout << "===== PROGRAM LINEAR QUEUE =====\n";
    cout << "Nama : Teguh Maulana Firmansyah\n";
    cout << "NIM  : 241011401348\n";
    cout << "Studi Kasus: Antrian Pemesanan Tiket Bus\n";
    cout << "================================\n";

    int pilihan;
    string data;

    do {
        cout << "\n=== MENU ANTRIAN ===\n";
        cout << "1. INSERT (tambah)\n";
        cout << "2. DELETE (hapus)\n";
        cout << "3. DISPLAY (lihat isi)\n";
        cout << "4. RESET (kosongkan)\n";
        cout << "0. KELUAR\n";
        cout << "Pilih: "; cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nama: "; cin >> data;
                insert(data);
                break;
            case 2:
                remove();
                break;
            case 3:
                display();
                break;
            case 4:
                reset();
                break;
            case 0:
                cout << "Selesai.\n"; break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 0);

    return 0;
}