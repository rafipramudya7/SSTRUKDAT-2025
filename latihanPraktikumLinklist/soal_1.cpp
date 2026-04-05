#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    string name;
    Node *next;
    Node *prev;

    Node(string name)
    {
        this->name = name;
        next = prev = nullptr;
    }
};

class Dll
{
private:
    Node *head;
    Node *tail;
    Node *current;
    int size;

public:
    Dll()
    {
        head = tail = current = nullptr;
        size = 0;
    }
    bool isEmpty()
    {
        return head == nullptr;
    }

    void addStation(string name)
    {
        Node *newNode = new Node(name);
        if (isEmpty())
        {
            head = tail = current = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    void insertEmergency(int index, string name)
    {
        if (index < 0 || index > size)
            return;
        Node *newNode = new Node(name);

        if (isEmpty())
        {
            head = tail = current = newNode;
            size++;
            return;
        }
        else
        {
            if (index == 0)
            {
                head->prev = newNode;
                newNode->next = head;
                head = newNode;
            }
            else if (index == size)
            {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            else
            {

                Node *tmp = head;
                for (int j = 0; j < index - 1; j++)
                {
                    tmp = tmp->next;
                }
                newNode->next = tmp->next;
                newNode->prev = tmp;
                tmp->next->prev = newNode;
                tmp->next = newNode;
            }
        }
        size++;
    }
    void remove(string name)
    {
        // cout << "masuk ke remove";
        if (isEmpty())
            return;

        Node *tmp = head;
        for (int i = 0; i < size; i++)
        {
            // cout << tmp->name;

            if (tmp->name == name)
            {
                // cout << "ketemu";
                break;
            }
            if (i == (size - 1))
                return;
            tmp = tmp->next;
        }
        // cout << "masuk log 0.1";

        if (head == tail)
        {
            head = current = tail = nullptr;
        }
        else if (tmp == head)
        {
            head->next->prev = nullptr;
            head = head->next;
        }
        else if (tmp == tail)
        {
            tail->prev->next = nullptr;
            tail = tail->prev;
        }
        else
        {
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
        }
        // printf(" debug masuk dan akan menghapus %s: \n", tmp->name);

        if (current == tmp)
        {
            // cout << "masuk log 1 " << endl;

            if (tmp->next != nullptr)
            {
                current = tmp->next;
            }
            else
            {
                current = tmp->prev;
            }
        }
        // cout << "berhasil dihapus";
        delete tmp;
        size--;
    }

    void forward()
    {
        if (isEmpty() || current->next == nullptr)
        {
            cout << "Kereta tidak bisa bergerak, salju terlalu tebal!" << endl;
            return;
        }
        current = current->next;
    }
    void backward()
    {
        if (isEmpty() || current->prev == nullptr)
        {
            cout << "Kereta tidak bisa bergerak, salju terlalu tebal!" << endl;
            return;
        }
        current = current->prev;
    }

    void cekposisi()
    {
        if (isEmpty())
        {
            cout << "Takaki tersesat di tengah badai salju..." << endl;
        }
        else
        {
            cout << "Takaki sekarang berada di: " << current->name << endl;
        }
    }

    void debugger()
    {
        Node *tmp;
        tmp = head;

        cout << endl;
        for (int i = 0; i < size; i++)
        {
            cout << tmp->name << " ";
            if (tmp == current)
            {
                cout << "<- takaki in here";
            }
            tmp = tmp->next;
            cout << endl;
        }
    }
};

int main()
{
    int n;
    cin >> n;

    Dll dataSet;

    while (n--)
    {
        string perintah;
        cin >> perintah;
        if (perintah == "ADD_STATION")
        {
            string nama;
            cin >> nama;
            dataSet.addStation(nama);
        }
        else if (perintah == "INSERT_EMERGENCY")
        {
            int idx;
            string name;
            cin >> idx >> name;
            dataSet.insertEmergency(idx, name);
        }
        else if (perintah == "REMOVE_STATION")
        {
            string name;
            cin >> name;
            dataSet.remove(name);
        }
        else if (perintah == "MOVE_FORWARD")
        {
            dataSet.forward();
        }
        else if (perintah == "MOVE_BACKWARD")
        {
            dataSet.backward();
        }
        else if (perintah == "WHERE_AM_I")
        {
            dataSet.cekposisi();
        }
        // dataSet.debugger();
        /* code */
    }
}

/*
remove() jika yang diinput current masih error (posisi di tail)
remove() jika yang diinput current masih error (posisi terakhir)

*/