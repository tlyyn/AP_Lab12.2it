#include <iostream>
using namespace std;

struct Elem {
    int info;
    Elem* link;
};

// generates a new list with values entered by the user from keyboard
Elem* generateList() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    Elem* head = nullptr;
    Elem* tail = nullptr;
    for (int i = 0; i < n; i++) {
        int x;
        cout << "Enter value for element " << i + 1 << ": ";
        cin >> x;
        Elem* p = new Elem;
        p->info = x;
        p->link = nullptr;
        if (head == nullptr) {
            head = tail = p;
        }
        else {
            tail->link = p;
            tail = p;
        }
    }
    return head;
}

// prints the values of all elements in a list
void printList(Elem* L) {
    while (L != nullptr) {
        cout << L->info << " ";
        L = L->link;
    }
    cout << endl;
}

// checks if a list is ordered in non-descending order
bool isNonDescending(Elem* L) {
    while (L != nullptr && L->link != nullptr) {
        if (L->info > L->link->info) {
            return false;
        }
        L = L->link;
    }
    return true;
}

// main program
int main() {
    Elem* L = generateList();
    cout << "List: ";
    printList(L);
    cout << "Is non-descending: " << boolalpha << isNonDescending(L) << endl;
    int x;
   
    return 0;
}
