#include <bits/stdc++.h>
using namespace std;

class Karakter
{
protected:
    string nama;
    char tier;
    int hp;
    int attackPower;

public:
    Karakter(string n, char t, int h, int atk)
    {
        nama = n;
        tier = t;
        hp = h;
        attackPower = atk;
    }
    string getName()
    {
        return nama;
    }
    char getTier()
    {
        return tier;
    }
    void setTier(char t)
    {
        tier = t;
    }
    virtual void displayInfo()
    {
        cout << "Nama: " << nama << endl;
        cout << "Tier: " << tier << endl;
        cout << "Hp: " << hp << endl;
        cout << "Attack: " << attackPower << endl;
    }
    virtual void useSkill() = 0;
};
class Warrior : public Karakter
{

private:
    int stamina;

public:
    Warrior(string n, char t, int h, int atk, int stamin) : Karakter(n, t, h, atk)
    {
        stamina = stamin;
    }
    void useSkill()
    {
        if (stamina >= 20)
        {
            stamina -= 20;
            cout << "stamina terpakai";
        }
        else
        {
            cout << "stamina tidak cukup";
        }
    }
    void displayInfo()
    {
        Karakter ::displayInfo();
        cout << stamina << endl;
    }
};

class mage : public Karakter
{
private:
    int mana;

public:
    mage(string n, char t, int h, int atk, int manaku) : Karakter(n, t, h, atk)
    {
        mana = manaku;
    }
    void useSkill()
    {
        if (mana >= 20)
        {
            mana -= 20;
            cout << "mana digunakan";
        }
        else
        {
            cout << "mana kurang cok";
        }
    }
    void displayInfo()
    {
        Karakter ::displayInfo();
        cout << "mana: " << mana << endl;
    }
};
int main()
{
    Karakter *daftarKarakter[100];
    int jumlah = 0;
    string nama;
    char tier;
    int choice, hp, attackPower, mana, stamina, tipe;
    do
    {

        cout << "Masukan code perintah" << endl;
        cin >> choice;
        if (choice == 1)
        {
            cout << "Nama: ";
            cin >> nama;
            cout << "Tier (A-E): ";
            cin >> tier;
            cout << "HP: ";
            cin >> hp;
            cout << "Attack: ";
            cin >> attackPower;
            cout << "masukan tipe" << endl;
            cin >> tipe;
            if (tipe == 1)
            {
                cout << "masukan stamina" << endl;
                cin >> stamina;
                daftarKarakter[jumlah++] = new Warrior(nama, tier, hp, attackPower, stamina);
            }
            else
            {
                cout << "masukan mana" << endl;
                cin >> mana;
                daftarKarakter[jumlah++] = new mage(nama, tier, hp, attackPower, mana);
            }
        }
        else
        {
            cout<<endl;
            for (int i = 0; i < jumlah; i++)
            {
                daftarKarakter[i]->displayInfo();
            }
            cout<<endl;
        }
    } while (choice != 6);
}