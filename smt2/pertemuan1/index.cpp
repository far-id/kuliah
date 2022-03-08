#include <iostream>
#include <limits>

using namespace std;

void segitiga(){
    int baris = 10, i, j;
    // vertikal
    for ( i = 0; i < baris; i++)
    {
        // horizontal
        for ( j = 0; j < i; j++) cout<<"*";
        cout<<endl;
    }
    
}

void cursedSegitiga(){
    int baris = 10, i, j;
    //perulangan untuk tinggi segitiga atas
    for ( i = 1; i <= baris; i++)
    {
        // segitiga kiri
        for ( j = 1; j <= baris; j++) j <= i ? cout << "*" : cout << " ";

        // segitiga tengah
        for (j = baris; j >= 1; j--) j <= i ? cout << "*" : cout << " ";
        for (j = 1; j <= baris; j++) j <= i ? cout << "*" : cout << " ";

        // segitiga kanan
        for ( j = baris; j >= 1; j--) j <= i ? cout << "*" : cout << " ";
        cout<<endl;
    }

    // pembatas tengah
    for (i = 0; i < 13; i++) cout<<" = ";
    cout<<endl;

    // perulangan untuk segitiga bawah
    for ( i = baris; i >= 1; i--)
    {
        // segitiga kiri
        for ( j = 1; j <= baris; j++) j <= i ? cout << "*" : cout << " ";

        // segitiga tengah
        for (j = baris; j >= 1; j--) j <= i ? cout << "*" : cout << " ";
        for (j = 1; j <= baris; j++) j <= i ? cout << "*" : cout << " ";

        // segitiga kanan
        for ( j = baris; j >= 1; j--) j <= i ? cout << "*" : cout << " ";
        cout<<endl;
    }
}

// mencegah user menginputkan selain integer dan meminta inputan ulang jika bukan integer
int inputInt()
{
    int x = 0;
    while (!(cin >> x))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Input bukan integer. coba lagi : ";
    }
    return x;
}

// header
void header(string label){
    //deklarasi
    int l = 10, i, center = l / 2;
    // menampilkan header
    for (i = 0; i <= l; i++)
    {
        // ketika ditengah tampilkan label, jika tidak tampilkan "="
        i == center ? cout<<"\t"<<label<<"\t" : cout << "=";
    }
    cout<<endl;
}

// template biodata
void biodata (string nama, int nim, string domisili, string ttl, string jk){
    cout << "Nama \t\t: " << nama; cout<<"\n";
    cout << "NIM \t\t: " << nim << "\n";
    cout << "Domisili\t: " << domisili << "\n";
    cout << "TTL \t\t : " << ttl << "\n";
    cout << "Jenis Kelamin \t: " << jk << "\n";
}

int main()
{
    // deklarasi
    bool con = true;
    int opt, nim = 2103015048;
    string nama = "Farid Rizk Wijaya", domisili = "Gn. Putri", jk ="Laki-laki", ttl = "Boyolali, 24 Oktober 2003", repeat;
    char ys;

    header("Tugas 1");
    cout<<"* Pilih Salah satu nomor dibawah!\n";
    cout<<"1. Biodata\n";
    cout<<"2. Segitiga\n";
    cout<<"(1, 2, 3)";
    opt = inputInt();
    while (con)
    {
        switch(opt){
            case 1 : // biodata
                header("Biodata");
                biodata(nama, nim, domisili, ttl, jk);
                cout<<"\nIngin membuat Biodata sendiri ? (y/n)";
                cin>>ys;
                if (ys == 'y')
                {
                    cin.ignore();
                    cout<<"\nNama : ";
                    getline(cin, nama);

                    cout<<"NIM : ";
                    nim = inputInt();

                    cout<<"Domisili : ";
                    getline(cin, domisili);

                    cout<<"TTL : ";
                    getline(cin, ttl);

                    cout<<"Jenis Kelamin : ";
                    getline(cin, jk);
                    biodata(nama, nim, domisili, ttl, jk);
                }
                
                break;
            case 2: //segitiga
                segitiga();
                cout<<"\nIngin menjalankan segitiga lainnya? (y/n)";
                cin>>ys;
                if (ys == 'y')
                {
                    cursedSegitiga();
                }
                break;
            default: //menghentikan perulangan
                con=false;
                break;
        }

        cout << "(1, 2, 3)";
        opt = inputInt();
    }
    return 0;
}