#include <iostream>
using namespace std;

int main(){
  string mhs[10], search;
  int index, 
  size = (sizeof(mhs) / sizeof(string)) -1;
  bool get = false;

  for (int i = 0; i <= size; i++)
  {
    cout<<"Masukkan nama Mahasiswa ke-"<<i+1<<" : ";
    getline (cin, mhs[i]);
  }
  
  cout<<"cari : ";
  getline(cin, search);

  cout<<"Daftar Mahasiswa\n";
  for (int i = 0; i <= size; i++)
  {
    cout<<i<<". "<<mhs[i]<<".\n";
  }

  for (int i = size; i >= 0; i--)
  {
    if (mhs[i] == search)
    {
      get = true;
      index = i;
      break;
    }
  }
  if (get)
  {
    cout<<search<<" ditemukan pada urutan ke-"<<index+1;
  }else
  {
    cout<<search<<" tidak ada dalam urutan";
  }
  return 0;
}