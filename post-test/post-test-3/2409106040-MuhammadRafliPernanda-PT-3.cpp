#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int MAX_USERS = 100;
const int MAX_CATATAN = 100;

// Struct untuk user
struct User {
    string username;
    string password;
};

// Struct untuk catatan keuangan
struct Catatan {
    string tanggal;
    string kategori;
    double jumlah;
    string sumber;
};

// Array untuk menyimpan user & catatan
User users[MAX_USERS] = {{"pernanda", "040"}};  // User default
Catatan catatan[MAX_CATATAN];

int totalUsers = 1;   // Mulai dari 1 karena "pernanda" sudah ada
int totalCatatan = 0;

int main() {
    int pilihan;
    string inputUser, inputPass;

    while (true) {
        cout << "=================================\n";
        cout << "|           MENU AWAL           |\n";
        cout << "=================================\n";
        cout << "| 1. Registrasi                 |\n";
        cout << "| 2. Login                      |\n";
        cout << "| 3. Keluar                     |\n";
        cout << "=================================\n";
        cout << "Pilih menu (1-3): ";
        cin >> pilihan;

        if (pilihan == 1) {  // Registrasi
            if (totalUsers >= MAX_USERS) {
                cout << "User sudah penuh!\n";
                continue;
            }

            string newUsername;
            bool usernameExists = false;

            cout << "Masukkan username baru: ";
            cin >> newUsername;

            // Check if username already exists
            for (int i = 0; i < totalUsers; i++) {
                if (users[i].username == newUsername) {
                    usernameExists = true;
                    break;
                }
            }

            if (usernameExists) {
                cout << "Username sudah digunakan!\n";
                continue;
            }

            users[totalUsers].username = newUsername;
            cout << "Masukkan password: ";
            cin >> users[totalUsers].password;
            totalUsers++;

            cout << "Registrasi berhasil!\n\n";

        } else if (pilihan == 2) {  // Login
            int attempts = 0;
            bool loginSukses = false;

            while (attempts < 3) {
                cout << "Masukkan Username: ";
                cin >> inputUser;
                cout << "Masukkan Password: ";
                cin >> inputPass;

                for (int i = 0; i < totalUsers; i++) {
                    if (users[i].username == inputUser && users[i].password == inputPass) {
                        loginSukses = true;
                        break;
                    }
                }

                if (loginSukses) {
                    cout << "Login berhasil! Selamat datang, " << inputUser << "!\n\n";
                    break;
                } else {
                    attempts++;
                    cout << "Login gagal! Sisa percobaan: " << (3 - attempts) << endl << endl;
                }
            }

            if (!loginSukses) {
                cout << "Anda gagal login 3 kali. Program dihentikan.\n";
                return 0;
            }

            // Menu setelah login
            while (true) {
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
                cout << "| 8. Logout                             |\n";
                cout << "=========================================\n";
                cout << "Pilih menu (1-8): ";
                cin >> pilihan;

                if (pilihan == 1 || pilihan == 2) {  // Tambah Pemasukan/Pengeluaran
                    if (totalCatatan >= MAX_CATATAN) {
                        cout << "Penyimpanan penuh!\n";
                        continue;
                    }

                    cin.ignore();
                    cout << "Masukkan tanggal (YYYY-MM-DD): ";
                    getline(cin, catatan[totalCatatan].tanggal);
                    cout << "Masukkan jumlah uang: ";
                    cin >> catatan[totalCatatan].jumlah;
                    cin.ignore();
                    cout << "Masukkan sumber: ";
                    getline(cin, catatan[totalCatatan].sumber);
                    catatan[totalCatatan].kategori = (pilihan == 1) ? "Pemasukan" : "Pengeluaran";

                    totalCatatan++;
                    cout << "Catatan berhasil ditambahkan!\n\n";

                } else if (pilihan == 3 || pilihan == 4) {  // Lihat total pemasukan/pengeluaran
                    double total = 0;
                    string tipe = (pilihan == 3) ? "Pemasukan" : "Pengeluaran";

                    for (int i = 0; i < totalCatatan; i++) {
                        if (catatan[i].kategori == tipe) {
                            total += catatan[i].jumlah;
                        }
                    }
                    cout << "Total " << tipe << ": Rp" << total << "\n\n";

                } else if (pilihan == 5) {  // Lihat semua catatan
                    if (totalCatatan == 0) {
                        cout << "Belum ada catatan.\n\n";
                        continue;
                    }

                    cout << "\n================== Daftar Catatan ===================\n";
                    cout << "+----+------------+------------+------------+------------------+\n";
                    cout << "| No |   Tanggal  |  Kategori  |   Jumlah   |      Sumber      |\n";
                    cout << "+----+------------+------------+------------+------------------+\n";

                    for (int i = 0; i < totalCatatan; i++) {
                        cout << "| " << setw(2) << i + 1 
                             << " | " << setw(10) << catatan[i].tanggal
                             << " | " << setw(10) << catatan[i].kategori
                             << " | " << setw(10) << catatan[i].jumlah
                             << " | " << setw(16) << catatan[i].sumber
                             << " |\n";
                    }

                    cout << "+----+------------+------------+------------+------------------+\n\n";

                } else if (pilihan == 6) {  // Edit catatan
                    int index;
                    cout << "Masukkan nomor catatan yang ingin diedit: ";
                    cin >> index;

                    if (index < 1 || index > totalCatatan) {
                        cout << "Nomor tidak valid!\n\n";
                        continue;
                    }

                    index--;
                    cin.ignore();
                    cout << "Masukkan tanggal baru: ";
                    getline(cin, catatan[index].tanggal);
                    cout << "Masukkan jumlah baru: ";
                    cin >> catatan[index].jumlah;
                    cin.ignore();
                    cout << "Masukkan sumber baru: ";
                    getline(cin, catatan[index].sumber);

                    cout << "Catatan berhasil diperbarui!\n\n";

                } else if (pilihan == 7) {  // Hapus catatan
                    int index;
                    cout << "Masukkan nomor catatan yang ingin dihapus: ";
                    cin >> index;

                    if (index < 1 || index > totalCatatan) {
                        cout << "Nomor tidak valid!\n\n";
                        continue;
                    }

                    for (int i = index - 1; i < totalCatatan - 1; i++) {
                        catatan[i] = catatan[i + 1];
                    }
                    totalCatatan--;

                    cout << "Catatan berhasil dihapus!\n\n";

                } else if (pilihan == 8) {
                    cout << endl;
                    break;  

                } else {
                    cout << "Pilihan tidak valid!" << endl << endl; 
                }
            }

        } else if (pilihan == 3) {
            cout << "Terima kasih karena telah menggunakan program ini\n";
            cout << "-------------Muhammad Rafli Pernanda-------------\n";
            cout << "--------------------2409106040-------------------\n";
            return 0;

        } else {
            cout << "Pilihan tidak valid!" << endl << endl;
        }
    }
}