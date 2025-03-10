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

        // username menggunakan nama panggilan, dan password menggunakan 3 angka terakhir NIM

        if ((username == "pernanda" || username == "Pernanda") && password == "040") {
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
    
    cout << "     ░█░█░█▀█░█▀█░█░█░█▀▀░█▀▄░█▀▀░▀█▀" << endl;
    cout << "     ░█▀▄░█░█░█░█░▀▄▀░█▀▀░█▀▄░▀▀█░░█░" << endl;
    cout << "     ░▀░▀░▀▀▀░▀░▀░░▀░░▀▀▀░▀░▀░▀▀▀░▀▀▀" << endl << endl;

    cout << "░█▀▀░█▀█░▀█▀░█░█░█▀█░█▀█░░░█▀▀░█░█░█░█░█░█" << endl;
    cout << "░▀▀█░█▀█░░█░░█░█░█▀█░█░█░░░▀▀█░█░█░█▀█░█░█" << endl;
    cout << "░▀▀▀░▀░▀░░▀░░▀▀▀░▀░▀░▀░▀░░░▀▀▀░▀▀▀░▀░▀░▀▀▀" << endl << endl;

    cout << "=============================" << endl;
    cout << "|         Menu Utama        |" << endl;
    cout << "=============================" << endl;
    cout << "|   1. Konversi Celcius     |" << endl;
    cout << "|   2. Konversi Fahrenheit  |" << endl;
    cout << "|   3. Konversi Reamur      |" << endl;
    cout << "|   4. Konversi Kelvin      |" << endl;
    cout << "|   5. Keluar dari program  |" << endl;
    cout << "=============================" << endl;
    cout << "Pilih menu: ";
    cin >> pilihan;
    cout << endl;

    if (pilihan == 1)
    {
        float suhuCelcius;
        cout << "==================================" << endl;
        cout << "|  Konversi Satuan suhu Celcius  |" << endl;
        cout << "==================================" << endl;
        cout << "Masukkan suhu dalam Celcius: ";
        cin >> suhuCelcius;
        cout << endl << "Mengkonversi " << suhuCelcius << "°C" << endl;
        cout << "Suhu dalam Fahrenheit: " << (suhuCelcius * 9/5) + 32 <<"°F" << endl;
        cout << "Suhu dalam Reamur: " << suhuCelcius * 4/5 <<"°R" << endl;
        cout << "Suhu dalam Kelvin: " << suhuCelcius + 273 <<"°K"<< endl;
        cout << "==================================" << endl << endl;
        return menuUtama();

    } else if (pilihan == 2)
    {
        float suhuFahrenheit;
        cout << "==================================" << endl;
        cout << "| Konversi Satuan suhu Fahrenheit|" << endl;
        cout << "==================================" << endl;
        cout << "Masukkan suhu dalam Fahrenheit: ";
        cin >> suhuFahrenheit;
        cout << endl << "Mengkonversi " << suhuFahrenheit << "°F" << endl;
        cout << "Suhu dalam Celcius: " << (suhuFahrenheit - 32) * 5/9 <<"°C" << endl;
        cout << "Suhu dalam Reamur: " << (suhuFahrenheit - 32) * 4/9 <<"°R" << endl;
        cout << "Suhu dalam Kelvin: " << (suhuFahrenheit - 32) * 5/9 + 273 <<"°K" << endl;
        cout << "==================================" << endl << endl;
        return menuUtama();

    } else if (pilihan == 3)
    {
        float suhuReamur;
        cout << "==================================" << endl;
        cout << "|  Konversi Satuan suhu Reamur   |" << endl;
        cout << "==================================" << endl;
        cout << "Masukkan suhu dalam Reamur: ";
        cin >> suhuReamur;
        cout << endl << "Mengkonversi " << suhuReamur << "°R" << endl;
        cout << "Suhu dalam Celcius: " << suhuReamur * 5/4 <<"°C"<< endl;
        cout << "Suhu dalam Fahrenheit: " << suhuReamur * 9/4 + 32 << "°F" << endl;
        cout << "Suhu dalam Kelvin: " << suhuReamur * 5/4 + 273 << "°K" <<endl;
        cout << "==================================" << endl << endl;
        return menuUtama();

    } else if (pilihan == 4)
    {
        float suhuKelvin;
        cout << "==================================" << endl;
        cout << "|   Konversi Satuan suhu Kelvin  |" << endl;
        cout << "==================================" << endl;
        cout << "Masukkan suhu dalam Kelvin: ";
        cin >> suhuKelvin;
        cout << endl << "Mengkonversi " << suhuKelvin << "°K" << endl;
        cout << "Suhu dalam Celcius: " << suhuKelvin - 273 <<"°C" << endl;
        cout << "Suhu dalam Fahrenheit: " << (suhuKelvin - 273) * 9/5 + 32 <<"°F" << endl;
        cout << "Suhu dalam Reamur: " << (suhuKelvin - 273) * 4/5 <<"°R" << endl;
        cout << "==================================" << endl << endl;
        return menuUtama();
        
    } else if (pilihan == 5)
    {
        cout << "-------------------------------------------" << endl;
        cout << "Terima kasih telah menggunakan program ini." << endl;
        cout << "----------Muhammad Rafli Pernanda----------" << endl;
        cout << "-----------------2409106040----------------" << endl;
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