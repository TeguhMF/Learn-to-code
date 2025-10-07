#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <limits>

namespace fs = std::filesystem;
using namespace std;

void clear_input() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void showmenu() {
    cout << "\n=== SISTEM BERKAS SEDERHANA ===\n";
    cout << "1. Buat file baru\n";
    cout << "2. Daftar file (di folder kerja)\n";
    cout << "3. Baca isi file\n";
    cout << "4. Hapus file\n";
    cout << "5. Ganti nama file\n";
    cout << "6. Keluar\n";
    cout << "Pilih (1-6): ";
}

void buatfile() {
    string filename;
    cout << "Masukkan nama file (contoh: data.txt): ";
    clear_input();
    getline(cin, filename);

    if (filename.empty()) {
        cout << "Nama file tidak boleh kosong.\n";
        return;
    }

    if (fs::exists(filename)) {
        cout << "File sudah ada. Apakah ingin menimpa? (y/n): ";
        char c;
        cin >> c;
        if (c != 'y' && c != 'Y') {
            clear_input();
            return;
        }
        clear_input();
    }

    cout << "Masukkan isi file (akhiri dengan .done):\n";
    ofstream ofs(filename);
    if (!ofs) {
        cout << "Gagal membuat file.\n";
        return;
    }

    string line;
    while (true) {
        getline(cin, line);
        if (line == ".done") break;
        ofs << line << '\n';
    }
    ofs.close();
    cout << "File '" << filename << "' berhasil disimpan.\n";
}

void listfile() {
    cout << "\nDaftar file di folder kerja:\n";
    int count = 0;
    try {
        for (const auto& entry : fs::directory_iterator(fs::current_path())) {
            if (entry.is_regular_file()) {
                cout << " - " << entry.path().filename().string() << '\n';
                count++;
            }
        }
    } catch (const fs::filesystem_error& e) {
        cout << "Error membaca folder: " << e.what() << '\n';
        return;
    }
    
    if (count == 0) {
        cout << "Tidak ada file di folder kerja.\n";
    } else {
        cout << "Total: " << count << " file\n";
    }
}

void readfile() {
    string filename;
    cout << "Masukkan nama file yang akan dibaca: ";
    clear_input();
    getline(cin, filename);

    if (filename.empty()) {
        cout << "Nama file tidak boleh kosong.\n";
        return;
    }

    if (!fs::exists(filename)) {
        cout << "File '" << filename << "' tidak ditemukan.\n";
        return;
    }

    ifstream ifs(filename);
    if (!ifs) {
        cout << "Gagal membuka file.\n";
        return;
    }

    cout << "\n--- Isi file '" << filename << "' ---\n";
    string line;
    int line_number = 1;
    while (getline(ifs, line)) {
        cout << line_number << ": " << line << '\n';
        line_number++;
    }
    cout << "--- Akhir file ---\n";
    ifs.close();
}

void deletefile() {
    string filename;
    cout << "Masukkan nama file yang akan dihapus: ";
    clear_input();
    getline(cin, filename);

    if (filename.empty()) {
        cout << "Nama file tidak boleh kosong.\n";
        return;
    }

    if (!fs::exists(filename)) {
        cout << "File '" << filename << "' tidak ditemukan.\n";
        return;
    }

    cout << "Yakin ingin menghapus file '" << filename << "'? (y/n): ";
    char c;
    cin >> c;
    clear_input();
    
    if (c == 'y' || c == 'Y') {
        try {
            if (fs::remove(filename)) {
                cout << "File '" << filename << "' berhasil dihapus.\n";
            } else {
                cout << "Gagal menghapus file.\n";
            }
        } catch (const fs::filesystem_error& e) {
            cout << "Gagal menghapus file: " << e.what() << '\n';
        }
    } else {
        cout << "Penghapusan dibatalkan.\n";
    }
}

void renamefile() {
    string oldname, newname;
    cout << "Masukkan nama file lama: ";
    clear_input();
    getline(cin, oldname);

    if (oldname.empty()) {
        cout << "Nama file lama tidak boleh kosong.\n";
        return;
    }

    if (!fs::exists(oldname)) {
        cout << "File '" << oldname << "' tidak ditemukan.\n";
        return;
    }

    cout << "Masukkan nama file baru: ";
    getline(cin, newname);

    if (newname.empty()) {
        cout << "Nama file baru tidak boleh kosong.\n";
        return;
    }

    if (fs::exists(newname)) {
        cout << "File '" << newname << "' sudah ada. Tetap lanjutkan? (y/n): ";
        char c;
        cin >> c;
        if (c != 'y' && c != 'Y') {
            clear_input();
            return;
        }
        clear_input();
    }

    try {
        fs::rename(oldname, newname);
        cout << "File berhasil diganti nama menjadi '" << newname << "'.\n";
    } catch (const fs::filesystem_error& e) {
        cout << "Gagal mengganti nama file: " << e.what() << '\n';
    }
}

int main() {
    cout << "Selamat datang di Sistem Berkas Sederhana!\n";
    
    while (true) {
        showmenu();
        int choice;
        
        if (!(cin >> choice)) {
            cout << "Pilihan tidak valid. Masukkan angka 1-6.\n";
            clear_input();
            continue;
        }
        
        clear_input(); 
        switch (choice) {
            case 1:
                buatfile();
                break;
            case 2:
                listfile();
                break;
            case 3:
                readfile();
                break;
            case 4:
                deletefile();
                break;
            case 5:
                renamefile();
                break;
            case 6:
                cout << "Terima kasih! Keluar dari program.\n";
                return 0;
            default:
                cout << "Pilihan tidak valid. Masukkan angka 1-6.\n";
        }
    }
    
    return 0;
}