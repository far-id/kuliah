#include <iostream>
#include <limits>
using namespace std;

// double linear linked list
struct wraparound {
    int data;
    struct wraparound *prev, *next;
} *newData, *start = NULL, *last = NULL, *current;

int inputInt(){
    int x = 0;
    // jika input mengalami kegagalan ulangi input
    while (!(cin >> x)){
        cin.clear(); // menghilangkan flag error
        cin.ignore(numeric_limits<int>::max(), '\n');
        cout << "Input bukan integer. coba lagi : ";
    }
    return x;
}

void tampil()
{
    if (start == NULL){
        cout << "Data Kosong" << endl;
    }else{
        // menampilkan data dari data start sampai data->next == NULL
        current = start;
        cout << "Data sekarang : \n";
        while (current != NULL)
        {
            // cout << current->prev << "<- " << current->data << " -> " << current->next << " | " << &current << endl;
            cout << "\4 " << current->data << "\n";
            current = current->next;
        }
        cout << endl;
        free(current);
    }
}

void btBaru(){
    cout << "Tambah Data" << endl;
    //membuat list baru
    newData = (wraparound*)malloc(sizeof(wraparound));
    //input data
    cout << "Input data angka : ";
    newData->data = inputInt();
    newData->next = NULL;
    newData->prev = NULL;
}

void tambahDepan(){
    btBaru();
    if (start == NULL){
        // jika sekarang adalah start maka next dan prevnya sama dengan NULL
        start = newData;
        last = newData;
        last->next = NULL;
        last->prev = NULL;
    }else {
        // jika sudah ada data start maka newData->next sama dengan start dan start->prev sama dengan data newData
        newData->next = start;
        start->prev = newData;
        start = newData;
    }
    tampil();
}

void tambahSetelah(){
    if (start == NULL){
        tambahDepan();
    }else{
        // jika start tidak kosong
        cout << "Data disisipkan setelah angka : ";
        int pilih;
        pilih = inputInt();
        btBaru();
        current = start;
        while (current != NULL){
            if (current->data == pilih){
                // jika data yang dipilih sama dengan data current maka
                if (current->next == NULL){
                    // jika current->next == NULL maka current->next sama dengan newData dan newData->prev sama dengan current
                    current->next = newData;
                    newData->prev = current;
                    last = newData;
                    last->next = NULL;
                }else{
                    // jika current->next != NULL maka current->next->prev sama dengan newData dan newData->next sama dengan current->next
                    newData->next = current->next;
                    current->next->prev = newData;
                    current->next = newData;
                    newData->prev = current;
                }
                break;
            }
            current = current->next;
        }
        if (current == NULL){
            cout << "Data tidak ditemukan" << endl;
        }
        tampil();
    }
}

void tambahBelakang(){
    btBaru();
    // jika start kosong maka data newData akan menjadi start dan last
    if (start == NULL){
        start = newData;
    }else {
        // jika sudah ada data maka last->next dari data sebelumnya mereference ke data newData
        last->next = newData;
    }
    // buat data newData menjadi data last
    newData->prev = last;
    last = newData;
    last->next = NULL;
    tampil();
}
  

void hapusDepan(){
    if (start == NULL){
        cout << "Data Kosong" << endl;
    }else{
        // memindahkan nilai start ke current, mengganti nilai start menjadi data setelahnya, buat start->prev yang baru menjadi NULL dan mengalokasikan data current
        current = start;
        start = start->next;
        start->prev = NULL;
        free(current);
    }
    tampil();
}

void hapusBelakang(){
    current = start;
    if (start == NULL){
        cout << "Data Kosong" << endl;
    }else if (start->next == NULL){
        // jika start adalah last maka buat variabel start dan last menjadi NULL dan alokasikan variabel current
        start = NULL;
        last = NULL;
        free(current);
    }else{
        // cek apakah data setelahnya adalah last
        while (current->next != last){
            current = current->next;
        }
        // jika data setelahnya adalah last maka putus reference ke data setelahnya, buat data itu jadi last dan alokasikan variabel current
        current->next = NULL;
        last = current;
        free(last->next);
    }
    tampil();
}

void hapusSetelah(){
    if (start == NULL){
        cout << "Data Kosong" << endl;
    }else{
        cout << "Data yang dihapus setelah angka : ";
        int n;
        n = inputInt();
        current = start;
        while (current != NULL){
            if (current->data == n){
                // jika data yang din sama dengan data current maka
                if (current->next == NULL){
                    // jika current->next == NULL maka tidak ada data setelahnya yang haris dihapus
                    cout << "Tidak ada data setelah " << n << endl;
                } else if(current->next->next == NULL){
                    // jika data setelah data yang dihapus adalah NULL
                    current->next = NULL;
                    last = current;                    
                }else{
                    // jika data setelah data yg dihapus bukan NULL maka prev dari data setelah yg dihapus adalah current
                    current->next->next->prev = current;
                    current->next = current->next->next;
                }
                break;
            }
            current = current->next;
        }
        if (current == NULL){
            cout << "Data tidak ditemukan" << endl;
        }
        tampil();
    }
}

void pilihan(){
    cout << "1. Tampilkan Pilihan" << endl;
    cout << "2. Tambah Depan" << endl;
    cout << "3. Tambah Belakang" << endl;
    cout << "4. Tambah Setelah" << endl;
    cout << "5. Hapus Depan" << endl;
    cout << "6. Hapus Belakang" << endl;
    cout << "7. Hapus Setelah" << endl;
    cout << "8. Tampilkan Data" << endl;
    cout << "9. Keluar" << endl;
}
int main(){
    int pilih;
    pilihan();
    do{
        cout << "Pilih (1-9): ";
        pilih = inputInt();
        cout<<endl;
        switch (pilih){
            case 1 : pilihan();
                break;
            case 2 : tambahDepan();
                break;
            case 3 : tambahBelakang();
                break;
            case 4 : tambahSetelah();
                break;
            case 5 : hapusDepan();
                break;
            case 6 : hapusBelakang();
                break;
            case 7 : hapusSetelah();
                break;
            case 8 : tampil();
                break;
            case 9 : cout << "Terima Kasih" << endl;
                break;
            default: cout << "Pilihan tidak ada" << endl;
                break;
        }
    }while (pilih != 9);
    return 0;
}