#include <iostream>
using namespace std;


int main(){
    
    typedef struct mahasiswa {
        string nama;
        char kelas[5];
        float ipk;
    }nilai;

    nilai doni;
    nilai farid = {"Farid", "2B", 3.9};

    cout<<"Nama: "; cin>>doni.nama;
    cout<<"Kelas: "; cin>>doni.kelas;
    cout<<"IPK: "; cin>>doni.ipk;
    

    cout<<"Nama: "<<farid.nama<<endl;
    cout<<"Kelas: "<<farid.kelas<<endl;
    cout<<"IPK: "<<farid.ipk<<endl;

    return 0;
}