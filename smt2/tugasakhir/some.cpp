#include <bits/stdc++.h>
#include <chrono>
using namespace std;

// A sample function whose time taken to
// be measured
void shellSort(int arr[], int n)
{
    int i, j, tmp, gap;
    for (gap = n / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < n; i += 1)
        {
            tmp = arr[i];
            for (j = i; j >= gap && arr[j - gap] > tmp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = tmp;
        }
    }
}
int main()
{
    auto start = chrono::high_resolution_clock::now();

    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);

    int array[50000], n = sizeof(array) / sizeof(array[0]);
    // auto fill random int from 0 to 10000
    for (int i = 0; i < n; i++)
    {
        array[i] = rand() % 10;
    }
    // print array before sort
    // cout << "Array before sort : ";
    // for (int i = 0; i < n; i++)
    // {
    //     cout << array[i] << " ";
    // }
    // cout << endl;
    // sort array
    shellSort(array, n);
    // print array after sort
    // cout << "Array after sort : ";
    // for (int i = 0; i < n; i++)
    // {
    //     cout << array[i] << " ";
    // }
    // cout << endl;

    auto end = chrono::high_resolution_clock::now();

    // Calculating total time taken by the program.
    double time_taken =
        chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    time_taken *= 1e-9;

    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(9);
    cout << " sec" << endl;
    return 0;
}
