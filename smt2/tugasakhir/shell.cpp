#include <iostream>
using namespace std;

//shell sort
void shellSort(int arr[], int n) {
    int i, j, tmp, gap;
    for (gap = n / 2; gap > 0; gap /= 2 + 1) {
        cout<<"GAP :"<<gap<<"\t";
        for (i = gap; i < n; i += 1) {
            cout<<"\n\ti:"<<i+1<<"; ";
            tmp = arr[i];
            for (j = i; j >= gap && arr[j - gap] > tmp; j -= gap){
                cout<<"j:"<<j+1<<" ";
                arr[j] = arr[j - gap];
            }
            arr[j] = tmp;
            cout<<"J akhir:"<<j+1;
        }
        cout<<"\n";
    }
}

int main(){
    int array[10] ={12,4,6,7,1,19,5,3,14,16}, n = sizeof(array)/sizeof(array[0]);

    cout << "Array sebelum sort : ";
    for (int i = 0; i < n; i++){
        cout << array[i] << " ";
    }
    cout << endl;
    shellSort(array, n);
    cout << "Array sesudah sort : ";
    for (int i = 0; i < n; i++)
        cout << array[i] << " ";
    cout << endl;

    return 0;
}