#include <iostream>
using namespace std;

void inputMatrix(int matrix[4][4], string con)
{
  int num;
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      if (con == "matrix1")
      {
        printf("inputkan angka untuk matrix 1 [%d][%d]", i, j);
        cin >> num;
        matrix[i][j] = num;
      }
      else if (con == "matrix2")
      {
        printf("inputkan angka untuk matrix 2 [%d][%d]", i, j);
        cin >> num;
        matrix[i][j] = num;
      }
    }
  }
}

void mult(int matrix1[4][4], int matrix2[4][4])
{
  int mult[4][4];
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      mult[i][j] = matrix1[i][j] * matrix2[i][j];
    }
    cout << endl;
  }

  cout << "mult[\n";
  for (int i = 0; i < 4; i++)
  {
    cout << "\t[";
    for (int j = 0; j < 4; j++)
    {
      cout << mult[i][j] << ", ";
    }
    cout << "]\n";
  }
  cout << "]\n";
}

int main()
{
  int matrix1[4][4], matrix2[4][4];

  inputMatrix(matrix1, "matrix1");
  inputMatrix(matrix2, "matrix2");

  mult(matrix1, matrix2);

  return 0;
}

//pseudo
/**
var matriks1 : array[1...4, 1...4], matriks2 : array[1...4, 1...4] of integer;
var i, j : integer;

Procedure inputMatriks(matriks
                       : array[1..4, 1...4] of integer, con
                       : string){menginputkan data kedalam matriks} {k.awal : matriks berelemen 4x4 kosong} {k.akhir : matriks berelemen 4x4 sudah memiliki data masing - masing elemen}

Deklarasi : num : integer;

  Algoritma :
    for i:= to 4 Do
      Begin
      for j:=1 to 4 Do
        Begin
        if con == "matriks1" then
          writeln("inputkan angka untuk matriks 1 [", i, "][", j, "]");
  read(num);
  matriks[i, j] = num;
  else if con == "matriks2" then
                     writeln("inputkan angka untuk matriks 2 [", i, "][", j, "]");
  read(num);
  matriks[i, j] = num;
  End;
  End

      Procedure perkalianMatriks(matriks1
                                 : array[1...4, 1...4], matriks2
                                 : array[1...4, 1...4] of integer){melakukan perkalian pada 2 matriks yang diterima parameter} {k.awal : 2 matriks dengan data masing masing} {k.angkhir : menampilkan matriks hasil perkalian}

  Deklarasi : kali : array[1...4, 1...4] of integer;

  Algoritma :
    for i:= to 4 Do
      Begin
      for j:=1 to 4 Do
        Begin
        { melakukan perkalian tiap elemen dari 2 matriks ke dalam matriks baru }
        kali[i,j] = matriks1[i,j] * matriks2[i,j];
  End;
  End;

    { menampilkan hasil perkalian 2 matriks }
    Begin
      println("Hasil kali [")
      for i:= to 4 Do
        Begin
        print(\t, "[");
        for
          j : = 1 to 4 Do
                  Begin
                      print(kali[i, j], ", ")
                          End;
        println("]");
        End;
        println("]");
        End;
*/