#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

void addAfter(Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        cout << "The given previous node cannot be NULL" << endl;
        return;
    }

    Node* new_node = new Node();
    new_node->data = new_data;

    new_node->next = prev_node->next;
    prev_node->next = new_node;

    new_node->prev = prev_node;

    if (new_node->next != NULL)
        new_node->next->prev = new_node;
}

void deleteNode(Node** head_ref, Node* del) {
    if (*head_ref == NULL || del == NULL) {
        return;
    }

    if (*head_ref == del) {
        *head_ref = del->next;
    }

    if (del->next != NULL) {
        del->next->prev = del->prev;
    }

    if (del->prev != NULL) {
        del->prev->next = del->next;
    }

    delete del;
}

int main() {
    Node* head = NULL;


    Node* firstNode = new Node();
    Node* secondNode = new Node();
    Node* thirdNode = new Node();

    firstNode->data = 61;
    secondNode->data = 62;
    thirdNode->data = 65;



    head = firstNode;
    firstNode->next = secondNode;
    secondNode->prev = firstNode;
    secondNode->next = thirdNode;
    thirdNode->prev = secondNode;


    addAfter(secondNode, 53);

    Node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }


    deleteNode(&head, thirdNode);


    current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}

