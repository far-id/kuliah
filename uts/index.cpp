#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
  float phi, r;
  int condition;

  phi = 3.14;

  cout<<"\tMENU LINGKARAN\n";
  cout<<"1. Menghitung Luas Lingkaran\n";
  cout<<"2. Menghitung Keliling Lingkaran";
  cout<<"3. Keluar Program\n";
  
  cout<<"\nPilih salah satu dari menu di atas (1, 2, 3) : ";
  cin>>condition;

  switch (condition)
  {
  case 1:
    cout<<"Masukkan jari-jari : ";
    cin>>r;
    cout<<"\nJari-jari yang anda masukkan adalah "<< r << "maka hasil luas lingkaran adalah "<< r * r * phi;
    break;

  case 2:
    cout<<"Masukkan jari-jari : ";
    cin>>r;
    cout<<"\nJari-jari yang anda masukkan adalah "<<r<< "maka hasil luas lingkaran adalah " <<  2 * phi * r ;
    break;

  default:
    cout<<"Terimakasih telah mengunjungi program ini :)";
    break;
  }
  return 0;
}