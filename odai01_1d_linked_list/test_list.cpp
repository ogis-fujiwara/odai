#include <iostream>
#include "./list.hpp"

using namespace std;

template <typename T>
void outputList(List<T>* l) {
    for (auto it = l->begin(); it != l->end() ; it.next()) {
        cout << it.get() << "->";
    }
    cout << endl;
}
int main() {
    List<int> list;
    for (int i = 0; i < 10; i++) {
        // リストの先頭に要素を追加
        list.addFirst(i);
    }
    outputList(&list);

    // リストの先頭の要素を削除
    list.removeFirst();
    cout << list.getFirst() << endl;

    outputList(&list);
        
    for (auto it = list.begin(); it != list.end() ; it.next()) {
        if (it.get() == 5) {
            // イテレータを用いて、任意の要素を削除
            // ここでは、5の直後
            it.removeNext();
        }
    }

    outputList(&list);
    
    List<char> clist;
    for (char c = 'a'; c < 'z'; c++) {
        clist.addFirst(c);
    }
    outputList(&clist);

    return 0;
}