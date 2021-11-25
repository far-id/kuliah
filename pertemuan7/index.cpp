#include <iostream>
using namespace std;

int main(){

  /*
  \ Program tugas 4 P.Algo 7 Pemrograman 
  \ Nama  : Farid Rizky Wijaya
  \ NIM   : 2103015048
  \ Kelas : 1B
  */

  //1
  int loop, i, num;
  float sum = 0, avr;

  cout<<"Berapa kali anda akan menjumlahkan?\n";
  cin>>loop;

  for(i = 0; i<loop; i++){
    cout<<"angka ke-"<<i+1<<" :";
    cin>>num;
    sum += num;
  }
  cout<<"total penjumlahan dari angka yang anda masukkan adalah :"<<sum<<endl;
  cout<<"rata-rata dari angka yang anda inputkan adalah" << sum/loop << endl;

  //  2
  for(i = 8; i>0; i--){
    for (int j = 1; j<=i; j++){
      cout<<"*";
    }
    cout<<endl;
  }

  //  3
  i = 3;
  do
  {
    if(i%2 != 0){
      cout<<i<<endl;
    }
    i++;
  } while (i<=23);
  
  //  4
  i = 50;
  while(i<=78){
    if(i%2 == 0){
      cout<<i<<endl;
    }
    i++;
  }

  return 0;
}