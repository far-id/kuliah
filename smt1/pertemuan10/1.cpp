#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <string.h>
using namespace std;

void setTable();

string nation[6][2] = {{"Negara", "Ibukota"}}, element;
int main()
{
  for (int i = 1; i < sizeof(nation) / sizeof(nation[0]); i++)
  {
    for (int j = 0; j < sizeof(nation[0]) / sizeof(nation[0][0]); j++)
    {
      if (j == 0)
      {
        element = "Negara";
      }
      else
      {
        element = "Ibukota";
      }

      cout << "Masukkan nama " << element << "\t: ";
      getline(cin, nation[i][j]);
    }
  }

  setTable();
  return 0;
}
void setTable()
{
  char row = 205, col = 179, cornerL = 198, cornerR = 181, midd = 197, cornerLU = 218;
  char cornerRU = 188, middU = 193, cornerRR = 191, cornerLL = 218, middleSingle = 194; // ascii codes

  for (int f = 0; f < 17; f++)
  {
    if (f == 0)
    {
      cout << cornerLL;
    }
    else if (f == 16)
    {
      cout << cornerRR;
    }
    else if (f == 8)
    {
      cout << middleSingle;
    }
    else
    {
      cout << row;
    }
  }
  for (int i = 0; i < sizeof(nation) / sizeof(nation[0]); i++)
  {

    cout << "\n";
    cout << col;
    for (int j = 0; j < sizeof(nation[0]) / sizeof(nation[0][0]); j++)
    {
      cout << nation[i][j] << " ";
      cout << col;
    }
    cout << "\n";
    for (int rd = 0; rd < 17; rd++)
    {
      switch (rd)
      {
      case 0:
        cout << cornerL;
        continue;
      case 16:
        cout << cornerR;
        continue;
      case 8:
        cout << midd;
        continue;
      default:
        cout << row;
      }
    }
  }
}