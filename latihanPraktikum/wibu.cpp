#include <bits/stdc++.h>
using namespace std;

class Karakter
{
protected:
    string nama;
    string ekspresi;
    int level;

public:
    Karakter(string a, string b, int c)
    {
        nama = a;
        ekspresi = b;
        level = c;
    }
    virtual void change(string s) = 0;

    string getName()
    {
        return nama;
    }
    void getWajah()
    {
        if (ekspresi == "biasa")
        {
            cout << "( o_o )" << endl;
        }
        else if (ekspresi == "senang")
        {
            cout << "( ^_^ )" << endl;
        }
        else if (ekspresi == "sedih")
            cout << "( T_T )" << endl;
    }

    virtual void displayKarakter() = 0;
    virtual void tampilInfo() = 0;
};

class Manusia : public Karakter
{
private:
    string perasaan;

public:
    Manusia(string a, string b, int c, string d) : Karakter(a, b, c)
    {
        perasaan = d;
    }
    void displayKarakter()
    {
        if (perasaan == "penasaran")
        {
            cout << "🤔" << endl;
        }
        else if (perasaan == "jatuh cinta")
        {
            cout << "🥰" << endl;
        }
        else if (perasaan == "patah hati")
        {
            cout << "<^_~" << endl;
        }
    }
    void tampilInfo()
    {
        cout << "nama: " << nama << endl;
        cout << "ekspresi: " << ekspresi << endl;
        cout << "level: " << level << endl;
        cout << "perasaan " << perasaan << endl;
    }
    void change(string s)
    {
        perasaan = s;
    }
};

class vampir : public Karakter
{
private:
    string tekad;

public:
    vampir(string a, string b, int c, string d) : Karakter(a, b, c)
    {
        tekad = d;
    }
    void displayKarakter()
    {
        if (tekad == "menyembunyikan")
        {
            cout << "🤔" << endl;
        }
        else if (tekad == "mengungkapkan")
        {
            cout << "🥰" << endl;
        }
        else if (tekad == "melindungi")
        {
            cout << "<^_~" << endl;
        }
    }
    void tampilInfo()
    {
        cout << "nama: " << nama << endl;
        cout << "ekspresi: " << ekspresi << endl;
        cout << "level: " << level << endl;
        cout << "tekad: " << tekad << endl;
    }
    void change(string s)
    {
        tekad = s;
    }
};

int main()
{
    Karakter *dataFull[100];
    int tipe, c, jenis, jumlah = 0;
    string a, b, d, tmp;

    do
    {
        cout << "masukan tipe : ";
        cin >> tipe;
        if (tipe == 1)
        {
            cout << "masukan nama: ";
            cin >> a;
            cout << "masukan ekspresi: ";
            cin >> b;
            cout << "masukan leve: l";
            cin >> c;
            cout << "masukan jenis: ";
            cin >> jenis;
            if (jenis == 1)
            {
                cout << "masukan perasaan: ";
                cin >> d;
                dataFull[jumlah++] = new Manusia(a, b, c, d);
            }
            else
            {
                cout << "masukan tekad";
                cin >> d;
                dataFull[jumlah++] = new vampir(a, b, c, d);
            }
        }
        else if (tipe == 2)
        {
            for (int i = 0; i < jumlah; i++)
            {
                dataFull[i]->displayKarakter();
                cout << endl;
                dataFull[i]->tampilInfo();
            }
        }
        else if (tipe == 3)
        {
            cout << "masukan nama: ";
            cin >> tmp;

            for (int i = 0; i < jumlah; i++)
            {
                if ((dataFull[i]->getName()) == tmp)
                {

                    cout << "masukan perasaan/tekad: " << endl;
                    cin >> tmp;
                    dataFull[i]->change(tmp);
                    break;
                }
            }
        }
        else if (tipe == 4)
        {
            cout << "masukan nama: " << endl;
            cin >> tmp;
            for (int i = 0; i < jumlah; i++)
            {
                if (dataFull[i]->getName() == tmp)
                {
                    delete dataFull[i];
                    for (int j = i; j < jumlah - 1; j++)
                    {
                        dataFull[i] = dataFull[i + 1];
                        /* code */
                    }
                    jumlah--;
                    break;
                }
            }
        }
    } while (tipe != 5);
}