#include <iostream>
#include <algorithm>
using namespace std;

int main(){

  /*
  \ Program tugas 3 P.Algo & Pemrograman Dasar
  \ Nama  : Farid Rizky Wijaya
  \ NIM   : 2103015048
  \ Kelas : 1B
  */
  int question, loop, num, i;
  float sum = 0;
  bool condition = true;
  string repeat;

  cout<<"Tugas 3 : Praktikum Algoritma dan Dasar Pemrograman\n";
  cout<<"Nama\t: Farid Rizky Wijaya\n";
  cout<<"NIM\t: 2103015048\n";
  cout<<"Kelas\t: 1B\n\n";

  cout<<"\t\tDaftar Soal\n";
  cout<<"1. Menentukan jumlah dan rata-rata bilangan bulat dari perulangan inputan dengna FOR\n";
  cout<<"2. Membentuk segitiga seperti pada contoh dengan NESTED FOR\n";
  cout<<"3. Menambilkan deret bilangan ganjil dari 3 sampai 23 dengan DO_WHILE\n";
  cout<<"4. Menampilkan bilangan genap dari 50 sampai 78 dengan WHILE-DO\n";


  while(condition){
    cout<<"\nPilih nomor soal yang akan dijalankan (1,2,3,4)  : ";
    cin>>question;
    cout<<"\nMenjalankan soal nomor "<<question<<endl<<endl;
    
    switch (question)
    {
      case 1:
        //1
        cout << "Berapa kali anda akan menjumlahkan?\n";
        cin >> loop;

        for (i = 0; i < loop; i++)
        {
          cout << "angka ke-" << i + 1 << " :";
          cin >> num;
          sum += num;
        }
        cout << "total penjumlahan dari angka yang anda masukkan adalah :" << sum << endl;
        cout << "rata-rata dari angka yang anda inputkan adalah " << sum / loop << endl;
        break;

      case 2:
        //  2
        for (i = 8; i > 0; i--)
        {
          for (int j = 1; j <= i; j++)
          {
            cout << "*";
          }
          cout << endl;
        }
        break;

      case 3:
        //  3
        i = 3;
        do
        {
          if (i % 2 != 0)
          {
            cout << i << endl;
          }
          i++;
        } while (i <= 23);
        break;

      case 4:
        //  4
        i = 50;
        while (i <= 78)
        {
          if (i % 2 == 0)
          {
            cout << i << endl;
          }
          i++;
        }
        break;
      default:
        cout << "Nomor soal yang anda masukkan tidak ada\n";
        break;
    }
    cout << "Cek soal lainnya? (y/n) :";
    cin >> repeat;
    transform(repeat.begin(), repeat.end(), repeat.begin(), ::tolower);
    repeat == "ya" || repeat == "iya" || repeat == "y" || repeat == "ulang" || repeat == "yes"? condition = true : condition = false;
  }
  cout<<"\nTerimakasih";

  return 0;
}