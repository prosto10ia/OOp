#pragma once

#include <iostream>
#include <cmath>
#include <type_traits>

template <typename T>
struct Node {
    T data;
    Node* next;
};

template <typename T>
class Iterator {
private:
    Node<T>* ptr;

public:
    T operator*();
    Iterator<T>& operator++();
    Iterator<T>  operator++(int);
    bool operator==(const Iterator<T>& s);
    bool operator!=(const Iterator<T>& s);

    Iterator(Node<T>* head) : ptr(head) {}
};

template <typename T>
class List {
public:
    Node<T>* head;

    void add(T data);
    void delite(T data);
    Iterator<T> begin();
    Iterator<T> end();

    List(Node<T>* node) : head(node) {}
    List() : head(nullptr) {}
};

 void strOut();
