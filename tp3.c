#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Product {
    int ID;
    char Name[20];
    int Price;
} Product;

typedef struct Node {
    Product Prod;
    struct Node *next;
} Node;

Node* createEmptyList() { return NULL; }

int isEmpty(Node* tail) { return (tail == NULL); }

Node* createNode(Product p) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->Prod = p;
    newNode->next = NULL;
    return newNode;
}

Node* insertAtBeginning(Node* tail, Product p) {
    Node* newNode = createNode(p);
    if (tail == NULL) {
        newNode->next = newNode;
        return newNode;
    }
    newNode->next = tail->next;
    tail->next = newNode;
    return tail;
}

Node* insertAtEnd(Node* tail, Product p) {
    Node* newNode = createNode(p);
    if (tail == NULL) {
        newNode->next = newNode;
        return newNode;
    }
    newNode->next = tail->next;
    tail->next = newNode;
    tail = newNode;
    return tail;
}

void displayProducts(Node* tail) {
    if (tail == NULL) {
        printf("list is empty.\n");
        return;
    }
    Node* head = tail->next;
    Node* p = head;
    do {
        printf("ID: %d, Name: %s, Price: %d\n",
               p->Prod.ID, p->Prod.Name, p->Prod.Price);
        p = p->next;
    } while (p != head);
}

int main() {
    Node* tail = createEmptyList();

    Product p1 = {1, "Keyboard", 25};
    tail = insertAtEnd(tail, p1);

    Product p2 = {2, "Mouse", 15};
    tail = insertAtBeginning(tail, p2);

    Product p3 = {3, "Monitor", 120};
    tail = insertAtEnd(tail, p3);

    Product p4 = {4, "printer", 120};
    tail = insertAtBeginning(tail, p4);

    displayProducts(tail);

    return 0;
}