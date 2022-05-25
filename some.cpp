#include <iostream>
using namespace std;


int main(){
  int a = 5;

  int b = 6;

  int c = 7;

  int *pa = &a;

  int *pb = &b;

  int **ppa = &pa;

  // int **pb = &pb;
  cout << "nilai ppa:" << *ppa << endl;
  return 0;
}