#include <iostream>
using namespace std;

struct sampul {
    int angka;
    struct sampul *next;
} *baru, *awal = NULL, *akhir = NULL, *current;

void btBaru(){
    cout << "Tambah Data" << endl;
    baru = (sampul*)malloc(sizeof(sampul));
    cout << "Input Angka : ";
    cin >> baru->angka;
    baru->next = NULL;
}

void tambahDepan(){
    btBaru();
    if (awal == NULL){
        awal = baru;
        akhir = baru;
        akhir->next = NULL;
    }else {
        baru->next = awal;
        awal = baru;
    }
}

// void tambahBelakang(){
//     btBaru();
//     if (awal == NULL){
//         awal = baru;
//     }
//     else{
//         akhir = baru;
//         akhir->next = NULL;
//     }
// }

void tambahBelakang(){
    btBaru();
    if (awal == NULL){
        awal = baru;
    }else {
        akhir->next = baru;
    }
    akhir = baru;
    akhir->next = NULL;
}

void tampil(){
    if (awal == NULL){
        cout << "Data Kosong" << endl;
    }else{
        current = awal;
        while (current != NULL){
            cout << current->angka << " ";
            current = current->next;
        }
        cout << endl;
    }
}

void pilih(){
    int pilih;
    bool con = true;
    while (con)
    {
        cout << "Pilih Menu : " << endl;
        cout << "1. Tambah Depan" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Tampilkan" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih : ";
        cin >> pilih;
        switch (pilih)
        {
        case 1:
            tambahDepan();
            break;
        case 2:
            tambahBelakang();
            break;
        case 3:
            tampil();
            break;
        case 4:
            con = false;
            break;
        default:
            cout << "Pilihan tidak ada" << endl;
            break;
        }
    }
    
}
int main(){
    pilih ();
    return 0;
}
