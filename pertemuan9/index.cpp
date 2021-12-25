#include <iostream>
using namespace std;

void sumArray(int array1[50], int array2[50]){
  int sum[50];
  for (int i = 0; i < sizeof(sum) / sizeof(sum[0]); i++)
  {
    sum[i] = array1[i] + array2[i];
  }

  cout << "Hasil penjumlahan [";
  for (int i = 0; i < sizeof(sum) / sizeof(sum[0]); i++)
  {
    cout << sum[i] << ", ";
  }
  cout << "]\n";
}

void multiplyingArray(int array1[50], int array2[50])
{
  int mult[50];
  for (int i = 0; i < sizeof(mult) / sizeof(mult[0]); i++)
  {
    mult[i] = array1[i] * array2[i];
  }

  cout << "Hasil perkalian [";
  for (int i = 0; i < sizeof(mult) / sizeof(mult[0]); i++)
  {
    cout << mult[i] << ", ";
  }
  cout << "]\n";
}

int main(){
  int array1[50] = {0}, array2[50] = {0}, max, location = 0, sum[50], mult[50], search, menu, pass = 0;
  bool con = true, found = false;

  cout<<"\t\tMENU\n";
  cout << "1. Memasukan data ke dalam array 1\n";
  cout<<"2. Memasukan data ke dalam array 2\n";
  cout<<"3. Menampilkan data Array 1 dan array 2\n";
  cout<<"4. MencariNilai Maksimum Array 1\n";
  cout<<"5. Mencari Nilai Tertentu dalam Array 2\n";
  cout<<"6. Menghitung penjumlahan array1 dan array2\n";
  cout<<"7. Menghitungperkalian array1 dan array2\n";
  cout<<"8. Keluar\n\n";
  cout<<"Pilih menu yang ingin dijalankann (1..8): ";
  cin>>menu;

  while (con)
  {
    cout<<"Menjalankan menu "<<menu<<"\n\n";
    switch (menu)
    {
    case 1:
      cout << "array 1 akan berisi data integer sebanyak " << sizeof(array1) / sizeof(array1[0]) << " elemen\n";
      cout << "harap masukkan data sebanyak " << sizeof(array1) / sizeof(array1[0]) << "elemen\n";
      for (int i = 0; i < sizeof(array1) / sizeof(array1[0]); i++)
      {
        cout << "elemen ke-" << i+1 << " : ";
        cin >> array1[i];
      }
      if (pass!= 0)
      {
        menu=pass;
      }
      
      break;

    case 2:
      cout << "array 2 akan berisi data integer sebanyak " << sizeof(array2) / sizeof(array2[0]) << "elemen\n";
      cout << "harap masukkan data sebanyak " << sizeof(array2) / sizeof(array2[0]) << "elemen\n";
      for (int i = 0; i < sizeof(array2) / sizeof(array2[0]); i++)
      {
        cout << "elemen ke-" << i+1 << " : ";
        cin >> array2[i];
      }

      if (pass != 0)
      {
        menu = pass;
      }
      break;

    case 3:
      if (array1[0] == 0)
      {
        cout << "array 1 masih kosong, harap isi terlebih dahulu\n";
        pass = 3;
        menu = 1;
        break;
      }
      if (array2[0] == 0)
      {
        cout << "array 2 masih kosong, harap isi terlebih dahulu\n";
        pass = 3;
        menu = 2;
        break;
      }
      
      cout<<"array1[";
      for (int i = 0; i < sizeof(array1) / sizeof(array1[0]); i++)
      {
        cout<<"\""<<array1[i]<<"\", ";
      }
      cout<<"]\n";
      cout<<"array2[";
      for (int i = 0; i < sizeof(array2) / sizeof(array2[0]); i++)
      {
        cout<<"\""<<array2[i]<<"\", ";
      }
      cout<<"]\n";
      pass = 0;
      break;

    case 4:
      if (array1[0] == 0)
      {
        cout<<"array 1 masih kosong, harap isi terlebih dahulu\n";
        menu = 1;
        pass = 4;
        break;
      }
      
      max = array1[0];
      for (int i = 0; i < sizeof(array1) / sizeof(array1[0]); i++)
      {
        if (array1[i]>max)
        {
          max = array1[i];
          location = i;
        }
      }
      printf("Nilai maksimal dari array 1 adalah %d yang berada di elemen ke-%d atau array1[%d]", max, location+1, location);
      pass=0;
      break;

    case 5:
      if (array2[0] == 0)
      {
        cout << "array 2 masih kosong, harap isi terlebih dahulu\n";
        pass = 5;
        menu = 2;
        break;
      }
      cout<<"Angka yang anda cari : ";
      cin>>search;
      for (int i = 0; i < sizeof(array2) / sizeof(array2[0]); i++)
      {
        if (array2[i] == search)
        {
          found = true;
          cout<<search<<" ditemukan pada elemen ke-"<<i+1<< " atau array2["<<i<<"]\n";
          break;
        }
      }
      if (!found)
      {
        cout<<search<<" tidak ditemukan\n";
      }

      found = false;
      pass=0;
      break;

    case 6: 
      if (array1[0] == 0)
      {
        cout << "array 1 masih kosong, harap isi terlebih dahulu\n";
        pass = 6;
        menu = 1;
        break;
      }
      if (array2[0] == 0)
      {
        cout << "array 2 masih kosong, harap isi terlebih dahulu\n";
        pass = 6;
        menu = 2;
        break;
      }
      sumArray(array1, array2);
      pass= 0;
      break;

    case 7: 
      if (array1[0] == 0)
      {
        cout << "array 1 masih kosong, harap isi terlebih dahulu\n";
        pass = 7;
        menu = 1;
        break;
      }
      if (array2[0] == 0)
      {
        cout << "array 2 masih kosong, harap isi terlebih dahulu\n";
        pass = 7;
        menu = 2;
        break;
      }
      multiplyingArray(array1, array2);
      pass= 0;
      break;
    
    case 8:
      cout<<"Anda keluar dari pemilihan menu\n";
      con = false;
      pass = 1;
      break;
    default:
      break;
    }

    if (pass == 0)
    {
      cout << "\nPilih menu lainnya (1..8):";
      cin >> menu;
    }
    
  }
  cout<<"Terima Kasih telah menjalankan program ini";

  return 0;
}