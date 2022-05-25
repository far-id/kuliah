#include <iostream>
#include <limits>
using namespace std;

// digunakan untuk input integer, akan meminta inputan ulang ketika input bukan integer
int inputInt()
{
    int x = 0;
    while (!(cin >> x))
    {
        cin.clear();
        cin.ignore(numeric_limits<int>::max(), '\n');
        cout << "Input bukan integer. coba lagi : ";
    }
    return x;
}

// case 1
void dataMahasiswa()
{
    string nama, kelas;
    int nim;
    
    // input nama
    cout << "Nama : ";
    cin.ignore();
    getline(cin, nama);

    // input nim
    cout << "NIM : ";
    nim = inputInt();
    
    // input kelas
    cout << "Kelas : ";
    cin.ignore();
    getline(cin, kelas);

    cout << "\n\nHasil input :\n";
    cout << "Nama : " << nama << endl;
    cout << "NIM : " << nim << endl;
    cout << "Kelas : " << kelas << endl;
}

typedef struct pegawai
{
    string nama, jabatan;
    int usia;
} tipedataPegawai;
// case 2
void dataPegawai()
{
    tipedataPegawai pegawai[5];
    cout << "Harap inputkan 5 data pegawai :\n";
    for (int i = 0; i < sizeof(pegawai)/sizeof(pegawai[0]); i++)
    {
        cout << i+1;
        // input nama
        cout << "Nama : ";
        cin.ignore();
        getline(cin, pegawai[i].nama);

        // input jabatan
        cout << "Jabatan : ";
        getline(cin, pegawai[i].jabatan);

        // input usia
        cout << "Usia : ";
        pegawai[i].usia = inputInt();

        cout << endl;
    }


    cout << "\n\nHasil input :\n";
    for (int i = 0; i < sizeof(pegawai)/sizeof(pegawai[0]); i++)
    {
        cout << "Nama : " << pegawai[i].nama << endl;
        cout << "Jabatan : " << pegawai[i].jabatan << endl;
        cout << "Usia : " << pegawai[i].usia << endl << endl;
    }
}

// case 3
void dataBuku()
{
    typedef struct buku
    {
        string judul, penerbit;
        int harga;
    } tipedataBuku;
    tipedataBuku* buku = new tipedataBuku;
    string *ptjudul, *ptpenerbit, **ptptjudul, **ptptpenerbit;
    int *ptharga, **ptptharga;

    cout << "Harap inputkan data buku :\n";
    // input judul
    cout << "Judul : ";
    cin.ignore();
    getline(cin, buku->judul);

    // input penerbit
    cout << "Penerbit : ";
    getline(cin, buku->penerbit);

    // input harga
    cout << "Harga : ";
    buku->harga = inputInt();
    
    ptjudul = &buku->judul;
    ptpenerbit = &buku->penerbit;
    ptharga = &buku->harga;

    ptptjudul = &ptjudul;
    ptptpenerbit = &ptpenerbit;
    ptptharga = &ptharga;

    cout << "\n\nHasil input :\n";

    cout << "Judul : "<< **ptptjudul << endl;
    cout << "Penebit : "<< **ptptpenerbit << endl;
    cout << "Harga : "<< **ptptharga << endl;

    delete(buku);
    
}


int main(){
    bool condition = true;
    int menu;

    cout << "Pilih menu sesuai nomor dibawah ini :\n";
    cout << "1. Data Mahasiswa\n";
    cout << "2. Data Pegawai\n";
    cout << "3. Data Buku\n";
    cout << "4. Keluar\n";
    while (condition)
    {
        // memilih menu
        cout << "Pilih menu (1/2/3/4): ";
        menu = inputInt();

        switch (menu)
        {
        case 1:
            dataMahasiswa();
            break;
        case 2:
            dataPegawai();
            break;
        case 3:
            dataBuku();
            break;
        default: // untuk menghentikan program
            condition = false;
            break;
        }
    }
    return 0;
}