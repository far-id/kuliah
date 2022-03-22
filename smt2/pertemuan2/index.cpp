#include <iostream>
#include <limits>

using namespace std;

int length = 0;
typedef struct nilai
{
    string semester;
    float ips;
    int sks;
} ipk;

typedef struct biodata{
    string nama;
    int nim;
    string prodi;
    ipk ips[14];
} mhs;

mhs mahasiswa;



bool already(string value){
    // for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
    // {
    //     if (value == array[i])
    //     {
    //         return true;
    //     }
    // }
    return false;
}

bool add(string value){
    // if (already(value))
    // {
    //     return false;
    // }

    // array[length] = value;
    // length++;
    return true;
}

void hapus(string value){
    // for (int i = 0; i < length; i++)
    // {
    //     if (value == array[i])
    //     {
    //         array[i] = "";
    //         for (int j = i; j < length; j++)
    //         {

    //             array[j] = array[j + 1];
    //         }
    //         length--;
    //     }
    // }
}

void outarray(){
    // cout << "array [";
    // for (int i = 0; i < length; i++)
    // {
    //     cout << array[i] << ", ";
    // }
    // cout << "]";
}

int inputInt()
{
    int x = 0;
    while (!(cin >> x))
    {
        cin.clear();
        cin.ignore(numeric_limits<int>::max(), '\n');
        cout << "Input bukan integer. coba lagi : ";
    }
    return x;
}

void header(string label){
    int length = 40, i, 
        start = length - (length / 2) - (label.length() / 2),
        loop = length - label.length();
    cout << endl;
    for (i = 0; i <= loop; i++)
    {
        i == start ? cout << " " << label << " " : cout << "=";
    }
    cout << endl;
}

void intro()
{
    header("INTRO");
    cout << "Anda diharapkan memasukkan biodata diri terlebih dahulu\n";
    cout << "Anda diminta setidaknya mengisi IPS semester 1 dan sebanyaknya semester 14\n";
    cout << "Anda bisa memilih opsi 4 untuk melihat IPK anda\n";
}

void biodata(){
    header("ISI BIODATA");
    cout << "Masukkan nama anda : ";
    cin.ignore();
    getline(cin, mahasiswa.nama);

    cout << "Masukkan NIM anda : ";
    mahasiswa.nim = inputInt();

    cout << "Masukkan prodi anda : ";
    cin.ignore();
    getline(cin, mahasiswa.prodi);

    header("BIODATA ANDA");
    cout<<"Nama\t: "<<mahasiswa.nama<<"\n";
    cout<<"NIM\t:"<<mahasiswa.nim<<"\n";
    cout<<"Prodi\t: "<<mahasiswa.prodi<<"\n";
}

void addIps(){
    header("IPS");
    cout << "Masukkan IPS semester 1 : ";
    mahasiswa.ips[0].semester = "semester 1";
    mahasiswa.ips[0].ips = inputInt();
    mahasiswa.ips[0].sks = 20;
}

void outIps(){
    header("IPS");
    cout << "IPS semester 1 : " << mahasiswa.ips[0].ips << " dengan SKS " << mahasiswa.ips[0].sks << endl;
}


int main()
{
    bool con = true;
    int option;
    char ys;
    
    header("Menghitung IPK");
    cout << "1. Intro\n";
    cout << "2. Biodata\n";
    cout << "3. Tambahkan IPS\n";
    cout << "4. Lihat IPK\n";
    cout << "5. Keluar\n";
    cout << "Pilih opsi (1,2,...5) : ";
    option = inputInt();
    while (con)
    {
        switch (option)
        {
        case 1:
            intro();
            break;

        case 2:
            biodata();
            break;
            
        case 3:
            addIps();
            outIps();
            break;
        default: // menghentikan perulangan
            con = false;
            break;
        }

        cout << "\n(1,2,...5)";
        option = inputInt();
    }

    return 0;
}