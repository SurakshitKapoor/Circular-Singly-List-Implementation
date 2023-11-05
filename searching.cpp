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
    cout << newNode->data << " is inserted\n";
}

void searchInLinkedList(struct node *&head, int data) {
    if(head == NULL) {
        cout << "No node is here !\n";
        return;
    }
    else {
        struct node *temp = head;
        int position = 1;
        while (temp->next != head)
        {
            if(temp->data == data) {
                cout << data << " is found at " << position << " position\n";
                return;
            }
            temp = temp->next;
            position ++;
        }
        if(temp->data == data) {
            cout << data << " is found at " << position << " position\n";
        }
    }
}

void printLinkedList(struct node *head) {
    if(head == NULL) {
        cout << "No node is here ! \n";
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
int main() {
    cout << "Searching in circular singly linked list :- \n";

    struct node *head = NULL;
    insertAtEnd(head, 14);
    insertAtEnd(head, 16);
    insertAtEnd(head, 23);
    insertAtEnd(head, 57);
    insertAtEnd(head, 92);

    printLinkedList(head);

    searchInLinkedList(head, 14);
    searchInLinkedList(head, 92);
}