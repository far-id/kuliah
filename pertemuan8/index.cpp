#include <iostream>
#include <algorithm>

using namespace std;

int menjumlahkanBilanganGenap(int n){
  int count = 0, i;
  for (i = 0; i < n * 2; i++)
  {
    if (i % 2 == 0)
    {
      count+=i;
    }
  }
  return count;
}

int menentukanBilanganFibonacci(int x)
{
  if (x == 0)
    return 0;

  if (x == 1)
    return 1;
  return menentukanBilanganFibonacci(x - 1) + menentukanBilanganFibonacci(x - 2);
}
bool ToF(char huruf){
  if (huruf == 'a')return true;
  return false;
}

int main()
{
  int question, n, i;
  bool condition = true;
  string repeat;
  char masuk;

  cout << "Tugas 4 : Praktikum Algoritma dan Dasar Pemrograman\n";
  cout << "Nama\t: Farid Rizky Wijaya\n";
  cout << "NIM\t: 2103015048\n";
  cout << "Kelas\t: 1B\n\n";

  cout << "\t\tDaftar Soal\n";
  cout << "1. Buatlah program computer dengan bahasa C++ untuk menulis prosedur untuk menghitung jumlah N buah bilangan genap pertama(bilangan genap dimulai dari 0) .Prosedur menerima(parameter) masukan N dan memberikan(parameter) luaran jumlah N buah bilangan genap pertama tersebut !\n ";
  cout<< "2. Buatlah program computer dengan bahasa C++ untuk membuat urutan bilangan Fibonacci mulai dari 3 sampai dengan 15, dengan metode rekursif !\n ";
  cout<< "3. Buatlah program computer dengan bahasa C++ dengan menggunakan fungsi yang akan memberikan nilai true jika karakter yang diterimanya adalah huruf ‘a’ dan false jika tidak.\n ";

  while (condition)
  {
    cout << "\nPilih nomor soal yang akan dijalankan (1,2,3)  : ";
    cin >> question;
    cout << "\nMenjalankan soal nomor " << question << endl<< endl;

    switch (question)
    {
    case 1:
      // 1
      cout<<"Berapa banyak bilangan genap pertama yang ingin anda jumlahkan? ";
      cin >> n;
      cout << "Menjumlahkan "<<n<<" bilangan genap pertama\nHasilnya : " << menjumlahkanBilanganGenap(n) << endl;
      break;

    case 2:
      //  2
      for (int i = 3; i <= 15; i++)
      {
        cout << "fibonacci ke-" << i << " : " << menentukanBilanganFibonacci(i) << endl;
      }
      break;

    case 3:
      //  3
      cin >> masuk;
      cout << ToF(masuk) << endl;
      break;
    default:
      cout << "Nomor soal yang anda masukkan tidak ada\n";
      break;
    }
    cout << "Cek soal lainnya? (y/n) :";
    cin >> repeat;
    transform(repeat.begin(), repeat.end(), repeat.begin(), ::tolower);
    repeat == "ya" || repeat == "iya" || repeat == "y" || repeat == "ulang" || repeat == "yes" ? condition = true : condition = false;
  }
  cout << "\nTerimakasih";
}