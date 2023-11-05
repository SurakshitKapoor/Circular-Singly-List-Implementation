#include<iostream>
using namespace std;

struct node
{
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

void printLinkedList(struct node *head) {
    if(head == NULL) {
        cout << "No node is here !" << endl;
        return;
    }
    else {
        struct node *temp = head;
        while (temp->next != head)
        {
            cout << temp->data << "\t";
            temp = temp->next;
        }
        cout << temp->data << "\n";
    }
}

void deleteAtBeginning(struct node *&head) {
    if(head == NULL) {
        cout << "No node is here !" << endl;
        return;
    }  
    else if(head->next == head){
         delete head;
         head = NULL;
    } 
    else {
        struct node *temp = head;
        struct node *delNode = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        
        temp->next = head->next;
        head = head->next;

        delete delNode;
    }
}

void deleteAtEnd(struct node *&head) {
    if(head == NULL) {
        cout << "No node is here ! \n";
        return;
    }
    else if(head->next == head) {
        delete head;
        head = NULL;
    }
    else {
        struct node *temp = head;
        while (temp->next->next != head)
        {
            temp = temp->next;
        }
        struct node *delNode = temp->next;
        temp->next = head;
        delete delNode;
    }
}

void deleteAtPosition(struct node *&head, int position) {
    struct node *temp = head;
    if(position == 1) {
        deleteAtBeginning(head);
    }
    //when position at any between or at end node
    else {
        int count = 1;
        while (count < position-1)
        {
            temp = temp->next;
            count++;
        }
        struct node *delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;
    }
}
int main() {
    cout << "Deletion in circular singly linked list :-\n";
    struct node *head = NULL;
    insertAtEnd(head, 11);
    insertAtEnd(head, 12);
    insertAtEnd(head, 13);
    insertAtEnd(head, 14);
    insertAtEnd(head, 15);

    deleteAtBeginning(head);
    // deleteAtBeginning(head);
    // deleteAtBeginning(head);
    // deleteAtBeginning(head);
    // deleteAtBeginning(head);
    // deleteAtBeginning(head);
    
    deleteAtEnd(head);
    // deleteAtEnd(head);
    // deleteAtEnd(head);
    // deleteAtEnd(head);
    // deleteAtEnd(head);

    deleteAtPosition(head, 3);
    
    printLinkedList(head);
}