#include <iostream>
using namespace std;

int main(){
  int a[3][4] = {
    {2,4,6,8},
    {10,12,14,16},
    {18,20,22,24}
  };
  //18,12,6

  int j = 0;
  for (int i = 2; i >= 0; i--)
  {
    cout<<a[i][j];
    j++;
  }
  return 0;
}