#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <list>
#include <cmath>
#include <chrono>
using namespace std;


void quickSort(int arr[], int left, int right) {
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];
    while (i <= j) {
        while (arr[i] < pivot)
            i++;    
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }
    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}

void shellSort(int arr[], int size) {
    int i, j, tmp, gap;
    for (gap = size / 2; gap > 0; gap /= 2) {
        for (i = gap; i < size; i += 1) {
            tmp = arr[i];
            for (j = i; j >= gap && arr[j - gap] > tmp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = tmp;
        }
    }
}

void insertionSort(int arr[], int size) {
    int i, j, tmp;
    for (i = 1; i < size; i++) {
        tmp = arr[i];
        for (j = i - 1; j >= 0 && arr[j] > tmp; j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = tmp;
    }
}

void selectionSort(int arr[], int size) {
    int i, j, min_idx;
    for (i = 0; i < size - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < size; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(arr[min_idx], arr[i]);
    }
}

void bubbleSort(int arr[], int size) {
    int i, j;
    for (i = 0; i < size - 1; i++)
        for (j = 0; j < size - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

void mergeSort(int arr[], int size){
    int temp[size], mid = size/2, i, j, k;
    if (size > 1){
        mergeSort(arr, mid);
        mergeSort(arr + mid, size - mid);
        for (i = 0; i < size; i++){
            temp[i] = arr[i];
        }
        for (i = 0, j = mid, k = 0; k < size; k++){
            if (j >= size){
                arr[k] = temp[i++];
            } else if (i >= mid){
                arr[k] = temp[j++];
            } else if (temp[i] < temp[j]){
                arr[k] = temp[i++];
            } else {
                arr[k] = temp[j++];
            }
        }
    }
}


void radixSort(int arr[], int size){
    // deklarasi variabel
    int i, j, m, p = 1, index, temp, count = 0, max = arr[0];
    // mencari nilai maksimum
    for (i = 0; i < size; i++){
        if (arr[i] > max){
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

void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int size){
    int i, j, temp;
    for (i = size / 2 - 1; i >= 0; i--){
        heapify(arr, size, i);
    }
    for (i = size - 1; i >= 0; i--){
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

void randomData(int *arr, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++)
        arr[i] = rand() % 1000000;
}

void runtime(int array[], int size){
    cout << "\n\nData Size " << size << endl;
    auto start = chrono::high_resolution_clock::now();
    quickSort(array, 0, size - 1);
    auto end = chrono::high_resolution_clock::now();
    // Calculating total time taken by the program.
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    cout << "Quick Sort\t: " << time_taken << setprecision(9) << " sec\n";

    start = chrono::high_resolution_clock::now();
    shellSort(array, size);
    end = chrono::high_resolution_clock::now();
    time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    cout << "Shell Sort\t: " << time_taken << setprecision(9) << " sec\n";

    start = chrono::high_resolution_clock::now();
    insertionSort(array, size);
    end = chrono::high_resolution_clock::now();
    time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    cout << "Insertion Sort  : " << time_taken << setprecision(9) << " sec\n";

    start = chrono::high_resolution_clock::now();
    selectionSort(array, size);
    end = chrono::high_resolution_clock::now();
    time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    cout << "Selection Sort  : " << time_taken << setprecision(9) << " sec\n";

    start = chrono::high_resolution_clock::now();
    bubbleSort(array, size);
    end = chrono::high_resolution_clock::now();
    time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    cout << "Bubble Sort\t: " << time_taken << setprecision(9) << " sec\n";

    start = chrono::high_resolution_clock::now();
    mergeSort(array, size);
    end = chrono::high_resolution_clock::now();
    time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    cout << "Merge Sort\t: " << time_taken << setprecision(9) << " sec\n";

    start = chrono::high_resolution_clock::now();
    radixSort(array, size);
    end = chrono::high_resolution_clock::now();
    time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    cout << "Radix Sort\t: " << time_taken << setprecision(9) << " sec\n";

    start = chrono::high_resolution_clock::now();
    heapSort(array, size);
    end = chrono::high_resolution_clock::now();
    time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;
    cout << "Heap Sort\t: " << time_taken << setprecision(9) << " sec\n";
}

int main(){
    int a10k[10000], size10k = 10000;
    int a20k[20000], size20k = 20000;
    int a30k[30000], size30k = 30000;
    int a40k[40000], size40k = 40000;
    int a50k[50000], size50k = 50000;
    
    randomData(a10k, size10k);
    randomData(a20k, size20k);
    randomData(a30k, size30k);
    randomData(a40k, size40k);
    randomData(a50k, size50k);

    for (int i = 0; i < 5; i++){
        (i == 0) ? runtime(a10k, size10k) :
        (i == 1) ? runtime(a20k, size20k) :
        (i == 2) ? runtime(a30k, size30k) :
        (i == 3) ? runtime(a40k, size40k) :
                   runtime(a50k, size50k);
    }
    
    return 0;
}