#include <iostream>
using namespace std;


int main(){
    int a = 5;
    int &b = a;

    cout<<"nilai a = "<<a<<endl;
    cout<<"alamat a = "<<&a<<endl;
    cout<<"nilai b = "<<b<<endl;
    cout<<"alamat b = "<<&b<<endl;

    return 0;
}