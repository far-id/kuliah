#include <iostream>
using namespace std;

int faktorial(int a){
  int hasil = 1;
  for (int i = a; i > 1; i--)
  {
    hasil *=a;
    a--;
  }
  return hasil;
  
}

int faktorialRekursif(int a){
  int hasil = a;
  if (a <=1)
  {
    return 1;
  }
  hasil *= faktorialRekursif(a-1);
  return hasil;
}

int faktorialTailRekursif(int a, int hasil = 1){
  
  if (a <= 1)
  {
    return hasil;
  }

  return faktorialTailRekursif(a - 1, hasil * a);
}

int main(){
  cout << faktorialRekursif(12);
  return 0;
}


