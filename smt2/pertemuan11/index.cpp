#include <iostream>
using namespace std;


void randomData(int arr[], int &n){
    cout<<"Data sekarang : ";
    // mengisi tiap element array dengan nilai random  0 - 30
    for (int i = 0; i < n; i++){
        arr[i] = rand() % 30;
        cout << arr[i] << " ";
    }
}

void mergeSort(int *arr, int n){
    // temp untuk menyimpan data yang akan diurutkan
    // mid untuk menentukan batasan data yang akan diurutkan
    // ijk unyuk pengulangan pengurutan
    int temp[n], mid = n/2, i, j, k;
    // jika panjang array lebih dari 1 maka akan dilakukan pengurutan
    if (n > 1){
        // pengurutan bagian kiri
        mergeSort(arr, mid);
        // pengurutan bagian kanan
        mergeSort(arr + mid, n - mid);
        // penempatan data yang di pecah dan merge ke array temp
        for (i = 0; i < n; i++){
            temp[i] = arr[i];
        }
        // pengurutan data ke temp
        for (i = 0, j = mid, k = 0; k < n; k++){
            if (j >= n){
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

void selectionSort(int *arr, int n) {
    int i, j, min_idx;
    // mengulang sebanyak n-1 kali untuk menentukan posisi minimum
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        // mencari posisi minimum dari i+1 sampai n
        for (j = i + 1; j < n; j++)
            // jika ditemukan nilai yang lebih kecil, maka min_idx akan berubah
            if (arr[j] < arr[min_idx])
                min_idx = j;
        // jika posisi minimum bukan i, maka akan dilakukan swap
        swap(arr[min_idx], arr[i]);
    }
}

void shellSort(int *arr, int n) {
    int i, j, temp, gap;
    // perulangan untuk mengatur jarak pengurutan
    for (gap = n / 2; gap > 0; gap /= 2) {
        // perulangan untuk mengurutkan data
        for (i = gap; i < n; i += 1) {
            temp = arr[i];
            // perulangan untuk mencari posisi data yang akan diurutkan
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}


void pilihan(){
    cout<<"=== Pilihan ==="<<endl;
    cout<<"1. Tampilkan Pilihan"<<endl;
    cout<<"2. Acak Data"<<endl;
    cout<<"3. ASC Merge Sort"<<endl;
    cout<<"4. DESC Merge Sort"<<endl;
    cout<<"5. ASC Selection Sort"<<endl;
    cout<<"6. DESC Selection Sort"<<endl;
    cout<<"7. ASC Shell Sort"<<endl;
    cout<<"8. DESC Shell Sort"<<endl;
    cout<<"9. keluar"<<endl;
}

int main(){
    int arr[15], n = sizeof(arr)/sizeof(arr[0]), con;
    pilihan();
    // random data
    randomData(arr, n);
    do{
        cout << "\n\nPilihan : ";
        cin>>con;
        switch (con){
        case 1 : pilihan();
            break;
        case 2 : randomData(arr, n);
            break;
        case 3 : mergeSort(arr, n);
            cout << "sort dengan ASC merge sort : ";
            for (int i = 0; i < n; i++)
                cout<<arr[i]<<" ";
            break;
        case 4 : mergeSort(arr, n);
            cout << "sort dengan DESC merge sort : ";
            for (int i = n-1; i >= 0; i--)
                cout<<arr[i]<<" ";
            break;
        case 5 : selectionSort(arr, n);
            cout << "sort dengan ASC selection sort : ";
            for (int i = 0; i < n; i++)
                cout<<arr[i]<<" ";
            break;
        case 6 : selectionSort(arr, n);
            cout << "sort dengan DESC selection sort : ";
            for (int i = n-1; i >= 0; i--)
                cout<<arr[i]<<" ";
            break;
        case 7 : shellSort(arr, n);
            cout << "sort dengan ASC shell sort : ";
            for (int i = 0; i < n; i++)
                cout<<arr[i]<<" ";
            break;
        case 8 : shellSort(arr, n);
            cout << "sort dengan DESC shell sort : ";
            for (int i = n-1; i >= 0; i--)
                cout<<arr[i]<<" ";
            break;
        case 9 : cout<<"\1\tTerima Kasih\t\1"<<endl;
            break;
        default: cout<<"Pilihan tidak ada"<<endl;
            break;
        }
    }while(con != 9);

    return 0;
}