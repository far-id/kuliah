#include <iostream>
#include <limits>

using namespace std;

typedef struct nilai
{
    int semester;
    float ips;
    int sks;
} ip;

typedef struct biodata
{
    string nama;
    int nim;
    string prodi;
    ip ips[14];
} mhs;

mhs mahasiswa;
int ipsLength = 0;
bool cBio = false, cIps = false;

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

float inputFloat()
{
    float x = 0;
    while (!(cin >> x))
    {
        cin.clear();
        cin.ignore();
        cout << "Input bukan float. coba lagi : ";
    }
    return x;
}

void header(string label)
{
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
    header("ALUR PROGRAM");
    cout << "Anda diharapkan memasukkan biodata diri terlebih dahulu\n";
    cout << "Anda diminta setidaknya mengisi IPS semester 1 dan sebanyaknya semester 14\n";
    cout << "Pilih opsi 4 untuk melihat IPK anda\n";
    cout << "Pilih opsi 5 untuk keluar dari program\n";
}

void biodata()
{
    header("ISI BIODATA");
    cout << "Masukkan nama anda\t: ";
    cin.ignore();
    getline(cin, mahasiswa.nama);

    cout << "Masukkan NIM anda\t: ";
    mahasiswa.nim = inputInt();

    cout << "Masukkan prodi anda\t: ";
    cin.ignore();
    getline(cin, mahasiswa.prodi);

    cBio = true;
    header("BIODATA ANDA");
    cout << "Nama\t: " << mahasiswa.nama << "\n";
    cout << "NIM\t: " << mahasiswa.nim << "\n";
    cout << "Prodi\t: " << mahasiswa.prodi << "\n";
}

void addIps(int *tSks)
{
    header("Masukkan IPS");
    cout << "Semester : " << ipsLength + 1 << "\n";

    mahasiswa.ips[ipsLength].semester = ipsLength + 1;
    cout << "Jumlah SKS : ";
    mahasiswa.ips[ipsLength].sks = inputInt();
    cout << "IPS : ";
    mahasiswa.ips[ipsLength].ips = inputFloat();
    *tSks += mahasiswa.ips[ipsLength].sks;

    cIps = true;
    ipsLength++;
}

void outIps(float *ipk, int *tSks)
{
    header("IPS");
    if (!cBio)
    {
        cout << "Anda belum mengisi biodata, harap pilih opsi 2\n";
    }else {
        cout << "Nama\t: " << mahasiswa.nama << "\n";
        cout << "NIM\t: " << mahasiswa.nim << "\n";
        cout << "Prodi\t: " << mahasiswa.prodi << "\n";
    }
    if (ipsLength == 0)
    {
        cout << "Anda belum mengisi IPS, harap pilih opsi 3\n";
    }
    
    for (int i = 0; i < ipsLength; i++)
    {
        cout << "Semester " << mahasiswa.ips[i].semester << "\n";
        cout << "Jumlah SKS : " << mahasiswa.ips[i].sks << "\n";
        cout << "IPS : " << mahasiswa.ips[i].ips << "\n\n";
        *ipk += mahasiswa.ips[i].ips;
    }

    *ipk /= ipsLength;
    cout << "IPK anda " << *ipk << " Dengan total SKS " << *tSks << "\n\n";
    *ipk >= 3.5    ? cout << "IPK anda sangat baik"
    : *ipk >= 3    ? cout << "IPK anda cukup baik"
    : *ipk >= 2.75 ? cout << "Anda disarankan memperbaiki IPK anda"
                   : cout << "Anda harus memperbaiki IPK anda";
}

int main()
{
    bool con = true;
    int option, tSks = 0;
    char ys;
    float ipk = 0.0;

    header("Menghitung IPK");
    cout << "1. Alur Program\n";
    cout << "2. Biodata\n";
    cout << "3. Tambahkan IPS\n";
    cout << "4. Lihat IPK\n";
    cout << "5. Keluar\n";

    while (con)
    {
        cout << "\nPilih opsi (1,2,...5) : ";
        option = inputInt();
        switch (option)
        {
        case 1:
            intro();
            break;

        case 2:
            biodata();
            break;

        case 3:
            addIps(&tSks);
            break;

        case 4:
            outIps(&ipk, &tSks);
            break;
        default: // menghentikan perulangan
            con = false;
            break;
        }
    }
    
    cout << "\nGoodbye";

    return 0;
}