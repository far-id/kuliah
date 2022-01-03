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

void Sort(int data[])
{
  int temp, j;
  for (int i = 9; i >= 0; i--)
  {
    temp = data[i];
    j = i + 1;
    while (temp < data[j] && j <= 9)
    {
      data[j - 1] = data[j];
      j++;
    }
    data[j - 1] = temp;
  }
}

void showArray(int data[]){
  for (int i = 0; i < 6; i++)
  {
    cout << data[i] << " | ";
  }
}
int main()
{
  int data1[6], j, k, i, temp, iBiggest, iLast = 5;
  int data2[6] = {0, 12, 100, 5, 70, 3};

  for (int i = 0; i < sizeof(data1) / sizeof(data1[0]); i++)
  {
    cout<<"Nilai element ke-"<<i<<" : ";
    data1[i] = inputInt();
  }

  cout<<"\n Data1 sebelum diurutkan\n | ";
  showArray(data1);
  
  
  for (i = 0; i < 6; i++)
  {
    iBiggest = 0;
    for (j = 1; j <= iLast; j++){
      if (data1[j] > data1[iBiggest]){
        iBiggest = j;
      }
    }
    temp = data1[iLast];
    data1[iLast] = data1[iBiggest];
    data1[iBiggest] = temp;
    iLast--;
  }
  
  cout << "\n Data1 setelah diurutkan ascending\n | ";
  showArray(data1);

  cout<<"\n\n Data2\n | ";
  showArray(data2);

  Sort(data2);

  cout<<"\n Data2 setelah diurutkan descending\n | ";
  showArray(data2);
}