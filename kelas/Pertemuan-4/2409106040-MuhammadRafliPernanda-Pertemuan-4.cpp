#include <iostream>
using namespace std;

// void perulangan()
// {
//     for (int i = 0; i < 5; i++)
//     {
//         if (i == 2)
//         {
//             return;
//         }
//         cout << i << endl;
//     }
// }

// int tambah(int a, int b)
// {
//     cout << "ini fungsi int a + b" << endl;
//     return a + b;
// }

// double tambah(double a, double b)
// {
//     cout << "ini fungsi double a + b" << endl;
//     return a + b;
// }

// int tambah(int a)
// {
//     cout << "ini fungsi a + a" << endl;
//     return a + a;
// }

// int a = 10;

// int ubahNilai()
// {
//     int b = 20;
//     return a;
// }

int faktorial(int n)
{
    if (n == 1)
        return 1;
    return n * faktorial(n - 1);
}

int main()
{

    // cout << b << endl;

    // cout << "ini fungsi int a + b" << endl;
    // cout << "ini tambah int a + b : " << tambah(10, 5) << endl;

    // cout << "ini tambah double a + b : " << tambah(10.5, 20.10) << endl;

    // cout << "ini tambah int a doang : " << tambah(10) << endl;

    // cout << "a sekarang : " << a << endl;

    // cout << "a di dalam fungsi : " << ubahNilai(15) << endl;

    // cout << "a sekarang : " << a << endl;

    // cout << tambah(5, 6);
    // perulangan();
    return 0;
}