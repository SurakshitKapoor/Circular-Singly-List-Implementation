#include<iostream>
using namespace std;

struct node {
    int data;
    node *next;
    node(int data) {
        this->data = data;
        next = NULL;
    }
};

void insertAtEnd(struct node *&head, int data) {
    struct node *newNode = new node(data);
    if(head == NULL) {
        head = newNode;
        newNode->next = head;
    }
    else {
        struct node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;   
    }
    cout << newNode->data << " is inserted \n";
}

void printLinkedList(struct node *&head) {
    if(head == NULL) {
        cout << "No node is here !" << "\n";
        return;
    }
    else {
        struct node *temp = head;
        cout << "The Linked List is :-" << endl;
        while (temp->next != head)
        {
            cout << temp->data << "\t";
            temp = temp->next;
        }
        cout << temp->data << "\n";
    }
}
 
int main() {
    cout << "Traversal in circular singly linked list :-\n";
    struct node *head = NULL;

    insertAtEnd(head, 11);
    insertAtEnd(head, 12);
    insertAtEnd(head, 13);
    insertAtEnd(head, 14);

    printLinkedList(head);
}