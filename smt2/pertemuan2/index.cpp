#include <iostream>
using namespace std;


int main(){
    
    typedef struct nilai {
        string nama;
        int semester;
        float ips;
    }ipk;

    ipk farid[];
    
    farid[0].nama = "Farid";
    farid[0].semester = 1;
    farid[0].ips = 3.5;

    farid[1].nama = "Farid";
    farid[1].semester = 2;
    farid[1].ips = 3.5;

    farid[2].nama = "Farid";
    farid[2].semester = 3;
    farid[2].ips = 3.5;

    for (int i = 0; i < sizeof(farid)/sizeof(farid[0]); i++) {
        cout<<"Nama : "<<farid[i].nama<<endl;
        cout<<"Semester : "<<farid[i].semester<<endl;
        cout<<"IPK : "<<farid[i].ips<<endl;
    }
    

    return 0;
}