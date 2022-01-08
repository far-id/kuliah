#include <iostream>
#include <conio.h>
#include <iomanip>
#include <limits>

using namespace std;

int inputInt()
{
  int x = 0;
  while (!(cin >> x))
  {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Input bukan integer. coba lagi : ";
  }
  return x;
}
void binarysearch(int data[], int end, int cari)
{
  int begin, center;
  begin = 0;
  bool get = false;
  while (get == false && begin <= end)
  {
    center = (begin + end) / 2;
    if (data[center] == cari)
    {
      get = true;
      break;
    }
    else if (data[center] < cari)
      begin = center + 1;
    else
      end = center - 1;
  }
  if (get == true)
    cout << "\nData ditemukan pada index ke-" << center << endl;
  else
    cout << "\nData tidak ditemukan\n";
}

void Sort(int data[], int size)
{
  int temp;
  for (int i = 0; i <= size; i++)
  {
    temp = data[i];
    int j = i-1;
    while (data[j] > temp && j>=0)
    {
      data[j+1] = data[j];
      j--;
    }
    data[j+1] = temp;
  }
  
}

void showArray(int data[], int size)
{
  for (int i = 0; i <= size; i++)
  {
    cout << data[i] << ", ";
  }
}

void insertValueToArray(int size){
  size -= 1;
  int data[size], search;

  cout<<"Silagkan masukkan angka yang anda inginkan\n";
  for (int i = 0; i <= size; i++)
  {
    cout<<"Data ke-"<<i+1<<" : ";
    data[i] = inputInt();
  }
  
  cout<<"\ndata sebelum diurutkan\n";
  showArray(data, size);

  Sort(data, size);
  cout<<"\ndata setelah diurutkan\n";
  showArray(data, size);

  cout<<"\n\n Data yang ingin anda cari : ";
  cin>>search;

  binarysearch(data, size, search);
}
int main()
{
  int length;

  cout<<"Berapa jumlah data yang ingin anda masukkan? : ";
  cin>>length;

  insertValueToArray(length);
  
}
