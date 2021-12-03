#include <iostream>
using namespace std;

int nbuah(int n){
  int count = 0, i;
  for (i = 0; i < n * 2; i++)
  {
    if (i % 2 == 0)
    {
      count+=i;
    }
  }
  return count;
}

int fib(int x)
{
  if (x == 0)
    return 0;

  if (x == 1)
    return 1;
  return fib(x - 1) + fib(x - 2);
}

bool nomor3(char huruf){
  if (huruf == 'a')return true;
  return false;
}

int main()
{
  // 1
  for (int i = 3; i <= 15; i++)
  {
    cout<<"fibonancci ke-"<<i<<" : "<<fib(i)<<endl;
  }
  // 2
  char masuk;
  cin>>masuk;
  cout<<nomor3(masuk);
  // 3
  int  n;
  cin>>n;
  cout << nbuah(n);
}