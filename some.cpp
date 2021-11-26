#include <iostream>
using namespace std;


int main(){
  for(int i = 8; i>0; i--){
    for(int k= 1; k<=i; k++){
      cout<<"*";
    }
    cout<<endl;
  }
  return 0;
}