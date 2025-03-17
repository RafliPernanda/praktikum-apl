#include <iostream>
#include <iomanip> // Untuk membuat tampilan tabel lebih rapi
#include <string>

using namespace std;

const int MAX_CATATAN = 100;

// Array untuk menyimpan data catatan keuangan
string tanggal[MAX_CATATAN];
string kategori[MAX_CATATAN];
double jumlah[MAX_CATATAN];
string sumber[MAX_CATATAN]; // Menyimpan sumber pemasukan/pengeluaran
int totalCatatan = 0;

// Fungsi login
bool login() {
    string username, password;
    int attempts = 0;
    
    while (attempts < 3) {
        cout << "=============================\n";
        cout << "|         MENU LOGIN        |\n";
        cout << "=============================\n";
        cout << "Masukkan Username: ";
        cin >> username;
        cout << "Masukkan Password: ";
        cin >> password;
        cout << endl;

        if ((username == "pernanda" || username == "Pernanda") && password == "040") {
            cout << "=============================" << endl;
            cout << "|      Login Berhasil!      |" << endl;
            cout << "| Selamat datang, Pernanda! |" << endl;
            cout << "=============================" << endl << endl << endl << endl;
            return true;
        } else {
            cout << "Login gagal! Username atau password salah.\n";
            attempts++;
            cout << "Percobaan tersisa: " << (3 - attempts) << "\n";
        }
    }

    cout << "Anda telah gagal login sebanyak 3 kali. Program ditutup.\n";
    return false;
}

// Fungsi menambahkan catatan pemasukan atau pengeluaran
int tambahCatatan(string tipe) {
    if (totalCatatan >= MAX_CATATAN) {
        cout << "Penyimpanan penuh!\n";
        return 0;
    }
    
    cout << "Masukkan tanggal (YYYY-MM-DD): ";
    cin >> tanggal[totalCatatan];
    cout << "Masukkan jumlah uang: ";
    cin >> jumlah[totalCatatan];
    cout << "Masukkan sumber " << tipe << ": ";
    cin.ignore(); 
    getline(cin, sumber[totalCatatan]); 
    kategori[totalCatatan] = tipe;

    totalCatatan++;
    cout << "Catatan berhasil ditambahkan!\n" << endl;
    return 1;
}

// Fungsi menghitung total pemasukan
double hitungTotalPemasukan() {
    double total = 0;
    for (int i = 0; i < totalCatatan; i++) {
        if (kategori[i] == "Pemasukan") {
            total += jumlah[i];
        }
    }
    return total;
}

// Fungsi menghitung total pengeluaran
double hitungTotalPengeluaran() {
    double total = 0;
    for (int i = 0; i < totalCatatan; i++) {
        if (kategori[i] == "Pengeluaran") {
            total += jumlah[i];
        }
    }
    return total;
}

// Fungsi untuk menampilkan semua catatan dalam bentuk tabel
bool lihatSemuaCatatan() {
    if (totalCatatan == 0) {
        cout << "Belum ada catatan keuangan.\n";
        return false;
    }

    cout << "\n================== Daftar Catatan Keuangan ===================\n";
    cout << "+----+------------+------------+------------+------------------+\n";
    cout << "| No |   Tanggal  |  Kategori  |   Jumlah   |      Sumber      |\n";
    cout << "+----+------------+------------+------------+------------------+\n";

    for (int i = 0; i < totalCatatan; i++) {
        cout << "| " << setw(2) << i + 1 
             << " | " << setw(10) << tanggal[i] 
             << " | " << setw(10) << kategori[i] 
             << " | " << setw(10) << jumlah[i] 
             << " | " << setw(16) << sumber[i] 
             << " |\n";
    }

    cout << "+----+------------+------------+------------+------------------+\n" << endl;
    return true;
}

// Fungsi untuk mengedit catatan
bool editCatatan(int index) {
    if (index < 1 || index > totalCatatan) return false;

    index--; 
    cout << "Masukkan tanggal baru: ";
    cin >> tanggal[index];
    cout << "Masukkan jumlah uang baru: ";
    cin >> jumlah[index];
    cout << "Masukkan kategori baru (Pemasukan/Pengeluaran): ";
    cin >> kategori[index];
    cout << "Masukkan sumber baru: ";
    cin.ignore();
    getline(cin, sumber[index]);

    return true;
}

// Fungsi untuk menghapus catatan
bool hapusCatatan(int index) {
    if (index < 1 || index > totalCatatan) return false;

    index--; 
    for (int i = index; i < totalCatatan - 1; i++) {
        tanggal[i] = tanggal[i + 1];
        jumlah[i] = jumlah[i + 1];
        kategori[i] = kategori[i + 1];
        sumber[i] = sumber[i + 1];
    }
    totalCatatan--;

    return true;
}

// Fungsi utama (menu)
int menu() {
    int pilihan;
    do {
        cout << "=========================================\n";
        cout << "|     Aplikasi Catatan Keuangan         |\n";
        cout << "=========================================\n";
        cout << "| 1. Tambah Catatan Pemasukan           |\n";
        cout << "| 2. Tambah Catatan Pengeluaran         |\n";
        cout << "| 3. Lihat Total Pemasukan              |\n";
        cout << "| 4. Lihat Total Pengeluaran            |\n";
        cout << "| 5. Lihat Semua Catatan                |\n";
        cout << "| 6. Perbarui/Edit Catatan              |\n";
        cout << "| 7. Hapus Catatan                      |\n";
        cout << "| 8. Keluar dari Program                |\n";
        cout << "=========================================\n";
        cout << "Pilih menu (1-8): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: tambahCatatan("Pemasukan"); break;
            case 2: tambahCatatan("Pengeluaran"); break;
            case 3: cout << "Total Pemasukan: Rp" << hitungTotalPemasukan() << endl << endl; break;
            case 4: cout << "Total Pengeluaran: Rp" << hitungTotalPengeluaran() << endl << endl; break;
            case 5: 
                if (!lihatSemuaCatatan()) {
                    cout << "Tidak ada catatan untuk ditampilkan.\n" << endl;
                }
                break;
            case 6:
                int editIndex;
                cout << "Masukkan nomor catatan yang ingin diedit: ";
                cin >> editIndex;
                if (editCatatan(editIndex)) {
                    cout << "Catatan berhasil diperbarui!\n" << endl;
                } else {
                    cout << "Nomor catatan tidak valid!\n" << endl;
                }
                break;
            case 7:
                int hapusIndex;
                cout << "Masukkan nomor catatan yang ingin dihapus: ";
                cin >> hapusIndex;
                if (hapusCatatan(hapusIndex)) {
                    cout << "Catatan berhasil dihapus!\n" << endl;
                } else {
                    cout << "Nomor catatan tidak valid!\n" << endl;
                }
                break;
            case 8: cout << "Terima kasih telah menggunakan program ini!\n" << endl; break;
            default: cout << "Pilihan tidak valid!\n" << endl; break;
        }
    } while (pilihan != 8);
    
    return 0;
}

// Fungsi utama (main)
int main() {
    if (login()) {
        return menu();
    } else {
        return 0;
    }
}