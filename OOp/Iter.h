#pragma once 

#include <iostream>
#include <cmath>
#include <type_traits>

using namespace std;

template <typename T>
struct Node
{
    T data;
    Node* next;
};
//data, next


template <typename T>
class Iterator {// foreach
private:
    Node<T>* ptr;

public:
    T operator*() {
        return ptr->data;
    }

    Iterator<T>& operator++() {//переопределение ++i
        if (ptr != nullptr) {
            ptr = ptr->next;
        }
        return *this;
    }

    Iterator<T> operator++(int) {//переопределение i++
        Iterator<T> last = *this;
        operator++();
        return last;
    }

    bool operator == (const Iterator<T>& s) { return (this->ptr == s.ptr); }
    bool operator != (const Iterator<T>& s) { return !(this->ptr == s.ptr); }

    Iterator(Node<T>* head) {
        ptr = head;
    }

};

template <typename T>
class List {
public:
    Node<T>* head;

    void add(T data) {//просто в начало 

        if (this->head != nullptr) {

            Node<T>* neew = new Node<T>();
            neew->data = data;
            neew->next = head;
            head = neew;
        }
        else {
            head = new Node<T>();
            head->data = data;
        }
    }

    void delite(T data) {
        Node<T>* last;
        while ((head->data != data) && (head != nullptr)) {
            last = head;
            head = head->next;
        }
        last = head->next;
        delete head;
    }

    Iterator<T> begin() { return Iterator<T>(head); }
    Iterator<T> end() {
        Node<T>* sh = head;
        while (sh != nullptr) { sh = sh->next; }
        return sh;
    }


    List(Node<T>* node) {
        head = node;
    }

    List() {
        head = nullptr;
    }

};


