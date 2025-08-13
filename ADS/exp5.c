#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
}

int main(){

    struct Node* n1 = createNode(10);
    printf("Node created with data: %d\n", n1->data);

    return 0;
}