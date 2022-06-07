#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;


int main(){
    int i, j, b, k, m, n, x, y, z, ketemu=0;
    int data['n'], temp[100];

    cout << "Masukkan jumlah data : ";
    cin >> n;

    for (i = 0; i <= n; i++)
    {
        cout << "Nilai [" << i << "] : ";
        cin >> data[i];
    }

    cout << "\nData sebelum diurutkan : ";
    for (i = 0; i <= n; i++)
    {
        cout << data[i] << " ";
    }
    
    cout<<endl;
    
    for (i = 0; i <n; i++)
    {
        for (j = 0; j <= i; j++)
        {
            if (data[i] < data[j])
            {
                m = data[i];
                data[i] = data[j];
                data[j] = m;
            }
        }
    }

    cout << "\nData setelah diurutkan ASC : ";
    for (i = 0; i <= n; i++)
    {
        cout << data[i] << " ";
    }

    cout << "\nData setelah diurutkan DESC : ";
    for (i = n; i >= 0; i--)
    {
        cout << data[i] << " ";
    }


    return 0;
}