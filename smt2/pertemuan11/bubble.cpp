#include <iostream>
#include <conio.h>
using namespace std;


int main(){
    int nilai['n'];
    int temp, n;
    cout << "Masukkan jumlah data : ";
    cin >> n;

    for (int i = 0; i <= n; i++)
    {
        cout << "Nilai [" << i << "] : ";
        cin >> nilai[i];
    }
    
    cout << "\nData sebelum diurutkan : ";
    for (int i = 0; i <= n; i++)
    {
        cout << nilai[i] << " ";
    }

    cout<<endl;
    for (int i = n-1; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            if (nilai[j] > nilai[j+1])
            {
                temp = nilai[j+1];
                nilai[j+1] = nilai[j];
                nilai[j] = temp;
            }
        }
    }

    cout << "\nData setelah diurutkan ASC : ";
    for (int i = 0; i <= n; i++)
    {
        cout << nilai[i] << " ";
    }

    cout << "\nData setelah diurutkan DESC : ";
    for (int i = n; i >= 0; i--)
    {
        cout << nilai[i] << " ";
    }    
    return 0;
}