#include <bits/stdc++.h>
using namespace std;

int jumlah;
bool ceoSudahMengaku = false;
bool sudahAdaCeo = false;
class orang
{
protected:
    string nama;
    int umur;

public:
    orang(string a, int b)
    {
        nama = a;
        umur = b;
    }
    string getNama()
    {
        return nama;
    }
    virtual void tampilInfo()
    {
        cout << endl
             << endl;
        cout << "nama: " << nama << endl;
        cout << "umur: " << umur << endl;
    };
    virtual string getTipe() = 0;
    virtual void ubahDepartemen(string departemen) = 0;
    virtual void mengaku() = 0;
    ~orang()
    {
        cout << "menghancurkan orang" << endl;
    }
};
orang *daftarOrang[100];

class karyawan : public orang
{
protected:
    string departemen;

public:
    karyawan(string a, int b, string c) : orang(a, b)
    {
        departemen = c;
    }
    void tampilInfo()
    {
        orang::tampilInfo();
        cout << "departemen: " << departemen << endl;
    }
    void ubahDepartemen(string a)
    {
        departemen = a;
    }
    string getTipe()
    {
        return "karyawan";
    }
    void mengaku()
    {
        cout << "karyawan mengaku";
    }
    ~karyawan()
    {
        cout << "menghancurkan karyawan";
    }
};

class ceo : public karyawan
{
protected:
    long long totalAset;

public:
    ceo(string a, int b, string c, long long d) : karyawan(a, b, c)
    {
        totalAset = d;
    }
    void mengaku()
    {
        ceoSudahMengaku = true;
        cout << endl;
        cout << "nama:" << nama << endl;
        cout << "total aset: " << totalAset << endl;
        cout << "umur: " << umur << endl;
        cout << "departemen: " << departemen << endl;
    }
    string getTipe()
    {
        return "[CEO]";
    }
    void tampilInfo()
    {
        for (int i = 0; i < jumlah; i++)
        {
            cout << endl;
            if (daftarOrang[i]->getTipe() == "karyawan")
            {
                daftarOrang[i]->tampilInfo();
            }
            else
            {
                daftarOrang[i]->mengaku();
            }
            cout << daftarOrang[i]->getTipe();
        }
    }
    ~ceo()
    {
        cout << "menghancurkan ceo" << endl;
    }
};

void daftarkanOrang()
{
    string nama;
    int umur;
    string departemen;
    long long totalAset;
    int tipe;
    cout << "masukan tipe(2 = ceo): ";
    cin >> tipe;
    cout << "masukan nama: ";
    cin >> nama;
    cout << "masukan umur: ";
    cin >> umur;
    cout << "masukan departemen: ";
    cin >> departemen;
    cout << "sudah masuk";
    if (tipe == 2)
    {
        cout << "masukan total aset: ";
        cin >> totalAset;
        daftarOrang[jumlah++] = new ceo(nama, umur, departemen, totalAset);
    }
    else
    {
        daftarOrang[jumlah++] = new karyawan(nama, umur, departemen);
    }
}

void lihatSemuaData()
{
    for (int i = 0; i < jumlah; i++)
    {
        if (daftarOrang[i]->getTipe() == "karyawan")
        {
            daftarOrang[i]->tampilInfo();
        }
        else
        {
            daftarOrang[i]->mengaku();
        }
    }
}

void pindahKerja()
{
    string departemen, nama;
    cout << "masukan nama: ";
    cin >> nama;
    cout << "masukan departemen pindahan: ";
    cin >> departemen;
    for (int i = 0; i < jumlah; i++)
    {
        if (daftarOrang[i]->getNama() == nama)
        {
            daftarOrang[i]->ubahDepartemen(departemen);
            break;
        }
        /* code */
    }
}
void pecatKaryawan()
{
    string nama;
    cout << "masukan nama: ";
    cin >> nama;
    for (int i = 0; i < jumlah; i++)
    {
        if (daftarOrang[i]->getNama() == nama)
        {
            if (daftarOrang[i]->getTipe() == "karyawan")
            {
                if (ceoSudahMengaku)
                {
                    delete daftarOrang[i];

                    for (int j = i; j < jumlah - 1; j++)
                    {
                        daftarOrang[i] = daftarOrang[i + 1];
                    }
                    jumlah--;
                }
                else
                {
                    cout << "ceo belum ngaku jier" << endl;
                }
            }
            cout<<"tidak bisa ganti karena ceo"<<endl;

            break;
        }
        /* code */
    }
}

void ceoMengaku()
{
    string nama;
    cout << "masukan nama: ";
    cin >> nama;
    for (int i = 0; i < jumlah; i++)
    {
        if (daftarOrang[i]->getNama() == nama)
        {
            if (daftarOrang[i]->getTipe() == "karyawan")
            {
                cout << "kamu bukan ceo" << endl;
            }
            else
            {
                daftarOrang[i]->mengaku();
            }
            break;
        }
        /* code */
    }
}

int main()
{
    int loopVar;

    do
    {
        cout << "masukan perintah eksekusi: " << endl;
        cin >> loopVar;
        if (loopVar == 1)
        {
            daftarkanOrang();
        }
        else if (loopVar == 2)
        {
            lihatSemuaData();
        }
        else if (loopVar == 3)
        {
            pindahKerja();
        }
        else if (loopVar == 4)
        {
            pecatKaryawan();
        }
        else if (loopVar == 5)
        {
            ceoMengaku();
        }
    } while (loopVar != 6);

    delete daftarOrang;

    /*
    [PROBLEM]
    -- urutan inheritance penurunan fungsi aman atau tidak
    -- dalam penggunaan lihaat data nanti ceo sudah mengaku langsung otomatis true
    -- destructor masih bingung
    -- pendeklarasian data array nya bagiamnaa
    */
    return 0;
}