#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    string nama;
    int stamina;

    Node *next;

    Node(string a, int b)
    {
        nama = a;
        stamina = b;
        next = nullptr;
    }
};

class Dl
{
private:
    Node *Head;
    Node *tail;
    int size;

public:
    Dl()
    {
        Head = tail = nullptr;
        size = 0;
    }
    bool isEmpty()
    {
        return Head == nullptr;
    }
    void pushBack(string a, int b)
    {
        Node *newNode = new Node(a, b);
        if (isEmpty())
        {
            Head = tail = newNode;
        }
        else
        {
            newNode->next = nullptr;
            tail->next = newNode;
            tail = newNode;
        }
        printf("Kegiatan %s berhasil ditambahkan!\n", a);
        size++;
    }

    void pushFront(string a, int b)
    {
        Node *newNode = new Node(a, b);
        if (isEmpty())
        {
            Head = tail = newNode;
        }
        else
        {
            newNode->next = Head;
            Head = newNode;
        }
        printf("Kegiatan %s berhasil ditambahkan di depan!\n", a);
        size++;
    }
    void sisipkan(string a, int b, int c)
    {
        Node *newNode = new Node(a, b);
        Node *tmp = Head;

        if (c < 0 || c > size)
        {
            cout << "Index tidak valid!"
                 << endl;
            return;
        }

        if (c == 0)
        {
            if (isEmpty())
            {
                Head = tail = newNode;
            }
            else
            {
                newNode->next = Head;
                Head = newNode;
            }
        }
        else if (c == size)
        {
            if (isEmpty())
            {
                Head = tail = newNode;
            }
            else
            {
                newNode->next = nullptr;
                tail->next = newNode;
                tail = newNode;
            }
        }
        else
        {
            for (int i = 0; i < (c - 1); i++)
            {
                tmp = tmp->next;
            }

            newNode->next = tmp->next;
            tmp->next = newNode;
        }
        cout << "Kegiatan berhasil disisipkan!\n"
             << endl;
        size++;
        return;
    }
    void remove(int a)
    {
        Node *tmp = Head;
        if (a < 0 || a >= size)
        {
            cout << "Index tidak ditemukan!\n";
            return;
        }
        else if (size == 1)
        {
            delete Head;
            Head = tail = nullptr;
        }
        else if (a == 0)
        {
            Node *target = Head;
            Head = Head->next;
            delete target;
        }
        else if (a == size - 1)
        {
            Node *target = tail;
            while (tmp->next->next != nullptr)
            {
                tmp = tmp->next;
            }
            tail = tmp;
            tail->next = nullptr;
            delete target;
        }
        else
        {
            for (int i = 0; i < (a - 1); i++)
            {
                tmp = tmp->next;
            }
            Node *target = tmp->next;
            tmp->next = tmp->next->next;
            delete target;
        }
        size--;
        cout << "Kegiatan berhasil dihapus!\n";
        return;
    }

    void histori()
    {
        int n = size;
        cout << "Daftar Kegiatan\n";

        if (n == 0)
        {
            cout << "Belum ada kegiatan.\n";
            return;
        }
        Node *tmp = Head;
        int idx = 0;

        while (tmp != nullptr)
        {
            cout << "[" << idx << "] " << tmp->nama << " (Energi: " << tmp->stamina << ")\n";
            tmp = tmp->next;
            idx++;
        }
    }
    void status()
    {
        int jumlah = 0;
        Node *tmp = Head;
        while (tmp != nullptr)
        {
            jumlah += tmp->stamina;
            tmp = tmp->next;
        }
        cout << "Total Energi yang dibutuhkan: " << jumlah << "\n";
        return;
    }
};

int main()
{
    Dl dataSet;
    while (true)
    {
        int a, b;
        string c, perintah;
        cin >> perintah;

        if (perintah == "KEGIATAN")
        {
            cin >> c >> a;
            dataSet.pushBack(c, a);
        }
        else if (perintah == "TAMBAH")
        {
            cin >> c >> a;
            dataSet.pushFront(c, a);
        }
        else if (perintah == "SISIPKAN")
        {
            cin >> c >> b >> a;
            dataSet.sisipkan(c, b, a);
        }
        else if (perintah == "HAPUS")
        {
            cin >> a;
            dataSet.remove(a);
        }
        else if (perintah == "HISTORI")
        {
            dataSet.histori();
        }
        else if (perintah == "STATUS")
        {
            dataSet.status();
        }
        else
        {
            cout << "Perintah tidak dikenali!\n";
            break;
        }
        return;
        /* code */
    }
}

/*

issue with remove() kondisi removefront

tinjau head dan tail tiap fungsi
*/