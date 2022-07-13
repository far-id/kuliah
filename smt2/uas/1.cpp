#include<iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>

using namespace std;

int pil;
void plh(int pil);
void bt_br();
void tbh_blk();
void tbh_dpn();
void hapus_dpn();
void hapus_belakang();
void tmpl();
struct simpul
{
    char angka[10];
    struct simpul *next;
} * baru, *awal = NULL, *akhir = NULL, *hapus, *bantu;

void clrscr()
{
    system("cls");
}
int main()
{
    int pil;
    do
    {
        cout << "\n\nPROGRAM LINKEDLIST "<<endl;
        cout<< "1. Tambah Depan" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Hapus Depan" << endl;
        cout << "4. Hapus Belakang" << endl;
        cout << "5. Tampilkan" << endl;
        cout << "6. Keluar\n"<< endl;
        cout<<"Masukan pilihan anda [1 s/d 6] : ";
        cin>>pil;
        plh(pil);
    } while (pil != 6);
    return 0;
}
void plh(int pil)
{
    if (pil == 1)
        tbh_dpn();
    else if (pil == 2)
        tbh_blk();
    else if (pil == 3)
        hapus_dpn();
    else if (pil == 4)
        hapus_belakang();
    else if (pil == 5)
        tmpl();
    else
        cout << "selesai";
}
void bt_br()
{
    cout << "\nTambah Data\n";
    cout << "===========\n\n";
    baru = (simpul *)malloc(sizeof(struct simpul));
    cout << "Input Angka : ";
    cin>>baru->angka;
    baru->next = NULL;
}

void tbh_blk()
{
    bt_br();
    if (awal == NULL)
    {
        awal = baru;
    }else{
        akhir->next = baru;
    }
    akhir = baru;
    akhir->next = NULL;
    cout << endl << endl;
    tmpl();
}

void tbh_dpn()
{
    bt_br();
    if (awal == NULL)
    {
        awal = baru;
        akhir = baru;
        akhir->next = NULL;
    }
    else
    {
        baru->next = awal;
        awal = baru;
    }
    cout << endl << endl;
    tmpl();
}
void hapus_dpn()
{
    if (awal == NULL){
        cout << "Data Kosong" << endl;
    }else{
        // memindahkan nilai awal ke bantu, mengganti nilai awal menjadi data setelahnya dan mengalokasikan data bantu
        bantu = awal;
        awal = awal->next;
        free(bantu);
    }
    tmpl();
}
void hapus_belakang()
{
    bantu = awal;
    if (awal == NULL){
        cout << "Data Kosong" << endl;
    }else if (awal->next == NULL){
        // jika awal adalah akhir maka buat variabel awal dan akhir menjadi NULL dan alokasikan variabel bantu
        awal = NULL;
        akhir = NULL;
        free(bantu);
    }else{
        // cek apakah data setelahnya adalah akhir
        while (bantu->next != akhir){
            bantu = bantu->next;
        }
        // jika data setelahnya adalah akhir maka putus reference ke data setelahnya, buat data itu jadi akhir dan alokasikan variabel bantu
        bantu->next = NULL;
        akhir = bantu;
        free(akhir->next);
    }
    tmpl();
}
void tmpl()
{
    if (awal == NULL)
        cout << "Kosong";
    else
    {
        bantu = awal;
        while (bantu != NULL)
        {
            cout << " " << bantu->angka;
            bantu = bantu->next;
        }
    }
    getch();
}