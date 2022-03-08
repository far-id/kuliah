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

int main(){
  int matrixA[3][2],matrixB[3][2], matrixR[3][2];

  cout<<"inputkan angka untuk mengisi Matrix A!\n";
  for (int i = 0; i < sizeof(matrixA) / sizeof(matrixA[0]); i++)
  {
    for (int j = 0; j < sizeof(matrixA[0]) / sizeof(matrixA[0][0]); j++)
    {
      printf("Baris %d kolom %d : ", i+1, j+1);
      matrixA[i][j] = inputInt();
    }
  }
  cout<<"inputkan angka untuk mengisi Matrix B\n";
  for (int i = 0; i < sizeof(matrixB) / sizeof(matrixB[0]); i++)
  {
    for (int j = 0; j < sizeof(matrixB[0]) / sizeof(matrixB[0][0]); j++)
    {
      printf("Baris %d kolom %d : ", i+1, j+1);
      matrixB[i][j] = inputInt();
    }
  }

  cout<<"Isi matrix A [\n";
  for (int i = 0; i < sizeof(matrixA) / sizeof(matrixA[0]); i++)
  {
    cout<<"\t";
    for (int j = 0; j < sizeof(matrixA[0]) / sizeof(matrixA[0][0]); j++)
    {
      cout<< matrixA[i][j] << ", ";
    }
    cout << endl;
  }
  cout<<"]\n";

  cout << "Isi matrix B [\n";
  for (int i = 0; i < sizeof(matrixB) / sizeof(matrixB[0]); i++)
  {
    cout << "\t";
    for (int j = 0; j < sizeof(matrixB[0]) / sizeof(matrixB[0][0]); j++)
    {
      cout << matrixB[i][j]<<", ";
    }
    cout << endl;
  }
  cout << "]\n";

  cout << "Hasil penjumlahan matrix A dan matrix B[\n";
  for (int i = 0; i < sizeof(matrixR) / sizeof(matrixR[0]); i++)
  {
    cout << "\t";
    for (int j = 0; j < sizeof(matrixR[0]) / sizeof(matrixR[0][0]); j++)
    {
      matrixR[i][j] = matrixA[i][j] + matrixB[i][j];
      cout<<matrixR[i][j]<<", ";
    }
    cout<<endl;
  }
  cout << "]\n";

  return 0;
}