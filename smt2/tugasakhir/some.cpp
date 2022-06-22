#include <bits/stdc++.h>
#include <chrono>
using namespace std;

// A sample function whose time taken to
// be measured

void radixSort(int arr[], int size)
{
    // deklarasi variabel
    int i, j, m, p = 1, index, temp, count = 0, max = arr[0];
    // mencari nilai maksimum
    for (i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    list<int> pocket[10]; // radix of decimal number is 10
    for (i = 0; i < max; i++)
    {
        m = pow(10, i + 1);
        p = pow(10, i);
        for (j = 0; j < size; j++)
        {
            temp = arr[j] % m;
            index = temp / p; // find index for pocket array
            pocket[index].push_back(arr[j]);
        }
        count = 0;
        for (j = 0; j < 10; j++)
        {
            // delete from linked lists and store to array
            while (!pocket[j].empty())
            {
                arr[count] = *(pocket[j].begin());
                pocket[j].erase(pocket[j].begin());
                count++;
            }
        }
    }
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int size)
{
    int i, j, temp;
    for (i = size / 2 - 1; i >= 0; i--)
    {
        heapify(arr, size, i);
    }
    for (i = size - 1; i >= 0; i--)
    {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

void randomData(int *arr, int size)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
        arr[i] = rand() % 1000000;
}
int main()
{
    int array[10000];
    randomData(array, 10000);

    cout<<"before :";
    radixSort(array, 10000);
    cout<<"\nafter :";
    
    
    
    return 0;
}
