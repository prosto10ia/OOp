#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
};
//data, next

class Iterator {// foreach
private:
        Node* ptr;
        int number;

        bool isPrime(int num) {
            for (int i = 2; i <= sqrt(num); i++) {
                if (num % i == 0) {
                    return false;
                }
            }
            return true;
        }

public:
    int operator*() {
        return ptr->data;
    }

    Iterator& operator++() {//переопределение ++i
        if (ptr != nullptr) {
            ptr = ptr->next;

            if (ptr != nullptr && !isPrime(ptr->data))
                operator++();//не уверен что так но тут должна быть рекурсия

        }
        return *this;
    }

    Iterator operator++(int) {//переопределение i++
        Iterator last = *this; 
        operator++(); 
        return last;
    }

    bool operator==(const Iterator& s) { return (this->ptr == s.ptr); }
    bool operator!=(const Iterator& s) { return !(this->ptr == s.ptr); }

    Iterator(Node* head) {
        ptr = head;
    }

};

class List {
public:
    Node* head;

    void add(int data) {//просто в начало 
        
        if (this->head != nullptr) {

            Node* neew = new Node();
            neew->data = data;
            neew->next = head;
            head       = neew;
        }
        else {
            head       = new Node();
            head->data = data;
        }
    }

    void delite(int data) {
        Node* last;
        while ((head->data != data) && (head != nullptr)) {
            last = head;
            head = head->next;
        }
        last = head->next;
        delete head;
    }

    Iterator begin() { return Iterator(head); }
    Iterator end() {
        Node* sh = head;
        while (sh != nullptr) { sh = sh->next; }
        return sh;
    }


    List(Node* node) {
        head = node;
    }

    List() {
        head = nullptr;
    }

};




int main()
{
    List list;
    list.add(3);//теряеться

    list.add(17);
    list.add(2);
    list.add(-3);//юхуу
      
    for (auto i = list.begin(); i != list.end(); ++i) {
        cout << *i << endl;
    }


    return 0;
}