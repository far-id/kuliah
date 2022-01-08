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
  
  cout<<"\ncari : ";
  getline(cin, search);
  cout<<endl;

  cout<<"Daftar Mahasiswa\n";
  for (int i = 0; i <= size; i++)
  {
    cout<<i+1<<". "<<mhs[i]<<".\n";
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

  cout<<endl;

  if (get)
  {
    cout<<search<<" ditemukan pada urutan ke-"<<index+1;
  }else
  {
    cout<<search<<" tidak ada dalam urutan";
  }
  return 0;
}