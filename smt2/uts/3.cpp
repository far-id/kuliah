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

int GreatestCommonDivisor(int x, int y)
{
    if (y == 0) return x;
    return GreatestCommonDivisor(y, x % y);
}

int main()
{
    int x, y, gcd;
    cout << "Input x : ";
    x = inputInt();
    cout << "Input y : ";
    y = inputInt();
    
    cout << "gcd  =: " << GreatestCommonDivisor(x, y) << endl;

    return 0;
}