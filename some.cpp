#include <iostream>

using namespace std;


int main (){
	
	
int a,b;

a = 03;
b = 06;

cout <<(" NILAI A DAN B SEBELUM PERTUKARAN") <<endl;
cout <<" NILAI A SEBELUM ADALAH :" << a << endl;
cout <<" NILAI B SEBELUM ADALAH :" << b << endl;

b = a;
a = b;

cout <<(" HASIL PERTUKARAN") <<endl;
cout << "NILAI A SEKARANG ADALAH :" << a << endl;
cout << "NILAI B SEKARANG ADALAH :" << b << endl;

return 0;
}