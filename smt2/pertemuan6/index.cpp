#include <limits>
#include <iostream>

using namespace std;

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

void sequentialSearch(int data[], int n, int cari)
{
    int i;
    for (i = 0; i < n; i++){
        if (data[i] == cari){
            cout << "Elemen ditemukan dengan Sequential Search pada index " << i << endl;
            break;
        }
    }
    if (i == n)
        cout << "Elemen tidak ditemukan dengan Sequential Search" << endl;
}

void binarySearch(int arr[], int l, int r, int cari)
{
    if (r >= l){
        int mid = l + (r - l) / 2;

        if (arr[mid] == cari){
            cout << "Elemen ditemukan dengan Binary Search pada index " << mid << endl;
            return;
        }

        if (arr[mid] > cari)
            binarySearch(arr, l, mid - 1, cari);
        else
            binarySearch(arr, mid + 1, r, cari);
    }
    else
        cout << "Elemen tidak ditemukan dengan Binary Search" << endl;
}

void outData(int data[], int n)
{
    for (int i = 0; i < n; i++)
        cout << data[i] << " ";
    cout << endl;
}

int main(){
    int data[5], cari, n = sizeof(data) / sizeof(data[0]);

    for (int i = 0; i < n; i++){
        cout << "Masukkan elemen index ke-" << i << " : ";
        data[i] = inputInt();
    }

    cout << "\nData : ";
    outData(data, n);

    cout << "\nMasukkan elemen untuk dicari: ";
    cari = inputInt();
    sequentialSearch(data, n, cari);
    binarySearch(data, 0, n - 1, cari);

    return 0;
}