#include <iostream>
using namespace std;

class iList
{
public:
    iList() : Head(NULL), Tail(NULL) {}
    void add(int value);
    void show();
    ~iList();

private:
    void sort();
    struct Node
    {
        int x;
        Node* Next, * Prev;
    };

    Node* Head, * Tail;
};



void iList::add(int value)
{
    Node* temp = new Node;
    temp->x = value;
    temp->Next = NULL;

    if (!Head) {
        temp->Prev = NULL;
        Head = Tail = temp;
    }
    else {
        temp->Prev = Tail;
        Tail->Next = temp;
        Tail = temp;
    }
    sort();
}

void iList::show()
{
    Node* temp = Head;
    while (temp) {
        cout << temp->x << '\t';
        temp = temp->Next;
    }
}

void iList::sort()
{
    Node* left = Head;
    Node* right = Head->Next;

    Node* temp = new Node;

    while (left->Next) {
        while (right) {
            if ((left->x) < (right->x)) {
                temp->x = left->x;
                left->x = right->x;
                right->x = temp->x;
            }
            right = right->Next;
        }
        left = left->Next;
        right = left->Next;
    }
}

iList::~iList()
{
    while (Head)
    {
        Tail = Head->Next;
        delete Head;
        Head = Tail;
    }
}

int main()
{
    iList ilst;

    while (true)
    {
        cout << "input number -> ";
        int a;
        cin >> a;
        ilst.add(a);
        ilst.show();
        cout << "1-Add, 2-quick -> ";
        cin >> a;
        if (a == 2) break;

    }
}

