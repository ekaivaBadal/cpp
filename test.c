#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAtBeginning(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void insertAtLast(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL; 

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    struct Node* temp = *head_ref;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = new_node;
}

void deleteNode(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref;
    struct Node* prev = NULL;

    // Agar head hi wo node hai jo delete karna hai
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;  // Head ko next node bana do
        free(temp);              // Purana head free kar do
        return;
    }

    // Find the node jisko delete karna hai (value match karna hai)
    while (temp != NULL && temp->data != key) {
        prev = temp;             // Previous node track karo
        temp = temp->next;       // Aage badho
    }

    // Agar key list me nahi mili
    if (temp == NULL) return;

    // Node mil gaya, ab prev ke next ko temp ke next se link karo
    prev->next = temp->next;

    // Delete karne ke liye memory free karo
    free(temp);
}





void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL; 

    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);
    insertAtBeginning(&head, 40);

    insertAtLast(&head,50);
    deleteNode(&head,50);
    printf("Linked list: ");
    printList(head);

    return 0;
}
