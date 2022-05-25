#include <iostream>
#include <limits>

using namespace std;

// bentuk data nilai
typedef struct nilai
{
    int semester;
    float ips;
    int sks;
} ip;

// bentuk data biodata
typedef struct biodata
{
    string nama;
    int nim;
    string prodi;
    ip ips[14]; // variabel untuk menyimpan nilai tiap semester. 
} mhs;

mhs mahasiswa;
int ipsLength = 0;  // menentukan nilai semester terakhir yang sudah diisi
bool cekBio = false; // cek apakah sudah mengisi biodata.

// fungsi yang berguna untuk input integer. jika bukan integer akan diminta input ulang
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

// fungsi yang berguna untuk input float. jika bukan float akan diminta input ulang
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

// output/print header untuk tiap section
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

// case 1: output/print alur yang harus diikuti user saat menggunakan program ini
void intro()
{
    header("ALUR PROGRAM");
    cout << "Anda diharapkan memasukkan biodata diri terlebih dahulu\n";
    cout << "Anda diminta setidaknya mengisi IPS semester 1 dan sebanyaknya semester 14\n";
    cout << "Pilih opsi 4 untuk melihat IPK anda\n";
    cout << "Pilih opsi 5 untuk keluar dari program\n";
}

// case 2: inpu t &print biodata
void biodata()
{
    // input biodata
    header("ISI BIODATA");
    cout << "Masukkan nama anda\t: ";
    cin.ignore();
    getline(cin, mahasiswa.nama);

    cout << "Masukkan NIM anda\t: ";
    mahasiswa.nim = inputInt();

    cout << "Masukkan prodi anda\t: ";
    cin.ignore();
    getline(cin, mahasiswa.prodi);

    cekBio = true;
    // output biodata
    header("BIODATA ANDA");
    cout << "Nama\t: " << mahasiswa.nama << "\n";
    cout << "NIM\t: " << mahasiswa.nim << "\n";
    cout << "Prodi\t: " << mahasiswa.prodi << "\n";
}

// case 3: input ips. semester ke berapa ditentukan dengan ipsLength
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

    ipsLength++;
}

bool checkBeforeOutIps()
{
    if (cekBio == false)
    {
        cout << "Anda belum memasukkan biodata. silahkan masukkan biodata terlebih dahulu\n";
        return false;
    }
    cout << "Nama\t: " << mahasiswa.nama << "\n";
    cout << "NIM\t: " << mahasiswa.nim << "\n";
    cout << "Prodi\t: " << mahasiswa.prodi << "\n";
    cout << "Semester: " << ipsLength + 1 << "\n";
    if (ipsLength == 0)
    {
        cout << "Anda belum mengisi IPS, harap pilih opsi 3\n";
        return false;
    }
    return true;
}

// case 4: output/print ips. sesuai banyak semester yang sudah diinputkan berdasarkan ipsLength
int outAllIps(float *ipk, int *tSks)
{
    header("IPS");
    if(!checkBeforeOutIps())
    {
        return 0;
    }

    // pointer array
    int *ptSemester[14];
    float *ptIps[14];
    int *ptSks[14];
    for (int i = 0; i < ipsLength; i++)
    {
        ptSemester[i] = &mahasiswa.ips[i].semester;
        ptIps[i] = &mahasiswa.ips[i].ips;
        ptSks[i] = &mahasiswa.ips[i].sks;
    }

    // pointer to pointer array
    int **ptptSemester[14];
    float **ptptIps[14];
    int **ptptSks[14];
    for (int i = 0; i < ipsLength; i++)
    {
        ptptSemester[i] = &ptSemester[i];
        ptptIps[i] = &ptIps[i];
        ptptSks[i] = &ptSks[i];
    }

    // output/print seluruh ips yang telah diinputkan
    for (int i = 0; i < ipsLength; i++)
    {
        cout << "Semester " << **ptptSemester[i] << "\n";
        cout << "Jumlah SKS : " << **ptptSks[i] << "\n";
        cout << "IPS : " << **ptptIps[i] << "\n\n";
        *ipk += **ptptIps[i];
    }
    *ipk /= ipsLength;
    // menampilkan komentar tambahan sesuai IPK
    cout << "IPK anda " << *ipk << " Dengan total SKS " << *tSks << "\n\n";
    *ipk >= 3.5    ? cout << "IPK anda sangat baik"
    : *ipk >= 3    ? cout << "IPK anda cukup baik"
    : *ipk >= 2.75 ? cout << "Anda disarankan memperbaiki IPK anda"
                    : cout << "Anda harus memperbaiki IPK anda";
    return 0;
}

int outIpsYourLookingFor()
{
    header("LIHAT IPS");
    if (!checkBeforeOutIps())
    {
        return 0;
    }
    
    int semester;
    cout << "Masukkan semester yang ingin dilihat : ";
    semester = inputInt();
    if (semester > ipsLength)
    {
        cout << "Anda baru mengisi hingga semester "<< ipsLength<<"\n";
        return 0;
    }
    cout << "Semester " << mahasiswa.ips[semester-1].semester << "\n";
    cout << "Jumlah SKS : " << mahasiswa.ips[semester-1].sks << "\n";
    cout << "IPS : " << mahasiswa.ips[semester-1].ips << "\n\n";
    return 0;
}

int main()
{
    bool condition = true;
    int option, tSks = 0;
    char ys;
    float ipk = 0.0;

    header("Menghitung IPK");
    cout << "1. Alur Program\n";
    cout << "2. Biodata\n";
    cout << "3. Tambahkan IPS\n";
    cout << "4. Lihat IPK\n";
    cout << "5. Keluar\n";

    while (condition)
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
            outAllIps(&ipk, &tSks);
            break;
        case 5:
            outIpsYourLookingFor();
            break;
        default: // menghentikan perulangan
            condition = false;
            break;
        }
    }

    cout << "\nGoodbye";

    return 0;
}