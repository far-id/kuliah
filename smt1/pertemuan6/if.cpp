#include <iostream>
using namespace std;

int main(){
  int merek, harga;

  cout << "\t === Pilih Merek ===\n";
  cout << "1. Rinsso \n2. Daia\n\n";

  cout<< "Silahkan Pilih merek (1,2)";
  cin>>merek;

  if(merek == 1){
    cout<<"\t === Pilih varian ===\n";
    cout<< "1:  5Kg\tRp.50.000\n";
    cout<< "2:  1Kg\tRP.15.000\n";

    cout<< "Silahkan Pilih varian (1,2)";
    cin>> harga;
    
    if(harga ==1){
      cout << "Anda membeli Rinso 5Kg dengan harga Rp.50.000";
    }else if(harga == 2){
      cout << "Anda membeli Rinso 1Kg dengan harga Rp.15.000";
    }else{
      cout << "Varian yang anda masukkan tidak tersedia";
    }
  }else if(merek == 2){
    cout<<"\t === Pilih varian ===\n";
    cout<< "1:  5Kg\tRp.30.000\n";
    cout<< "2:  1Kg\tRP.10.000\n";

    cout<< "Silahkan Pilih varian (1,2)";
    cin>> harga;
    
    if(harga ==1){
      cout << "Anda membeli Daia 5Kg dengan harga Rp.30.000";
    }else if(harga == 2){
      cout << "Anda membeli Daia 1Kg dengan harga Rp.10.000";
    }else{
      cout << "Varian yang anda masukkan tidak tersedia";
    }
  }else{
      cout << "Merek yang anda masukkan tidak tersedia";
  }
}