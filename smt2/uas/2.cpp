#include <iostream>
#include <stdlib.h>
#define MAX 10

using namespace std;
int queue[MAX];
int head = -1, tail = -1;

bool isEmpty(){
    // jika head atau depannya -1 yang artinya kosong maka return true
    if (head == -1)
    {
        return true;
    }
    // jika kondisi diatas tidak terpenuhi maka teturn false;
    return false;
}

bool isFull(){
    // jika tail atau belakannya 10 yang artinya penuh maka return true
    if (tail == 10)
    {
        return true;
    }
    // jika kondisi diatas tidak terpenuhi maka teturn false;
    return false;
}
void tampilkan()
{
    int i;
    if (!isEmpty())
    {
        for (i = head; i <= tail; i++)
        {
            cout << queue[i] << " | ";
        }
    }
}
void enqueue(){
    int data;
    cout<<"Masukkan data :";
    cin>>data;
    if (isEmpty()){
        head = 0;
        tail++;
        queue[tail] = data;
    }else if(!isFull()){
        tail++;
        queue[tail] = data;
    }
    cout<<tail<<head;
    tampilkan();
}

void dequeue(){
    for (int i = 0; i < tail; i++)
    {
        queue[i] = queue[i+1];
    }
    tail--;
    tampilkan();
}

int main(){
    int pilih;
    do
    {
        cout << "\n1. isEmpty\n";
        cout << "2. isFull\n";
        cout << "3. enqueue\n";
        cout << "4. dequeue\n";
        cout << "5. tampilkan\n";
        cin>>pilih;
        switch (pilih)
        {
        case 1: isEmpty();
            break;
        case 2: isFull();
            break;
        case 3: enqueue();
            break;
        case 4: dequeue();
            break;
        case 5: tampilkan();
            break;
        case 6: cout<<"Terimakasih";
        
        default: cout<<"Pilihan tidak ada";
            break;
        }
    } while (pilih != 6);

    return 0;
}