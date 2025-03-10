#include <iostream>
using namespace std;

int loginPage()
{
    string username, password;
    int percobaan = 0;
    int percobaanMaksimal = 3;

    while (percobaan < percobaanMaksimal) {
        cout << "=============================" << endl;
        cout << "|         Login Page        |" << endl;
        cout << "=============================" << endl;
        cout << "Masukkan username Anda: ";
        cin >> username;
        cout << "Masukkan Password: ";
        cin >> password;

        // username: Pernanda, password: gacorParah

        if ((username == "Pernanda") && password == "gacorParah") {
            cout << "=============================" << endl;
            cout << "|      Login Berhasil!      |" << endl;
            cout << "| Selamat datang, Pernanda! |" << endl;
            cout << "=============================" << endl << endl << endl << endl;
            return 0;
        } else {
            cout << "Username atau Password anda salah, silahkan coba lagi." << endl;
            percobaan++;
        }
    }

    cout << "Percobaan login maksimal hanya 3x, program dihentikan." << endl;
    cout << "Terima kasih." << endl;
    return 1;
}

int menuUtama() {
    int pilihan;

    cout << "=============================" << endl;
    cout << "|         Menu Utama        |" << endl;
    cout << "=============================" << endl;
    cout << "|   1. Konversi ke USD      |" << endl;
    cout << "|   2. Konversi ke Ringgit  |" << endl;
    cout << "|   3. Konversi ke Euro     |" << endl;
    cout << "|   4. Keluar dari program  |" << endl;
    cout << "=============================" << endl;
    cout << "Pilih menu: ";
    cin >> pilihan;
    cout << endl;

    if (pilihan == 1)
    {
        float jumlah;
        cout << "==================================" << endl;
        cout << "|      Konversi ke USD           |" << endl;
        cout << "==================================" << endl;
        cout << "Masukkan jumlah dalam Rupiah: ";
        cin >> jumlah;
        cout << endl << "Mengkonversi " << jumlah << " IDR" << endl;
        cout << "Jumlah dalam USD: " << jumlah / 15000 << " USD" << endl;
        cout << "==================================" << endl << endl;
        return menuUtama();

    } else if (pilihan == 2)
    {
        float jumlah;
        cout << "==================================" << endl;
        cout << "|      Konversi ke Ringgit       |" << endl;
        cout << "==================================" << endl;
        cout << "Masukkan jumlah dalam Rupiah: ";
        cin >> jumlah;
        cout << endl << "Mengkonversi " << jumlah << " IDR" << endl;
        cout << "Jumlah dalam Ringgit: " << jumlah / 3500 << " MYR" << endl;
        cout << "==================================" << endl << endl;
        return menuUtama();

    } else if (pilihan == 3)
    {
        float jumlah;
        cout << "==================================" << endl;
        cout << "|      Konversi ke Euro          |" << endl;
        cout << "==================================" << endl;
        cout << "Masukkan jumlah dalam Rupiah: ";
        cin >> jumlah;
        cout << endl << "Mengkonversi " << jumlah << " IDR" << endl;
        cout << "Jumlah dalam Euro: " << jumlah / 17000 << " EUR" << endl;
        cout << "==================================" << endl << endl;
        return menuUtama();
        
    } else if (pilihan == 4)
    {
        cout << "-------------------------------------------" << endl;
        cout << "Terima kasih telah menggunakan program ini." << endl;
        cout << "----------Muhammad Rafli Pernanda----------" << endl;
        cout << "-------------------------------------------" << endl;
        return 0;
    } else
    {
        cout << "Pilihan tidak valid, masukkan angka sesuai pilihan yang tersedia." << endl << endl << endl;
        return menuUtama();
    }
}

int main () 
{
    int login = loginPage();
    if (login == 1) {
        return 1;
    }

    return menuUtama();

    return 0;
}