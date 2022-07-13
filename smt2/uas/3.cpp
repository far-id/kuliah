#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <list>
#include <cmath>
#include <chrono>
using namespace std;

void quickSort(int arr[], int left, int right)
{
    int i = left, j = right;
    int tmp;
    // menentukan pivot
    int pivot = arr[(left + right) / 2];
    // selama kiri lebih sama dengan kanan
    while (i <= j)
    {
        // selama kiri kurang dari pivot increment
        while (arr[i] < pivot)
            i++;
        // selama kanan lebih dari pivot decrement
        while (arr[j] > pivot)
            j--;
        // jika kiri kurang sama dengan kanan
        if (i <= j)
        {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }
    // jika kiri awal kurang dari kanan recursive
    if (left < j)
        quickSort(arr, left, j);
    // jika kiri kurang dari kanan awal
    if (i < right)
        quickSort(arr, i, right);
}

void shellSort(int arr[], int size)
{
    int i, j, tmp, gap;
    // menentukan gap atau jarak yang menjadi rumus 
    for (gap = size / 2; gap > 0; gap /= 2)
    {
        // bandingkan tiap elemen dengan gapnya
        for (i = gap; i < size; i += 1)
        {
            tmp = arr[i];
            for (j = i; j >= gap && arr[j - gap] > tmp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = tmp;
        }
    }
}

void insertionSort(int arr[], int size)
{
    int i, j, tmp;
    // ulangi sepanjang array
    for (i = 1; i < size; i++)
    {
        tmp = arr[i];
        // bandingkan nilai
        for (j = i - 1; j >= 0 && arr[j] > tmp; j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = tmp;
    }
}

void selectionSort(int arr[], int size)
{
    int i, j, min_idx;
    // ulangi sepanjang array
    for (i = 0; i < size - 1; i++)
    {
        // index sekarang yg dibandingkan dengan index setelahnya ++
        min_idx = i;
        for (j = i + 1; j < size; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(arr[min_idx], arr[i]);
    }
}

void bubbleSort(int arr[], int size)
{
    int i, j;
    // ulangi sepanjang array
    for (i = 0; i < size - 1; i++)
        // bandingkan
        for (j = 0; j < size - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

void mergeSort(int arr[], int size)
{
    int temp[size], mid = size / 2, i, j, k;
    if (size > 1)
    {
        mergeSort(arr, mid);
        mergeSort(arr + mid, size - mid);
        for (i = 0; i < size; i++)
        {
            temp[i] = arr[i];
        }
        for (i = 0, j = mid, k = 0; k < size; k++)
        {
            if (j >= size)
            {
                arr[k] = temp[i++];
            }
            else if (i >= mid)
            {
                arr[k] = temp[j++];
            }
            else if (temp[i] < temp[j])
            {
                arr[k] = temp[i++];
            }
            else
            {
                arr[k] = temp[j++];
            }
        }
    }
}

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
    list<int> pocket[10]; // nomor desimal radix 10
    for (i = 0; i < max; i++)
    {
        m = pow(10, i + 1);
        p = pow(10, i);
        for (j = 0; j < size; j++)
        {
            temp = arr[j] % m;
            index = temp / p; // cari index dari pocet
            pocket[index].push_back(arr[j]);
        }
        count = 0;
        for (j = 0; j < 10; j++)
        {
            // hapus dari linked list and kembalikan ke array
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
void tampil(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}
void randomData(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        arr[i] = rand() % 20;

    cout<<"\nData random :";
    tampil(arr, size);
    
}



int main(){
    int array[10];
    int size = 10;

    //random data & tampilkan
    //sorting
    // tampilkan hasil sort

    randomData(array,10);
    quickSort(array, 0, size - 1);
    cout << "Setelah sort :"; 
    tampil(array, 10);

    randomData(array,10);
    quickSort(array, 0, size - 1);
    cout << "Setelah sort :"; 
    tampil(array, 10);
    
    randomData(array, 10);
    shellSort(array, size);
    cout << "Setelah sort :";
    tampil(array, 10);

    randomData(array,10);
    insertionSort(array, size);
    cout << "Setelah sort :";
    tampil(array, 10);

    randomData(array,10);
    selectionSort(array, size);
    cout << "Setelah sort :";
    tampil(array, 10);

    randomData(array,10);
    bubbleSort(array, size);
    cout << "Setelah sort :";
    tampil(array, 10);

    randomData(array,10);
    mergeSort(array, size);
    cout << "Setelah sort :";
    tampil(array, 10);

    radixSort(array, size);
    randomData(array,10);
    cout << "Setelah sort :";
    tampil(array, 10);

    randomData(array,10);
    heapSort(array, size);
    cout << "Setelah sort :";
    tampil(array, 10);
}