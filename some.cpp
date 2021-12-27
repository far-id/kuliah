#include <iostream>
#include <string>
using namespace std;
int main()
{
  string negara[5][2] = {{"Indonesia", "Jakarta"}, {"Inggris", "London"}, {"Australia", "Wina"}, {"Francis", "Paris"}, {"Jepang", "Tokyo"}};
  for (int i = 0; i < sizeof(negara) / sizeof(negara[0]); i++)
  {
    for (int j = 0; j < sizeof(negara[0]) / sizeof(negara[0][0]); j++)
    {
      cout << negara[i][j];
    }
  }
}