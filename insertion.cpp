#include<iostream>
using namespace std;

struct node
{
    int data;
    node*next;
    
    node(int data) {
        this->data = data;
        next = NULL;
    }
};

void insertAtEnd(struct node *&head, int data) {

    struct node *newNode = new node(data);
    if(head == NULL){
        head = newNode;
        newNode->next = head;
    }
    else {
        struct node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next ;
        }
        temp->next = newNode;  
        newNode->next = head;
    }
    cout << newNode->data << " is inserted" << endl;
}

void insertAtBeginning(struct node *&head, int data) {
    struct node *newNode = new node(data);

    if(head == NULL) {
        head = newNode;
        newNode->next = head;
    }
    else    //update the last node as well with next as newNode; 
    {
        struct node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
    cout << newNode->data << " is inserted " << "\n";
}

void insertAtPosition(struct node *&head, int data, int position) {
    struct node *newNode = new node(data);
    if(position == 1) {
        insertAtBeginning(head, data);
    }
    else {
        struct node *temp = head;
        int count = 1;
        while (count < position-1)
        {
            temp = temp->next;
            count++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    cout << newNode->data << " is inserted at " << position << " position \n";
    
}

void printLinkedList(struct node *head) {
    if(head == NULL){
        cout << "No node is here !" << endl;
        return;
    }
    else {
        struct node *temp = head;
        while (temp->next != head)
        {
            cout << temp->data << "\t" ;
            temp = temp->next;
        }
        cout << temp->data ;
        cout << "\n";
    }
}

int main() {
    cout << "Insertion in circular singly linked list :-" << endl;
    struct node *head = NULL;

    insertAtEnd(head, 11);
    insertAtEnd(head, 12);
    insertAtEnd(head, 13);
    insertAtEnd(head, 14);

    insertAtBeginning(head, 15);
    insertAtBeginning(head, 17);

    insertAtPosition(head, 20, 5);
    printLinkedList(head);
}