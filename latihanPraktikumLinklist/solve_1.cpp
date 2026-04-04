#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next;
    Node* prev;

    Node(string name) {
        this->name = name;
        next = prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    Node* current;
    int size;

public:
    DoublyLinkedList() {
        head = tail = current = nullptr;
        size = 0;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    // ADD_STATION
    void addStation(string name) {
        Node* newNode = new Node(name);

        if (isEmpty()) {
            head = tail = current = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    // INSERT_EMERGENCY
    void insertEmergency(int index, string name) {
        if (index < 0 || index > size) return;

        Node* newNode = new Node(name);

        if (isEmpty()) {
            head = tail = current = newNode;
            size++;
            return;
        }

        // insert di depan
        if (index == 0) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            size++;
            return;
        }

        // insert di belakang
        if (index == size) {
            addStation(name);
            return;
        }

        // insert di tengah
        Node* temp = head;
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        newNode->prev = temp;

        temp->next->prev = newNode;
        temp->next = newNode;

        size++;
    }

    // REMOVE_STATION
    void removeStation(string name) {
        if (isEmpty()) return;

        Node* temp = head;

        while (temp != nullptr && temp->name != name) {
            temp = temp->next;
        }

        if (temp == nullptr) return; // tidak ditemukan

        // jika hanya satu node
        if (head == tail) {
            delete temp;
            head = tail = current = nullptr;
            size = 0;
            return;
        }

        // jika node adalah head
        if (temp == head) {
            head = head->next;
            head->prev = nullptr;
        }
        // jika node adalah tail
        else if (temp == tail) {
            tail = tail->prev;
            tail->next = nullptr;
        }
        // node di tengah
        else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }

        // handle current
        if (current == temp) {
            if (temp->next != nullptr) {
                current = temp->next;
            } else {
                current = temp->prev;
            }
        }

        delete temp;
        size--;
    }

    // MOVE_FORWARD
    void moveForward() {
        if (isEmpty() || current->next == nullptr) {
            cout << "Kereta tidak bisa bergerak, salju terlalu tebal!" << endl;
            return;
        }
        current = current->next;
    }

    // MOVE_BACKWARD
    void moveBackward() {
        if (isEmpty() || current->prev == nullptr) {
            cout << "Kereta tidak bisa bergerak, salju terlalu tebal!" << endl;
            return;
        }
        current = current->prev;
    }

    // WHERE_AM_I
    void whereAmI() {
        if (isEmpty()) {
            cout << "Takaki tersesat di tengah badai salju..." << endl;
        } else {
            cout << "Takaki sekarang berada di: " << current->name << endl;
        }
    }
};

int main() {
    int n;
    cin >> n;

    DoublyLinkedList dll;

    while (n--) {
        string command;
        cin >> command;

        if (command == "ADD_STATION") {
            string name;
            cin >> name;
            dll.addStation(name);
        }
        else if (command == "INSERT_EMERGENCY") {
            int idx;
            string name;
            cin >> idx >> name;
            dll.insertEmergency(idx, name);
        }
        else if (command == "REMOVE_STATION") {
            string name;
            cin >> name;
            dll.removeStation(name);
        }
        else if (command == "MOVE_FORWARD") {
            dll.moveForward();
        }
        else if (command == "MOVE_BACKWARD") {
            dll.moveBackward();
        }
        else if (command == "WHERE_AM_I") {
            dll.whereAmI();
        }
    }

    return 0;
}