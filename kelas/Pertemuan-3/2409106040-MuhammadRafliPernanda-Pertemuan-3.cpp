#include <iostream>
using namespace std;

struct Tanggal {
    int hari;
    int bulan;
    int tahun;
};

struct Mahasiswa {
    string nama;
    int NIM;
    string gender;
    Tanggal tanggalLahir;
};


int main () {

    Mahasiswa mhsBaru, mhsLama;
    
    mhsBaru.nama = "Muhammad Rafli Pernanda";
    mhsBaru.NIM = 40;
    mhsBaru.gender = "Laki-laki";
    mhsBaru.tanggalLahir.hari = 2;
    mhsBaru.tanggalLahir.bulan = 6;
    mhsBaru.tanggalLahir.tahun = 2006;

    cout << mhsBaru.nama << endl;
    cout << mhsBaru.NIM << endl;
    cout << mhsBaru.gender << endl;

    cout <<"Tanggal lahir : " << mhsBaru.tanggalLahir.hari <<"/"<<mhsBaru.tanggalLahir.bulan<<"/"<<mhsBaru.tanggalLahir.tahun<< endl;

    string buah [5] = {"Apel", "Jeruk", "Mangga", "Pisang", "Semangka"};
    Mahasiswa mhsAbadi [5];
    mhsAbadi[0].nama = "A";
    mhsAbadi[1].nama = "B";
    mhsAbadi[2].nama = "C";
    mhsAbadi[3].nama = "D";
    mhsAbadi[4].nama = "E";

    for (int i = 0; i < sizeof(mhsAbadi); i++) {
        cout << mhsAbadi[i].nama << endl;
    }

    return 0;
}