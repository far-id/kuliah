#include <iostream>
#include <limits>
using namespace std;

struct sampul {
    int angka;
    struct sampul *next;
} *baru, *awal = NULL, *akhir = NULL, *current, *hapus;

int inputInt(){
    int x = 0;
    // jika input mengalami kegagalan ulangi input
    while (!(cin >> x)){
        cin.clear();
        cin.ignore(numeric_limits<int>::max(), '\n');
        cout << "Input bukan integer. coba lagi : ";
    }
    return x;
}

void tampil(){
    if (awal == NULL){
        cout << "Data Kosong" << endl;
    }else{
        // menampilkan data dari data awal sampai data->next == NULL
        current = awal;
        cout<<"Data : ";
        while (current != NULL){
            cout << current->angka << " ";
            current = current->next;
        }
        cout << "\n\n";
    }
} 

void btBaru(){
    cout << "Tambah Data" << endl;
    baru = (sampul*)malloc(sizeof(sampul));
    cout << "Input Angka : ";
    baru->angka = inputInt();
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
    tampil();
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
    tampil();
}


void hapusDepan(){
    if (awal == NULL){
        cout << "Data Kosong" << endl;
    }else{
        // memindahkan nilai awal ke current, mengganti nilai awal menjadi data setelahnya dan mengalokasikan data current
        current = awal;
        awal = awal->next;
        free(current);
    }
    tampil();
}

void hapusBelakang(){
    current = awal;
    if (awal == NULL){
        cout << "Data Kosong" << endl;
    }else if (awal->next == NULL){
        // jika awal adalah akhir maka buat variabel awal dan akhir menjadi NULL dan alokasikan variabel current
        awal = NULL;
        akhir = NULL;
        free(current);
    }else{
        // cek apakah data setelahnya adalah akhir
        while (current->next != akhir){
            current = current->next;
        }
        // jika data setelahnya adalah akhir maka putus reference ke data setelahnya, buat data itu jadi akhir dan alokasikan variabel current
        current->next = NULL;
        akhir = current;
        free(akhir->next);
    }
    tampil();
}

void pilih(){
    int pilih;
    bool con = true;
    while (con)
    {
        cout << "Pilih Menu : " << endl;
        cout << "1. Tambah Depan" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Hapus Depan" << endl;
        cout << "4. Hapus Belakang" << endl;
        cout << "5. Tampilkan" << endl;
        cout << "6. Keluar" << endl;
        cout << "Pilih : ";
        pilih = inputInt();
        cout<<endl;
        switch (pilih)
        {
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
        case 6 : con = false;
            break;
        default : cout << "Pilihan tidak ada" << endl;pilih = 0;
        }
    }
}
int main(){
    pilih ();
    return 0;
}
