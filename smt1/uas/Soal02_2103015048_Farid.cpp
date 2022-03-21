#include <iostream>
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

void Sort(int data[], int n)
{
  int temp, prev;
  for (int i = 0; i < n - 1; i++)
  {
    prev = i;
    for (int j = i + 1; j < n; j++)
    {
      if (data[j] < data[prev])
      {
        prev = j;
      }
    }
    temp = data[i];
    data[i] = data[prev];
    data[prev] = temp;
  }
}

void showArray(int data[])
{
  for (int i = 0; i < 10; i++)
  {
    cout << data[i] << "  ";
  }
}
int main()
{
  int array[10];

  cout << "Masukkan nilai pada elemen array:\n";
  for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
  {
    printf("A[%d]= ", i);
    array[i] = inputInt();
  }

  cout << "Data Sebelum diurutkan : \n";
  showArray(array);
  Sort(array, sizeof(array)/sizeof(array[0]));

  cout << "\n\nData setelah diurutkan : \n";
  showArray(array);

  return 0;
}