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

  void inputMatrix(int matrix[4][4], string con)
  {
    for (int i = 0; i < 4; i++)
    {
      for (int j = 0; j < 4; j++)
      {
        if (con == "matrix1")
        {
          printf("inputkan angka untuk matrix 1 [%d][%d] :  ", i, j);
          
          matrix[i][j] = inputInt();
        }
        else if (con == "matrix2")
        {
          printf("inputkan angka untuk matrix 2 [%d][%d] :  ", i, j);
          
          matrix[i][j] = inputInt();
        }
      }
    }
  }

  void sumSubt(int matrix1[4][4], int matrix2[4][4])
  {
    int sum[4][4], subt[4][4];
    for (int i = 0; i < 4; i++)
    {
      for (int j = 0; j < 4; j++)
      {
        sum[i][j] = matrix1[i][j] + matrix2[i][j];
      }
    }
    for (int i = 0; i < 4; i++)
    {
      for (int j = 0; j < 4; j++)
      {
        subt[i][j] = matrix1[i][j] - matrix2[i][j];
      }
    }

    cout << "Hasil Penjumlahan [\n";
    for (int i = 0; i < 4; i++)
    {
      cout << "\t[";
      for (int j = 0; j < 4; j++)
      {
        cout << sum[i][j] << ", ";
      }
      cout << "]\n";
    }
    cout << "]\n";

    cout << "Hasil Pengurangan[\n";
    for (int i = 0; i < 4; i++)
    {
      cout << "\t[";
      for (int j = 0; j < 4; j++)
      {
        cout << subt[i][j] << ", ";
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

    sumSubt(matrix1, matrix2);

    return 0;
  }