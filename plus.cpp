#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int _data) : data(_data), next(nullptr) {}
};

struct List {
    Node* head;
    Node* tail;
    List() : head(nullptr), tail(nullptr) {}
    
    void print() const {
        if (head == nullptr) {
            cout << "Пустой лист";
            return;
        }

        Node* n = head;
        while (n) {
            cout << n->data<< " ";
            n = n->next;
        }
        cout << "\n\nhead: " << head->data;
        cout << "\ntail: " << tail->data;
        cout << endl;

    }



    void addlast(int _data) {
        Node* n = new Node(_data);

        if (head == nullptr) {
            head = n;
            tail = n;
            return;
        }

        tail->next = n;
        tail = n;
    }


    void addfirst(int _data) {
        Node* n = new Node(_data);

        if (head == nullptr) {
            head = n;
        };

        n->next = head;
        head = n;

    }

    void removefirst() {
        if (head == nullptr) {
            return;
        }
        Node* n = head;
        head = n->next;
    }

    void removelast() {
        if (head == nullptr) {
            return;
        }

        Node* n = head;
        while (n->next != tail) {
            n = n->next;
        }
        n->next = nullptr;
        delete tail;
        tail = n;

    }

    bool empty() const {
        return head == nullptr;
    }

    void removeall() {
        head = nullptr;
    }
};

int main()
{
    List l;
    l.addlast(1);
    l.addlast(2);
    l.addfirst(3);
    l.addfirst(-3);
    l.addlast(22);
    l.print();
    l.removefirst();
    l.print();
    l.removelast();
    l.print();
    cout << l.empty();
    return 0;
}


