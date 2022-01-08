#include <iostream>
#include <conio.h>

using namespace std;
int main()
{
  int n, i;
  int data[10], x, tengah;
  cout << "Masukkan banyak data : ";
  cin >> n;
  for (i = 0; i < n; i++)
  { 
    cout << "Data ke-" << i + 1 << " : ";
    cin >> data[i];
  }
  for (int i = 0; i < n; i++)
  {
    cout<<data[i]<<", ";
  }
  
  cout << "Data yang dicari : ";
  cin >> x;
  int awal = 0, akhir = n - 1;
  do
  {
    tengah = (awal + akhir) / 2;
    if (x < data[tengah])
      akhir = tengah - 1;
    else
      awal = tengah + 1;
  } while ((akhir >= awal) && (data[tengah != x]));
  if (data[tengah] == x)
    cout << "Data " << x << " Pada Posisi " << tengah + 1;
  getch();
  return 0;
}