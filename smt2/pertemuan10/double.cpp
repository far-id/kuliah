// double linked list
#include <iostream>
using namespace std;

// double circular linked list
struct sampul {
    int angka;
    struct sampul *prev, *next;
} *baru, *awal = NULL, *akhir = NULL, *current, *hapus;

void btBaru(){
    cout << "Tambah Data" << endl;
    baru = (sampul*)malloc(sizeof(sampul));
    cout << "Input Angka : ";
    cin >> baru->angka;
    baru->next = NULL;
    baru->prev = NULL;
}

void tambahDepan(){
    btBaru();
    if (awal == NULL){
        awal = baru;
        akhir = baru;
        akhir->next = NULL;
        akhir->prev = NULL;
    }else {
        baru->next = awal;
        awal->prev = baru;
        awal = baru;
    }
}

void tambahBelakang(){
    btBaru();
    if (awal == NULL){
        awal = baru;
    }else {
        akhir->next = baru;
    }
    akhir = baru;
    akhir->next = NULL;
    akhir->prev = NULL;
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

void hapusDepan(){
    if (awal == NULL){
        cout << "Data Kosong" << endl;
    }else{
        current = awal;
        awal = awal->next;
        free(current);
    }
}

void hapusBelakang(){
    current = awal;
    while (current){
        if (current->next == akhir){
            hapus = akhir;
            akhir = current;
            akhir->next = NULL;
            delete hapus;
            break;
        }
        current = current->next;
    }
}
int main(){
    int pilih;
    do{
        cout << "1. Tambah Depan" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Hapus Depan" << endl;
        cout << "4. Hapus Belakang" << endl;
        cout << "5. Tampil" << endl;
        cout << "6. Exit" << endl;
        cout << "Pilih : ";
        cin >> pilih;
        switch (pilih){
            case 1 : tambahDepan();
                break;
            case 2 : tambahBelakang();
                break;
            case 3 : hapusDepan();
                break;
            case 4 : hapusBelakang();
                break;
            case 5 : tampil();
                break;
            case 6 : exit(0);
                break;
            default: cout << "Pilihan tidak ada" << endl;
        }
    }while (pilih != 6);
    return 0;
}