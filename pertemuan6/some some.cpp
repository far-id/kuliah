#include <iostream>

using namespace std;


int main () {
	
	int rinso;
	
	cout << " Permasalahan Kasus / Permasalahan Merk Diterjen " << endl;
	
	cout << "Berapa kilogram Rinso yang ingin anda beli ? \n 1. 1 kg \n 2. 5 kg " <<endl;
	cout << " Nomor : " ; cin >> (rinso);
	
	switch (rinso) {
		case 1:
			cout << " Anda membeli Rinso sebanyak 1 kg, Maka harganya Rp. 15.000 ";
			break;
		case 2:
			cout << " Anda membeli Rinso sebanyak 5 kg, Maka harganya Rp. 50.000 ";
			break;
    } 
	int daia;
	
	
	 cout << " Permasalahan Kasus / Permasalahan Merk Diterjen " << endl;
	 
	 cout << " Berapa Kilogram Daia yang ingin anda beli ? \n 1. 1kg \n 2. 5kg " <<endl;
	 cout << " Nomor : " ; cin >> (daia);
	 
	 switch (daia) {
	 
	  case 1:		
	 	cout << " Anda membeli Daia Sebanyak 1kg, Maka harganya Rp. 10.000 ";
	 	break;
	  case 2:
		cout << " Anda membeli Daia sebanyak 5kg, Maka harganya Rp. 30.000 ";
		break;
}
       return 0; 
 }