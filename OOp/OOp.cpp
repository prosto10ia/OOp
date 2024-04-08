#include <iostream>
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

        bool isPrime(T num) {
            if (!std::is_integral<T>::value) return true;
            int numi = static_cast<int>(num);
            for (int i = 2; i <= sqrt(numi); i++) {
                if (numi % i == 0) {
                    return false;
                }
            }
            return true;
        }

public:
    T operator*() {
        return ptr->data;
    }

    Iterator<T>& operator++() {//переопределение ++i
        if (ptr != nullptr) {
            ptr = ptr->next;

            if (ptr != nullptr && !isPrime(ptr->data))
                operator++();//не уверен что так но тут должна быть рекурсия

        }
        return *this;
    }

    Iterator<T> operator++(int) {//переопределение i++
        Iterator<T> last = *this;
        operator++(); 
        return last;
    }

    bool operator==(const Iterator<T>& s) { return (this->ptr == s.ptr); }
    bool operator!=(const Iterator<T>& s) { return !(this->ptr == s.ptr); }

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
            head       = neew;
        }
        else {
            head       = new Node<T>();
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



class naprimerStroka {
public:
    static void strOut() {
        List<char> stroka;
        stroka.add('i');
        stroka.add('m');
        stroka.add(' ');
        stroka.add('s');
        stroka.add('t');
        stroka.add('r');

        for (auto i = stroka.begin(); i != stroka.end(); ++i) {
            cout << *i << endl;
        }
    }
};



int main()
{
    List<float> list;
    list.add(0.33f);//теряеться

    list.add(0.63f);
    list.add(1.3f);
    list.add(-3.6f);//юхуу
      
    for (auto i = list.begin(); i != list.end(); ++i) {
        cout << *i << endl;
    }


    naprimerStroka::strOut();

    return 0;
}



