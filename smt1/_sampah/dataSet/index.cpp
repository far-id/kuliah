#include <iostream>
#include <iterator>
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
  if (sizeof(larik) / sizeof(larik[0]) == panjang)
  {
    return false;
  }
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
    if (value == larik[i])
    {
      larik[i] = "";
      for (int j = i; j < panjang; j++)
      {
      
        larik[j] = larik[j+1];
      }
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
  add("arid");
  add("iqbal");
  add("far");
  add("id");
  add("faz");
  add("ya");
  add("fazya");
  hapus("rizky");
  outlarik();
  
  // string newlarik[20];
  // copy(begin(larik), end(larik), begin(newlarik));
  
  return 0;
}