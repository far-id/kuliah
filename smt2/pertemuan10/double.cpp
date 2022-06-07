#include <iostream>
#include <limits>
using namespace std;

// double linear linked list
struct wraparound {
    string nama;
    struct wraparound *prev, *next;
} *baru, *awal = NULL, *akhir = NULL, *current;

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

void btBaru(){
    string input;
    cout << "Tambah Data" << endl;
    baru = (wraparound*)malloc(sizeof(wraparound));
    cout << "Input Nama : ";
    cin.ignore();
    getline(cin, input);
    baru->nama = input;
    baru->next = NULL;
    baru->prev = NULL;
}

void tambahDepan(){
    btBaru();
    if (awal == NULL){
        // jika sekarang adalah awal maka next dan prevnya sama dengan NULL
        awal = baru;
        akhir = baru;
        akhir->next = NULL;
        akhir->prev = NULL;
    }else {
        // jika sudah ada data awal maka nextnya sama dengan awal dan awal->prev sama dengan data baru
        baru->next = awal;
        awal->prev = baru;
        awal = baru;
    }
}

void tambahBelakang(){
    btBaru();
    // jika awal kosong maka data baru akan menjadi awal dan akhir
    if (awal == NULL){
        awal = baru;
    }else {
        // jika sudah ada data maka akhir->next dari data sebelumnya mereference ke data baru
        akhir->next = baru;
    }
    // buat data baru menjadi data terakhir
    baru->prev = akhir;
    akhir = baru;
    akhir->next = NULL;
}

void tampil(){
    if (awal == NULL){
        cout << "Data Kosong" << endl;
    }else{
        // menampilkan data dari data awal sampai data->next == NULL
        current = awal;
        int i = 1;
        cout<<"Data sekarang : \n";
        while (current != NULL){
            cout << i<<". "<< current->nama << "\n";
            current = current->next;
            i++;
        }
        cout << endl;
    }
}   

void hapusDepan(){
    if (awal == NULL){
        cout << "Data Kosong" << endl;
    }else{
        // memindahkan nilai awal ke current, mengganti nilai awal menjadi data setelahnya, buat awal->prev yang baru menjadi NULL dan mengalokasikan data current
        current = awal;
        awal = awal->next;
        awal->prev = NULL;
        free(current);
    }
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
        pilih = inputInt();
        cout<<endl;
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