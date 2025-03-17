#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    // Deklarasi array
    int number[4] = {1, 2, 4};

    // Menambah data
    number[4] = 10;

    // Edit data
    number[1] = 2;

    // Menampilkan data (read)
    for (auto i = 0; i < 4; i++)
    {
        cout << "Nilai array : " << number[i] << endl;
    }

    // Panjang sebuah array statis
    int totalByte = sizeof(number);
    int singleByte = sizeof(number[0]);
    int panjangArray2 = size(number);
    int panjangArray = sizeof(number) / sizeof(number[0]);
    cout
        << totalByte << "\n"
        << singleByte << "\n"
        << panjangArray2;

    for (int i = 0; i < panjangArray; i++)
    {
        cout << "Nilai array : " << number[i] << endl;
    }
    // Cek versi c++
    cout << "Versi c++ saya  : " << __cplusplus;

    // Hapus
    for (int i = 1; i < 3; i++)
    {
        number[i] = number[i + 1];
    }
    return 0;
}