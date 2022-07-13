#include <iostream>
using namespace std;

void bubbleSort(int arr[], int size)
{
    int i, j;
    for (i = 0; i < size - 1; i++)
        for (j = 0; j < size - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

int main(){
    int array[10]; // deklarasi array
    for (int i = 0; i < 10; i++) // random data
        array[i] = rand() % 20;

    for (int i = 0; i < 10; i++)    // print data yang masih random
    {
        cout << array[i] << " ";
    }

    bubbleSort(array, 10); // sorting
    cout<<"\n\n";
    for (int i = 0; i < 10; i++)    // print data yang sudah disort
    {
        cout << array[i] << " ";
    }
    

    return 0;
}