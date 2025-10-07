//LINEAR QUEUE//
#include <iostream>
using namespace std;

class CircularQueue {
private:
    int *arr;       // array untuk menyimpan elemen
    int front;      // indeks elemen depan
    int rear;       // indeks elemen belakang
    int capacity;   // kapasitas maksimum queue
    int size;       // jumlah elemen saat ini

public:
    // Konstruktor
    CircularQueue(int cap = 5) {
        capacity = cap;
        arr = new int[capacity];
        front = -1;
        rear = -1;
        size = 0;
    }
    // Destruktor
    ~CircularQueue() {
        delete[] arr;
    }
    // Fungsi untuk mengecek apakah queue kosong
    bool isEmpty() {
        return size == 0;
    }
    // Fungsi untuk mengecek apakah queue penuh
    bool isFull() {
        return size == capacity;
    }
    // Fungsi enqueue (menambah elemen)
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue penuh! Tidak dapat menambahkan " << value << endl;
            return;
        }
        if (isEmpty()) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }
        arr[rear] = value;
        size++;
        cout << "Berhasil menambahkan: " << value << endl;
        displayQueue();
    }
    // Fungsi dequeue (mengeluarkan elemen)
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue kosong! Tidak dapat mengeluarkan elemen" << endl;
            return -1;
        }
          int value = arr[front];      
        if (front == rear) {
            // Hanya satu elemen tersisa
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % capacity;
        }

        size--;
        cout << "Berhasil mengeluarkan: " << value << endl;
        displayQueue();
        return value;
    }
    // Fungsi untuk menampilkan isi queue
    void displayQueue() {
        if (isEmpty()) {
            cout << "Queue: [kosong]" << endl;
            return;
        }

        cout << "Queue: [";
        int i = front;
        int count = 0;
        
        while (count < size) {
            cout << arr[i];
            if (count < size - 1) {
                cout << ", ";
            }
            i = (i + 1) % capacity;
            count++;
        }
        cout << "]" << endl;
        
        cout << "Front: " << front << ", Rear: " << rear << ", Size: " << size << endl;
        cout << "------------------------" << endl;
    }
    // Fungsi untuk mendapatkan elemen depan tanpa menghapus
    int peek() {
        if (isEmpty()) {
            cout << "Queue kosong!" << endl;
            return -1;
        }
        return arr[front];
    }
};
// Contoh penggunaan
int main() {
    CircularQueue queue(5);
    
    cout << "=== IMPLEMENTASI CIRCULAR QUEUE ===" << endl;
    cout << "Kapasitas: 5 elemen" << endl;
    cout << "================================" << endl;
    
    // Urutan operasi sesuai permintaan
    cout << "\n1. enqueue(10)" << endl;
    queue.enqueue(10);
    
    cout << "\n2. enqueue(24)" << endl;
    queue.enqueue(24);
    
    cout << "\n3. dequeue()" << endl;
    queue.dequeue();
    
    cout << "\n4. enqueue(30)" << endl;
    queue.enqueue(30);
    
    cout << "\n5. enqueue(40)" << endl;
    queue.enqueue(40);
    
    cout << "\n6. enqueue(50)" << endl;
    queue.enqueue(50);
    
    cout << "\n7. enqueue(50)" << endl;
    queue.enqueue(50); // Akan ditolak karena penuh
    
    cout << "\n8. dequeue()" << endl;
    queue.dequeue();
    
    return 0;
}