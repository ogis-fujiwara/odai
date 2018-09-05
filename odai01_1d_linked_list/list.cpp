#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    Node* next = nullptr;
    T value;
    Node(T v) {
        value = v;        
    }
};

template <typename T>
class Iterator {
    Node<T> *current;
public:
    Iterator(Node<T> *n) {
        current = n;
    }
    void next() {
        if (current != nullptr) {
            current = current->next;
        }
    }
    void removeNext() {
        if (current->next != nullptr) {
            auto next = current->next;
            current->next = next->next;
            delete next;
        }
    }
    T get() {
        return current->value;
    }
    bool operator!=(Node<T> *n) {
        return (current != n);
    }
};

template <class T> class List {
    Node<T>* first = nullptr;
    Iterator<T>* it = nullptr; // 使えるイテレータはひとつだけ
public:
    Node<T>* end = nullptr;
    ~List() {
        while (first != nullptr) {
            removeFirst();
        }
        if (it != nullptr) {
            delete it;
        }
    }
    void addFirst(T v) {
        auto n = new Node<T>(v);
        if (first == nullptr) {
            first = n;
        } else {
            n->next = first;
            first = n;
        }
    }
    void removeFirst() {
        if (first != nullptr) {
            auto next = first->next;
            delete first;
            first = next;
        }
    }
    T getFirst() {
        return first->value;
    }
    Iterator<T> getIterator() {
        if (it != nullptr) {
            delete it;
        }
        it = new Iterator<T>(first);
        return *it;
    }
};
