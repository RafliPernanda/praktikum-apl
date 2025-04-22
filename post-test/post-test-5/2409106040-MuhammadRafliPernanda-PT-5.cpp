#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_USERS = 100;
const int MAX_CATATAN = 100;

struct User {
    string username;
    string password;
};

struct Catatan {
    string tanggal;
    string kategori;
    double jumlah;
    string sumber;
};

User users[MAX_USERS] = {{"pernanda", "040"}};
Catatan catatan[MAX_CATATAN];

int totalUsers = 1;
int totalCatatan = 0;

void MenuAwal() {
    cout << "=================================\n";
    cout << "|           MENU AWAL           |\n";
    cout << "=================================\n";
    cout << "| 1. Registrasi                 |\n";
    cout << "| 2. Login                      |\n";
    cout << "| 3. Keluar                     |\n";
    cout << "=================================\n";
}

bool usernameSudahAda(string uname) {
    for (int i = 0; i < totalUsers; i++) {
        if (users[i].username == uname)
            return true;
    }
    return false;
}

void registrasi() {
    if (totalUsers >= MAX_USERS) {
        cout << "User sudah penuh!\n";
        return;
    }

    string uname, pass;
    cout << "Masukkan username baru: ";
    cin >> uname;

    if (usernameSudahAda(uname)) {
        cout << "Username sudah digunakan!\n";
        return;
    }

    cout << "Masukkan password: ";
    cin >> pass;

    users[totalUsers++] = {uname, pass};
    cout << "Registrasi berhasil!\n\n";
}

bool login(string& username) {
    string inputUser, inputPass;
    int attempts = 0;

    while (attempts < 3) {
        cout << "Masukkan Username: ";
        cin >> inputUser;
        cout << "Masukkan Password: ";
        cin >> inputPass;

        for (int i = 0; i < totalUsers; i++) {
            if (users[i].username == inputUser && users[i].password == inputPass) {
                username = inputUser;
                cout << "Login berhasil! Selamat datang, " << inputUser << "!\n\n";
                return true;
            }
        }

        attempts++;
        cout << "Login gagal! Sisa percobaan: " << (3 - attempts) << "\n\n";
    }

    return false;
}

void tambahCatatan(bool pemasukan, Catatan* catatan, int* totalCatatan) {
    if (*totalCatatan >= MAX_CATATAN) {
        cout << "Penyimpanan penuh!\n";
        return;
    }

    cin.ignore();
    cout << "Masukkan tanggal (YYYY-MM-DD): ";
    getline(cin, catatan[*totalCatatan].tanggal);
    cout << "Masukkan jumlah uang: ";
    cin >> catatan[*totalCatatan].jumlah;
    cin.ignore();
    cout << "Masukkan sumber: ";
    getline(cin, catatan[*totalCatatan].sumber);
    catatan[*totalCatatan].kategori = pemasukan ? "Pemasukan" : "Pengeluaran";

    (*totalCatatan)++;
    cout << "Catatan berhasil ditambahkan!\n\n";
}

void lihatTotal(bool pemasukan, Catatan* catatan, int* totalCatatan) {
    double total = 0;
    string tipe = pemasukan ? "Pemasukan" : "Pengeluaran";

    for (int i = 0; i < *totalCatatan; i++) {
        if (catatan[i].kategori == tipe) {
            total += catatan[i].jumlah;
        }
    }

    cout << "Total " << tipe << ": Rp" << total << "\n\n";
}

void tampilkanSemuaCatatan(Catatan* catatan, int* totalCatatan) {
    if (*totalCatatan == 0) {
        cout << "Belum ada catatan.\n\n";
        return;
    }

    cout << "\n================== Daftar Catatan ===================\n";
    cout << "+----+------------+------------+------------+------------------+\n";
    cout << "| No |   Tanggal  |  Kategori  |   Jumlah   |      Sumber      |\n";
    cout << "+----+------------+------------+------------+------------------+\n";

    for (int i = 0; i < *totalCatatan; i++) {
        cout << "| " << setw(2) << i + 1
             << " | " << setw(10) << catatan[i].tanggal
             << " | " << setw(10) << catatan[i].kategori
             << " | " << setw(10) << catatan[i].jumlah
             << " | " << setw(16) << catatan[i].sumber
             << " |\n";
    }

    cout << "+----+------------+------------+------------+------------------+\n\n";
}

void editCatatan(Catatan* catatan, int* totalCatatan) {
    tampilkanSemuaCatatan(catatan, totalCatatan);

    if (*totalCatatan == 0) return;

    int index;
    cout << "Masukkan nomor catatan yang ingin diedit: ";
    cin >> index;

    if (index < 1 || index > *totalCatatan) {
        cout << "Nomor tidak valid!\n\n";
        return;
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
}

void hapusCatatan(Catatan* catatan, int* totalCatatan) {
    tampilkanSemuaCatatan(catatan, totalCatatan);

    if (*totalCatatan == 0) return;

    int index;
    cout << "Masukkan nomor catatan yang ingin dihapus: ";
    cin >> index;

    if (index < 1 || index > *totalCatatan) {
        cout << "Nomor tidak valid!\n\n";
        return;
    }

    for (int i = index - 1; i < *totalCatatan - 1; i++) {
        catatan[i] = catatan[i + 1];
    }
    (*totalCatatan)--;

    cout << "Catatan berhasil dihapus!\n\n";
}

void menuUtama(Catatan* catatan, int* totalCatatan) {
    int pilihan;
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

        switch (pilihan) {
            case 1: tambahCatatan(true, catatan, totalCatatan); break;
            case 2: tambahCatatan(false, catatan, totalCatatan); break;
            case 3: lihatTotal(true, catatan, totalCatatan); break;
            case 4: lihatTotal(false, catatan, totalCatatan); break;
            case 5: tampilkanSemuaCatatan(catatan, totalCatatan); break;
            case 6: editCatatan(catatan, totalCatatan); break;
            case 7: hapusCatatan(catatan, totalCatatan); break;
            case 8: cout << "\nLogout berhasil!\n\n"; return;
            default: cout << "Pilihan tidak valid!\n\n";
        }
    }
}

int main() {
    int pilihan;
    string usernameLogin;

    while (true) {
        MenuAwal();
        cout << "Pilih menu (1-3): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: registrasi(); break;
            case 2:
                if (login(usernameLogin)) {
                    menuUtama(catatan, &totalCatatan);
                } else {
                    cout << "Anda gagal login 3 kali. Program dihentikan.\n";
                    return 0;
                }
                break;
            case 3:
                cout << "Terima kasih karena telah menggunakan program ini\n";
                cout << "-------------Muhammad Rafli Pernanda-------------\n";
                cout << "--------------------2409106040-------------------\n";
                return 0;
            default: cout << "Pilihan tidak valid!\n\n";
        }
    }
}
