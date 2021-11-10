#include <iostream>
using namespace std;

int main(){
  int nim, umur, a;
  cout<<"\t===Pertukaran 2 nilai variabel===\n";

  cout<<"NIM : ";
  cin>>nim;
  cout<<"umur : ";
  cin>>umur;

  cout<<endl;
  printf("Sebelum ditukar NIM anda %d, dan umur anda %d", nim, umur);

  //pertukaran
  a = nim;
  nim = umur;
  umur = a;

  cout<<endl;
  printf("Sebelum setelah NIM anda %d, dan umur anda %d", nim, umur);

  return 0;
}