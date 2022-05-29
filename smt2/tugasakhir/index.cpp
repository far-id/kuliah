#include <iostream>
using namespace std;

// quick sorting
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


// shell sort
void shellSort(int arr[], int n) {
    int i, j, tmp, gap;
    for (gap = n / 2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i += 1) {
            tmp = arr[i];
            for (j = i; j >= gap && arr[j - gap] > tmp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = tmp;
        }
    }
}

// insertion sort
void insertionSort(int arr[], int n) {
    int i, j, tmp;
    for (i = 1; i < n; i++) {
        tmp = arr[i];
        for (j = i - 1; j >= 0 && arr[j] > tmp; j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = tmp;
    }
}

//selection sort
void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(arr[min_idx], arr[i]);
    }
}

// bubble sort
void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}
int main(){
    int n;
    cout << "Masukkan jumlah data: ";
    cin >> n;
    int arr[n];
    cout << "Masukkan data: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    // cout << "Pilih metode sorting: " << endl;
    // cout << "1. Quick Sort" << endl;
    // cout << "2. Shell Sort" << endl;
    // cout << "3. Insertion Sort" << endl;
    // cout << "4. Selection Sort" << endl;
    // cout << "5. Bubble Sort" << endl;
    // int pilihan;
    // cin >> pilihan;
    // switch (pilihan) {
    //     case 1:
    //         quickSort(arr, 0, n - 1);
    //         break;
    //     case 2:
    //         shellSort(arr, n);
    //         break;
    //     case 3:
    //         insertionSort(arr, n);
    //         break;
    //     case 4:
    //         selectionSort(arr, n);
    //         break;
    //     case 5:
    //         bubbleSort(arr, n);
    //         break;
    //     default:
    //         cout << "Pilihan tidak ada" << endl;
    //         break;
    // }
    // cout << "Hasil: ";
    // for (int i = 0; i < n; i++)
    //     cout << arr[i] << " ";
    // cout << endl;

    quickSort(arr, 0, n - 1);
    cout << "Hasil quicksort: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    shellSort(arr, n);
    cout << "Hasil shellsort: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    insertionSort(arr, n);
    cout << "Hasil insertionsort: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    
    selectionSort(arr, n);
    cout << "Hasil selectionsort: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    bubbleSort(arr, n);
    cout << "Hasil bubblesort: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    
    return 0;
}