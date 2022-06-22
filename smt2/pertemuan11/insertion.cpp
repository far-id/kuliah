#include <iostream>
using namespace std;


int main(){
    int i, j, m, n;
    int data['n'];

    cout << "Banyaknya data: "; cin >> n;

    for (i = 1; i <= n; i++)
    {
        cout << "Nilai [" << i << "] : ";
        cin >> data[i];
    }

    cout << "\nData sebelum diurutkan : ";
    for (i = 1; i <= n; i++)
    {
        cout << data[i] << " ";
    }
    
    cout<<endl;
    
    for (i = 1; i <n; i++)
    {
        for (j = 1; j <= i; j++)
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
    for (i = 1; i <= n; i++)
    {
        cout << data[i] << " ";
    }

    cout << "\nData setelah diurutkan DESC : ";
    for (i = n; i >= 1; i--)
    {
        cout << data[i] << " ";
    }


    return 0;
}