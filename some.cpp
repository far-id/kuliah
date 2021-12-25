#include <iostream>
#include <limits>
using namespace std;

int inputArray(int i){
  int x = 0;
  while (!(cin >> x))
  {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Invalid input.  array[" << i << "] : ";
  }
  return x;
}

int main()
{
  int array[3];
  for (int i = 0; i < 3; i++)
  {
    cout << "array["<<i<<"] :";
    
    array[i] = inputArray(i);
  }

  cout<<"array[";
  for (int i = 0; i < 3; i++)
  {
    cout<<array[i]<<", ";
  }
  cout<<"]";
  
}