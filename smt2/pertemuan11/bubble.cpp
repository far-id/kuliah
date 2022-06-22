#include <iostream>
using namespace std;


int main(){
    int nilai['n'], temp, n;
    cout << "banyak data: ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cout << "Nilai [" << i << "] : ";
        cin >> nilai[i];
    }
    
    cout << "\nData sebelum diurutkan : ";
    for (int i = 1; i <= n; i++)
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
    for (int i = 1; i <= n; i++)
    {
        cout << nilai[i] << " ";
    }

    cout << "\nData setelah diurutkan DESC : ";
    for (int i = n; i >= 1; i--)
    {
        cout << nilai[i] << " ";
    }    
    return 0;
}