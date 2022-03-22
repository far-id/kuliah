#include <iostream>
using namespace std;


int main(){
    // int a = 5;
    // int &b = a;

    // cout<<"nilai a = "<<a<<endl;
    // cout<<"alamat a = "<<&a<<endl;
    // cout<<"nilai b = "<<b<<endl;
    // cout<<"alamat b = "<<&b<<endl;


    // int a = 5;
    // int *point = &a;
    // int **ppoint = &point;

    // cout<<*point<<endl;
    // cout<<"alamat dari a : "<<&a<<endl;
    // cout<<"alamat dari point : "<<&point<<endl;
    // cout<<"alamat dari ppoint : "<<&ppoint<<endl;

    // cout<<ppoint;

    // typedef struct buku {
    //     string judul;
    //     string pengarang;
    //     int harga;
    // } perpustakaan;

    // perpustakaan *buku;
    // buku = new perpustakaan;
    // buku->judul = "C++";
    // buku->pengarang = "Budi";
    // buku->harga = 100000;

    // cout<<&buku<<endl;
    // cout<<&buku->judul<<endl;
    // cout<<&buku->pengarang<<endl;
    // cout<<&buku->harga<<endl;

    // delete buku;

    typedef struct buku {
        string judul;
        string pengarang;
        int harga;
    } perpustakaan;

    perpustakaan *buku;
    buku = new perpustakaan [3];
    buku[0].judul = "C++";
    buku[0].pengarang = "Farid";
    buku[0].harga = 100000;

    buku[1].judul = "Javascript";
    buku[1].pengarang = "Farid";
    buku[1].harga = 200000;

    buku[2].judul = "PHP";
    buku[2].pengarang = "Farid";
    buku[2].harga = 150000;

    for (int i = 0; i < 4; i++)
    {
        cout<<"Judul : "<<buku[i].judul<<endl;
        cout<<"Pengarang : "<<buku[i].pengarang<<endl;
        cout<<"Harga : "<<buku[i].harga<<endl<<endl;
    }
    
    return 0;
}