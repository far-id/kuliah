#include <iostream>
using namespace std;

int main(){
  // int a,b,c;

  // a = 100;
  // b = 250;

  // cout<< ("Nilai A : ") << a << endl; // kurung ga bikin error ga tau kenapa
  // cout<< "Nilai B : " << b << endl;

  // c = a;
  // a = b;
  // b = c;

  // cout<< "Setelah pertukaran \n";
  // cout << "Nilai A : " << a << endl;
  // cout << "Nilai B : " << b;

  int nilai;
  cout << "masukkan nilai : ";
  cin>> nilai;

  if(nilai > 70)
    cout<<"anda lulus";// ga pake {} tetep jalan
  else
    cout<<"anda gagal";
}