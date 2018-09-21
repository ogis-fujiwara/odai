#include "list.hpp"

template <typename T> 
template class Node<int>;


Node<T>::Node(T v) : next(nullptr), value(v) {};

template <typename T> Iterator<T>::Iterator(Node<T> *n) : current(n) {};

template <typename T> void Iterator<T>::next() {
    if (current != nullptr) {
        current = current->next;
    }
}
template <typename T>T Iterator<T>::get() {
    if (current != nullptr) {
        return current->value;
    } else {
        return nullptr;
    }
}
bool Iterator<T>::operator!=(Iterator<T> it) {
    return (current->value != it.get());
}

template <typename T>List<T>::~List() {
    while (first != nullptr) {
        removeFirst();
    }
    if (it != nullptr) {
        delete it;
    }
    delete it_end;
}
List<T>::addFirst(T v) {
    auto n = new Node<T>(v);
    if (first == nullptr) {
        first = n;
    } else {
        n->next = first;
        first = n;
    }
}
List<T>::removeFirst() {
    if (first != nullptr) {
        auto next = first->next;
        delete first;
        first = next;
    }
}
T List<T>::getFirst() {
    if (first != nullptr) {
        return first->value;
    } else {
        return nullptr
    }
}
Iterator<T> List<T>::begin() {
    if (it != nullptr) {
        delete it;
    }
    it = new Iterator<T>(first);
    return *it;
}
Iterator<T> List<T>::end() {
    return it_end;
}