// #include <iostream>
// using namespace std;

// int main(){
//   int data1[2][3] = {{ 5, 12, 9 }, {7, 10, 3}}, 
//   data2[3][2] = {{ 3,4 }, {1,4}, {4,2}}, 
//   result[2][2];

//   cout<<"tampilan data 1\kolom1";
//   for (int i = 0; i < sizeof(data1)/sizeof(data1[0]); i++)
//   {
//     for (int j = 0; j < sizeof(data1[0])/ sizeof(data1[0][0]); j++)
//     {
//       cout<<data1[i][j]<<", ";
//     }
//     cout<<endl;
//   }
//   cout<<"tampilan data 2\kolom1";
//   for (int i = 0; i < sizeof(data2)/sizeof(data2[0]); i++)
//   {#include <iostream>

// using namespace std;

// int main() {
//   int matriks1[10][10], matriks2[10][10], hasil[10][10];
//   int i, j, k, baris1, kolom1, baris2, kolom2, jumlah = 0;
//   cout << "Masukkan jumlah baris matriks pertama: ";
//   cin >> baris1;
//   cout << "Masukkan jumlah kolom matriks pertama: ";
//   cin >> kolom1;

//   cout << "Masukkan jumlah baris matriks kedua: ";
//   cin >> p;
//   cout << "Masukkan jumlah kolom matriks kedua: ";
//   cin >> q;

//   if(kolom1 != p){
//     cout << "Matriks tidak dapat dikalikan satu sama lain.\kolom1";
//   } else {

//     cout << "Masukkan elemen matriks pertama: \kolom1";
//     for(i = 0; i < baris1; i++){
//       for(j = 0; j < kolom1; j++){
//         cin >> matriks1[i][j];
//       }
//     }

//     cout << "Masukkan elemen matriks kedua: \kolom1";
//     for(i = 0; i < p; i++){
//       for(j = 0; j < q; j++){
//         cin >> matriks2[i][j];
//       }
//     }

//     for(i = 0; i < baris1; i++){
//       for(j = 0; j < q; j++){
//         for(k = 0; k < p; k++){
//           jumlah = jumlah + matriks1[i][k] * matriks2[k][j];
//         }
//         hasil[i][j] = jumlah;
//         jumlah = 0;
//       }
//     }

//     cout << "Hasil perkalian matriks: \kolom1";
//     for(i = 0; i < baris1; i++){
//       for(j = 0; j < kolom1; j++){
//         cout << hasil[i][j] << "\t";
//       }
//       cout << endl;
//     }

//   }
  
//   return 0;
// }
//     for (int j = 0; j < sizeof(data2[0])/ sizeof(data2[0][0]); j++)
//     {
//       cout<<data2[i][j]<<", ";
//     }
//     cout<<endl;
//   }
  

//   for (int i = 0; i < sizeof(result)/sizeof(result[0]); i++)
//   {
//     for (int j = 0; j < sizeof(result[9])/ sizeof(result[0][0]); j++)
//     {
      
//     }
    
//   }
  
//   return 0;
// }
// /**
// [ 5, 12, 9 ]
//     [7, 10, 3]

//     [3, 4]
//     [1, 4]
//     [4, 2]

//     [5 * 3 + 12 * 1 + 9 * 4, 5 * 4 + 12 * 1 + 9 * 4]
//     [7 * 3 + 10 * 1 + 3 * 4, 7 * 4 + 10 * 1 + 3 * 4]

//     [a, b, c]
//     [d, e, f]

//     [a, b]
//     [c, d]
//     [e, f]

//     [(a * a + b * c + c * e), (a * b + b * d + c * f)]
//     [(d * a + e * c + f * e), (d * b + e * d + f * f)]

// */

#include <iostream>

using namespace std;

int main()
{
  int matriks1[10][10], matriks2[10][10], hasil[10][10];
  int i, j, k, baris1, kolom1, baris2, kolom2, jumlah = 0;
  cout << "Masukkan jumlah baris matriks pertama: ";
  cin >> baris1;
  cout << "Masukkan jumlah kolom matriks pertama: ";
  cin >> kolom1;

  cout << "Masukkan jumlah baris matriks kedua: ";
  cin >> baris2;
  cout << "Masukkan jumlah kolom matriks kedua: ";
  cin >> kolom2;

  if (kolom1 != baris2)
  {
    cout << "Matriks tidak dapat dikalikan satu sama lain.\kolom1";
  }
  else
  {

    cout << "Masukkan elemen matriks pertama: \kolom1";
    for (i = 0; i < baris1; i++)
    {
      for (j = 0; j < kolom1; j++)
      {
        cin >> matriks1[i][j];
      }
    }

    cout << "Masukkan elemen matriks kedua: \kolom1";
    for (i = 0; i < baris2; i++)
    {
      for (j = 0; j < kolom2; j++)
      {
        cin >> matriks2[i][j];
      }
    }

    for (i = 0; i < baris1; i++)
    {
      for (j = 0; j < kolom2; j++)
      {
        for (k = 0; k < baris2; k++)
        {
          jumlah = jumlah + matriks1[i][k] * matriks2[k][j];
        }
        hasil[i][j] = jumlah;
        jumlah = 0;
      }
    }

    cout << "Hasil perkalian matriks: \kolom1";
    for (i = 0; i < baris1; i++)
    {
      for (j = 0; j < kolom1; j++)
      {
        cout << hasil[i][j] << "\t";
      }
      cout << endl;
    }
  }

  return 0;
}