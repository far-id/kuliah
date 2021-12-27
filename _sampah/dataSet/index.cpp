#include <iostream>
using namespace std;

string larik[10];
int panjang = 0;

bool already(string value)
{
  for (int i = 0; i < sizeof(larik) / sizeof(larik[0]); i++)
  {
    if (value == larik[i])
    {
      return true;
    }
    
  }
  return false;
}

bool add(string value){
  if (already(value))
  {
    return false;
  }

  larik[panjang] = value;
  panjang++;
  return true;
}

void hapus(string value){
  for (int i = 0; i < panjang; i++)
  {
    if (value == larik[i]);
    {
      larik[i] = "";
      panjang--;
    }
  }
}


void outlarik(){
  cout<<"larik [";
  for (int i = 0; i < panjang; i++)
  {
    cout<<larik[i]<< ", ";
  }
  cout<<"]";
  
}





int main(){
  add("Farid");
  add("rizky");
  add("wijaya");
  add("Farid");
  hapus("some");
  outlarik();
  return 0;
}