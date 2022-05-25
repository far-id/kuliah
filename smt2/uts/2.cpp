#include <iostream>
#include <limits>
using namespace std;

// digunakan untuk input integer, akan meminta inputan ulang ketika input bukan integer
int inputInt()
{
    int x = 0;
    while (!(cin >> x))
    {
        cin.clear();
        cin.ignore(numeric_limits<int>::max(), '\n');
        cout << "Input bukan integer. coba lagi : ";
    }
    return x;
}

int main(){
    int n1 = 0, n2 = 1, n3, i, fibonacciKe;
    cout << "Berapa elemen fibonacci yang ingin dikeluarkan: ";
    fibonacciKe = inputInt();
    cout << n1 << " " << n2 << " "; // print 0 dan 1
    // iterasi fibonacci
    for (i = 2; i < fibonacciKe; ++i)    
    {
        n3 = n1 + n2;
        cout << n3 << " ";
        n1 = n2;
        n2 = n3;
    }
    return 0;
}