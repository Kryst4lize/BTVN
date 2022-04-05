#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node* link;
};
void _addafter(node*, int, int);
void _addatbeg(node**, int);
void _append(node**, int);
void _display(node* q)
{
    while (q != NULL)
    {
        cout << q->data << " ";
        q = q->link;
    }
    cout << endl;
}
void _append(node** head, int b) 
{
    //create mid container to add
    node* ctner = new node();
    ctner->data = b;
    ctner->link = NULL;
    node* last = *head;
    if (*head == NULL) {
        (*head) = ctner;
        return;
    }
    while (last->link != NULL) {
        last = last->link;
    }
    last->link = ctner;
}
void _addatbeg(node** head, int b) {
    node* ctner = new node();
    ctner->data = b;
    ctner->link = *head;
    *head = ctner;
}
void _addafter(node* a, int idx, int val) {
    int index = 1;
    //container temp
    node* ctner2 = new node();
    ctner2->data = val;
    ctner2->link = NULL;
    //solving index
    node arr = *a; // copy of node a
    while (index <= idx && arr.link != NULL) {
        arr = *(arr).link;
    }
    if (arr.link != NULL) {
        ctner2->link = arr.link;
    }
}
int mainte16()
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

    return 0;
}