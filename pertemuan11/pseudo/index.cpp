#include <iostream>

using namespace std;

void Sort(int data[]){
  // {5, 12, 4, 13, 2, 14, 21, 643, 74, 23};
  int temp, j;
  for (int i = 9; i >= 0; i--)
  {
    temp = data[i];
    j = i+1;
    while (temp < data[j] && j<=9)
    {
      data[j-1] = data[j];
      j++;
    }
    data[j-1] = temp;
    
  }
}
int main()
{
  // // deklarasi array dengan 6 elemen
  // int data[6] = {2,32,124,3,4,211212};
  // int j, k, i, temp;
  // int iBiggest, iLast = 5;
  // // Proses pengiLastriLasttan secara menaik (datascending)
  // for (i = 0; i < 6; i++)
  // {
  //   iBiggest = 0;
  //   for (j = 1; j <= iLast; j++){
  //     if (data[j] > data[iBiggest]){
  //       iBiggest = j;
  //     }
  //   }
  //   temp = data[iLast];
  //   data[iLast] = data[iBiggest];
  //   data[iBiggest] = temp;
  //   iLast--;
  // }
  // // menampiljan nilai setelah diurutkan
  // cout << "\nNilai setelah diurutkan =" << endl;
  // for (i = 0; i < 6; i++){
  //   cout << data[i] << " ";
  // }

  int data[10] = { 5,12,4,13,2,14,21,643,74,23};
  Sort(data);
  for (int i = 0; i < 10; i++)
  {
    cout<<data[i]<<", ";
  }
}

/*
  dataInt: array[1..6] of integer
  i, j, temp,, iBiggest, iLast: integer
  iLast<-6
  
  algoritma: 
  
  for i <- 1 to 6 do
    read(dataInt[i])
  endfor

  for i <- 1 to 6 do
    iBiggest <- 1
    for j <- 2 to iLast do
      if dataINt[j] > dataInt[iBiggest] then
        iBiggest <- j
      endif
    endfor
    temp <- dataInt[iLast]
    dataInt[iLast] <- dataInt[iBiggest]
    dataInt[iBiggest] <- temp
    iLast--
  endfor

  for i <- 1 to 6 do
    write(dataInt[i], ", ");
  endfor
*/

/*
  deklarasi:
  dataInt: array[1...10] of integer
  i: integer

  Procedure sortArrayDesc(dataInt: array[1...10] of integer)
  { mengurutkan data dalam array dari besar ke kecil }
  { mengurutkan menggunakan metode insertion }

    deklarasi :
      temp, j: integer

    algoritma:
      for i <- 10 downTo 1 do
        tekp <- dataInt[i]
        j <- i+1
        while (temp < dataInt[j]) and (j<=9) do
          dataInt[j-1] <- data[j]
          j++
        endwhile
        data[j-1] <- temp
      endfor

  Algoritma
    dataInt <- {5,12,4,13,2,14,21,643,74,23}
    SortArrayDesc(dataInt)
    for i <- 1 to 10 do
      write(dataInt[i], ", ")
    endfor
*/