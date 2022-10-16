#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node* link;
};
void _addatbeg(node**, int);
void _append(node**, int);
void _addafter(node*, int, int);
void _delete(node**, int);
void _display(node* q)
{
    while (q != NULL)
    {
        cout << q->data << " ";
        q = q->link;
    }
    cout << endl;
}
void _append(node** ptr, int a) {
    node* ctner = new node();
    ctner->data = a;
    ctner->link = NULL;
    if (*ptr == NULL) {
        (*ptr = ctner);
        return;
    }
    node* pt2 = *ptr;
    while (pt2->link != NULL) {
        pt2 = pt2->link;
    }
    pt2->link = ctner;
}
void _addatbeg(node** ptr, int a) {
    node* ctner = new node();
    ctner->data = a;
    ctner->link = *ptr;
    *ptr = ctner;
}
void _addafter(node* ptr, int idx, int a) {
    node* ctner = new node();
    ctner->data = a;
    ctner->link = NULL;
    node* ptr2 = ptr;
    for (int i = 0; i < idx; i++) {
        if (ptr2 == NULL) {
            ptr2 = ctner;
            return;
        }
        else {
            ptr2 = ptr2->link;
        }
    }
    node* ptr3 = ptr2->link;
    ptr2->link = ctner;
    ctner->link = ptr3;
}
int _count(node* ptr) {
    node* ptr2 = ptr;
    int idx = 0;
    while (ptr2 != NULL) {
        idx++;
        ptr2 = ptr2->link;
    }
    return idx;
}
void _delete(node** ptr, int a) {
    node* ptr2 = *ptr;
    while (ptr2->link!=NULL) {
        node* ptr4 = ptr2;
        if (ptr2->link->data != a) {
            ptr2 = ptr2->link;
        }
        if (ptr2->link == NULL && ptr2->data != a) {
            return;
        }
        else if (ptr2->link == NULL && ptr2->data == a) {
            ptr4->link = NULL;
            return;
        }
        else if (ptr2->link->data == a) {
            node* ptr3 = ptr2;
            ptr3 = ptr3->link->link;
            delete ptr2->link;
            ptr2->link = ptr3;
        }
    }
}
int mainlinklist()
{
    node* head;
    head = NULL;

    _append(&head, 1);
    _append(&head, 2);
    _append(&head, 3);
    _append(&head, 4);
    _append(&head, 17);

    _display(head);

    _addatbeg(&head, 999);
    _addatbeg(&head, 888);
    _addatbeg(&head, 777);

    _display(head);

    _addafter(head, 7, 0);
    _addafter(head, 2, 1);
    _addafter(head, 1, 99);

    _display(head);

    cout << "No. of element in the Linked List = " << _count(head) << endl;

    _delete(&head, 888);
    _delete(&head, 1);
    _delete(&head, 10);

    _display(head);

    cout << "No. of element in the Linked List = " << _count(head) << endl;

    return 0;
}