#include <iostream>
using namespace std;

//shell sort
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

int main(){
    int array[1000], n = sizeof(array)/sizeof(array[0]);
    // auto fill random int from 0 to 10000
    for (int i = 0; i < n; i++){
        array[i] = rand() % 10000;
    }
    // print array before sort
    cout << "Array before sort : ";
    for (int i = 0; i < n; i++){
        cout << array[i] << " ";
    }
    cout << endl;
    // sort array
    shellSort(array, n);
    // print array after sort
    cout << "Array after sort : ";
    for (int i = 0; i < n; i++){
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}