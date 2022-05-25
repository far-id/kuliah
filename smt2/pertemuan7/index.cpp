#include <iostream>
using namespace std;

int tailRecursive(int n, int i) {
    if (n == 0) {
        return i;
    } else {
        return tailRecursive(n - 1, i + 1);
    }
}

int interpolationSearch(int arr[], int n, int x) {
    int low = 0;
    int high = n - 1;
    while (low <= high && x >= arr[low] && x <= arr[high]) {
        int pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (x - arr[low]));
        if (arr[pos] == x) {
            return pos;
        } else if (arr[pos] < x) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }
    return -1;
}
int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 5;
    interpolationSearch(arr, n, x);
    return 0;
}