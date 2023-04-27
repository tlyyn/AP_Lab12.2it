#include <iostream>

struct Elem {
    int info;
    Elem* link;
};

int Count(Elem* L) {
    int k = 0;
    while (L != NULL) {
        k++;
        L = L->link;
    }
    return k;
}

void SortList(Elem*& L) {
    int n = Count(L);
    if (n <= 1) {
        return;
    }
    for (int i = 0; i < n - 1; i++) {
        Elem* p = L;
        for (int j = 0; j < n - i - 1; j++) {
            if (p->info > p->link->info) {
                int tmp = p->info;
                p->info = p->link->info;
                p->link->info = tmp;
            }
            p = p->link;
        }
    }
}

void PrintList(Elem* L) {
    while (L != NULL) {
        std::cout << L->info << " ";
        L = L->link;
    }
    std::cout << std::endl;
}

void AddToList(Elem*& L, int value) {
    Elem* newElem = new Elem;
    newElem->info = value;
    newElem->link = NULL;

    if (L == NULL) {
        L = newElem;
    }
    else {
        Elem* p = L;
        while (p->link != NULL) {
            p = p->link;
        }
        p->link = newElem;
    }
}

int main() {
    Elem* L = NULL;
    AddToList(L, 6);
    AddToList(L, 2);
    AddToList(L, 8);
    AddToList(L, 1);
    AddToList(L, 9);
    AddToList(L, 3);
    std::cout << "Original List: ";
    PrintList(L);
    SortList(L);
    std::cout << "Sorted List: ";
    PrintList(L);
    return 0;
}
