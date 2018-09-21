#ifndef LIST_HPP
#define LIST_HPP

template <typename T>
class Node {
public:
    Node* next;
    T value;
    Node(T value);
};

template <typename T>
class Iterator {
    Node<T> *current;
public:
    Iterator(Node<T> *n);
    void next();
    void removeNext();
    T get();
    bool operator!=(Iterator<T> it);
};

template <class T> 
class List {
    Node<T>* first = nullptr;
    Iterator<T>* it = nullptr; // 使えるイテレータはひとつだけ
    Iterator<T>* it_end = new Iterator<T>(nullptr);
public:
    ~List();
    void addFirst(T v);
    void removeFirst();
    T getFirst();
    Iterator<T> begin();
    Iterator<T> end();
};

#endif // LIST_HPP