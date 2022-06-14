#include <iostream>
#include <limits>
using namespace std;

int inputInt(){
    int x = 0;
    // jika input mengalami kegagalan ulangi input
    while (!(cin >> x)){
        cin.clear();
        cin.ignore(numeric_limits<int>::max(), '\n');
        cout << "Input bukan integer. coba lagi : ";
    }
    return x;
}

void tampil(int *stack, int &top){
    cout << "Stack : \n";
    // menampilkan array dari top ke data awal
    for (int i = top; i >= 0; i--)
    {
        cout << stack[i] << "\n";
    }
    cout << endl;
}

void push(int *stack, int &top){
    // jika data index terakhir adalah 9 maka stack penuh. jika tidak maka tambahkan dan tampilkan data
    if (top == 9){
        cout << "Stack penuh" << endl;
    } else {
        cout<<"Data : ";
        top++;
        stack[top] = inputInt();
    }
    tampil(stack, top);
}

void pop(int *stack, int &top){
    // jika data index terakhir adalah -1 maka stack kosong. jika tidak maka hapus dan tampilkan data
    top == -1 ? void(cout << "Stack kosong" << endl) : void(top--);
    tampil(stack, top);
}

void topElement(int *stack, int &top){
    // jika data index terakhir adalah -1 maka stack kosong. jika tidak maka tampilkan data teratas
    top == -1 ? cout << "Stack kosong" << endl : cout << "Top element : " << stack[top] << endl;
}

void isEmpty(int *stack, int &top){
    // jika data index terakhir adalah -1 maka stack kosong. jika tidak maka stack tidak kosong
    top == -1 ? cout << "Stack kosong" << endl : cout << "Stack tidak kosong" << endl;
}

void isFull(int *stack, int &top){
    // jika data index terakhir adalah 9 maka stack penuh. jika tidak maka stack tidak penuh
    top == 9 ? cout << "Stack penuh" << endl : cout << "Stack tidak penuh" << endl;
}
void pilihan(){
    // menampilkan pilihan menu
    cout << "1. Masukkan data" << endl;
    cout << "2. Keluarkan data" << endl;
    cout << "3. Cek data teratas" << endl;
    cout << "4. Cek kosong" << endl;
    cout << "5. Cek penuh" << endl;
    cout << "6. Keluar" << endl;
    
}
int main(){
    // deklarasi variable yang dibutuhkan
    int stack[10], top = -1, condition;
    pilihan();
    // pengulangan pemilihan menu
    do{
        cout << "Pilih menu (1-6): ";
        condition = inputInt();
        switch (condition){
            case 1 : push(stack, top);
                break;
            case 2 : pop(stack, top);
                break;
            case 3 : topElement(stack, top);
                break;
            case 4 : isEmpty(stack, top);
                break;
            case 5 : isFull(stack, top);
                break;
            case 6 : cout << "Terima kasih" << endl;
                break;
            default : cout << "Pilihan tidak ada" << endl;
                break;
        }
    } while (condition != 6);
    return 0;
}