#include <iostream>
using namespace std;

int main(){
	int angka[] = {1,2,3,4,5};
	angka[5] = 6;
	angka[6] = 7;
	angka[7] = 8;
	angka[8] = 9;
	angka[9] = 10;
	for (int i = 0; i < 10; i++)
	{
		cout<<angka[i]<<endl;
	}
	
	return 0;
}