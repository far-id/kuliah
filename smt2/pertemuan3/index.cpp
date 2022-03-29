#include <iostream>
using namespace std;


int main(){
    // int a = 5;
    // int &b = a;

    // cout<<"nilai a = "<<a<<endl;
    // cout<<"alamat a = "<<&a<<endl;
    // cout<<"nilai b = "<<b<<endl;
    // cout<<"alamat b = "<<&b<<endl;


    int a = 5;
    int *point = &a;
    int **ppoint = &point;

    cout<<*point<<endl;
    cout<<"alamat dari a : "<<&a<<endl;
    cout<<"alamat dari point : "<<&point<<endl;
    cout<<"alamat dari ppoint : "<<&ppoint<<endl;

    cout<<ppoint;
    
    return 0;
}