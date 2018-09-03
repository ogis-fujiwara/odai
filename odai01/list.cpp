#include <iostream>
using namespace std;

class Node {
public:
    Node* next = nullptr;
    int value = 0;
    Node(int v) {
        value = v;        
    }
};

class Iterator {
    Node* current;
public:
    Iterator(Node* n) {
        current = n;
    }
    void next() {
        current = current->next;
    }
    void removeNext() {
        auto next = current->next;
        current->next = next->next;
        delete next;
    }
    Node* get() {
        return current;
    }
};

class List {
    Node* first = nullptr;
    Iterator* it = nullptr;
public:
    ~List() {
        while (first != nullptr) {
            removeFirst();
        }
        if (it != nullptr) {
            delete it;
        }
    }
    void add(Node* newNode) {
        if (first == nullptr) {
            first = newNode;
        } else {
            auto last = getLast();
            last->next = newNode;
        }
    };
    Node* getFirst() {
        return first;
    }
    void removeFirst() {
        if (first != nullptr) {
            auto next = first->next;
            delete first;
            first = next;
        }
    };
    void removeNext(Node* prev) {
        auto target = prev->next;
        if (target != nullptr) {
            prev->next = target->next;
            delete target;
        }
    };
    void insertFirst(Node* newNode) {
        auto np = first;
        first = newNode;
        first->next = np;
    }
    void insertNext(Node* prev, Node* newNode) {
        auto currentNext = prev->next;
        prev->next = newNode;
        prev->next->next = currentNext;
    }
    Node* getLast() {
        auto n = first;
        if (n == nullptr) {
            return n;
        }
        while (n->next != nullptr) {
            n = n->next;
        }
        return n;
    }
    Iterator* iterator() {
        if (it != nullptr) {
            delete it;
        }
        it = new Iterator(first);
        return it;
    }
};

void outputList(List* l) {
    auto it = l->iterator();
    for (auto it = l->iterator(); it->get() != nullptr; it->next()) {
        cout << it->get()->value;
        cout << "->";
    }
    cout << endl;
}

int main() {
    List list;
    for (int i = 0; i < 10; i++) {
        list.add(new Node(i));
    }

    outputList(&list);
    list.removeFirst();
    outputList(&list);
    auto n = list.getFirst()->next->next->next->next;
    cout << n->value << endl;
    list.removeNext(n);
    outputList(&list);
    list.insertFirst(new Node(99));
    outputList(&list);
    n = list.getFirst()->next->next->next->next->next->next;
    cout << n->value << endl;
    list.insertNext(n, new Node(77));
    outputList(&list);
    list.removeNext(list.getFirst());
    outputList(&list);
    n = list.getLast();
    list.removeNext(n);
    outputList(&list);
    list.insertNext(n, new Node(123));
    outputList(&list);
    list.removeNext(n);
    outputList(&list);
    
    cout << "Iterator operation" << endl;
    auto it = list.iterator();
    it->next();
    cout << it->get()->value << endl;
    it->next();
    cout << it->get()->value << endl;
    it->removeNext();
    outputList(&list);
    
    return 0;
}