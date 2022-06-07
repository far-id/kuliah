#include <iostream>
using namespace std;

// quick sorting ASC
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

// quick sorting DESC
void quickSortDescending(int arr[], int left, int right) {
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];
    while (i <= j) {
        while (arr[i] > pivot)
            i++;    
        while (arr[j] < pivot)
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
        quickSortDescending(arr, left, j);
    if (i < right)
        quickSortDescending(arr, i, right);
}

// shell sort ASC
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

// shell sort DESC
void shellSortDescending(int arr[], int n) {
    int i, j, tmp, gap;
    for (gap = n / 2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i += 1) {
            tmp = arr[i];
            for (j = i; j >= gap && arr[j - gap] < tmp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = tmp;
        }
    }
}

// insertion sort ASC
void insertionSort(int arr[], int n) {
    int i, j, tmp;
    for (i = 1; i < n; i++) {
        tmp = arr[i];
        for (j = i - 1; j >= 0 && arr[j] > tmp; j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = tmp;
    }
}
// insertion sort DESC
void insertionSortDescending(int arr[], int n) {
    int i, j, tmp;
    for (i = 1; i < n; i++) {
        tmp = arr[i];
        for (j = i - 1; j >= 0 && arr[j] < tmp; j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = tmp;
    }
}

//selection sort ASC
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
// selection sort DESC
void selectionSortDescending(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] > arr[min_idx])
                min_idx = j;
        swap(arr[min_idx], arr[i]);
    }
}

// bubble sort ASC
void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

// bubble sort DESC
void bubbleSortDescending(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] < arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

int main(){
    // auto fill from 0 to 100 random integer in array
    int arr[100];
    for (int i = 0; i < 100; i++)
        arr[i] = rand() % 100;
    // print array
    for (int i = 0; i < 100; i++)
        cout << arr[i] << " ";
    cout << endl;
    // int n = 10, arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 10, 9};
    
    // cout<<"Quick Sort Ascending"<<endl;
    // quickSort(arr, 0, n - 1);
    // for (int i = 0; i < n; i++)
    //     cout<<arr[i]<<" ";
    // cout<<endl;

    // cout<<"Quick Sort Descending"<<endl;
    // quickSortDescending(arr, 0, n - 1);
    // for (int i = 0; i < n; i++)
    //     cout<<arr[i]<<" ";
    // cout<<endl;

    // cout<<"Shell Sort Ascending"<<endl;
    // shellSort(arr, n);
    // for (int i = 0; i < n; i++)
    //     cout<<arr[i]<<" ";
    // cout<<endl;

    // cout<<"Shell Sort Descending"<<endl;
    // shellSortDescending(arr, n);
    // for (int i = 0; i < n; i++)
    //     cout<<arr[i]<<" ";
    // cout<<endl;

    // cout<<"Insertion Sort Ascending"<<endl;
    // insertionSort(arr, n);
    // for (int i = 0; i < n; i++)
    //     cout<<arr[i]<<" ";
    // cout<<endl;

    // cout<<"Insertion Sort Descending"<<endl;
    // insertionSortDescending(arr, n);
    // for (int i = 0; i < n; i++)
    //     cout<<arr[i]<<" ";
    // cout<<endl;
    
    // cout<<"Selection Sort Ascending"<<endl;
    // selectionSort(arr, n);
    // for (int i = 0; i < n; i++)
    //     cout<<arr[i]<<" ";
    // cout<<endl;

    // cout<<"Selection Sort Descending"<<endl;
    // selectionSortDescending(arr, n);
    // for (int i = 0; i < n; i++)
    //     cout<<arr[i]<<" ";
    // cout<<endl;
    
    // cout<<"Bubble Sort Ascending"<<endl;
    // bubbleSort(arr, n);
    // for (int i = 0; i < n; i++)
    //     cout<<arr[i]<<" ";
    // cout<<endl;
    
    // cout<<"Bubble Sort Descending"<<endl;
    // bubbleSortDescending(arr, n);
    // for (int i = 0; i < n; i++)
    //     cout<<arr[i]<<" ";
    // cout<<endl;
    
    return 0;
}