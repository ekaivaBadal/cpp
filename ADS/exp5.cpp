#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;
void insertBegin(int value)
{

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL)
    {
        newNode->next = NULL;
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
    printf("✅ Inserted %d at the beginning.\n", value);
}

void insertEnd(int value)
{

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("✅ Inserted %d at the end.\n", value);
}

void deleteBegin()
{
    if (head == NULL)
    {
        printf("❌ List is Empty! Deletion is not possible.\n");
    }
    else
    {
        struct Node *temp = head;
        head = head->next;
        printf("🗑️ Deleted %d from the beginning.\n", temp->data);
        free(temp);
    }
}

void display()
{
    if (head == NULL)
    {
        printf("List is Empty!\n");
    }
    else
    {
        struct Node *temp = head;
        printf("Your list: ");
        while (temp != NULL)
        {
            printf("%d ---> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main()
{
   insertEnd(20);
   insertEnd(30);
   insertEnd(40);
   insertEnd(50);

    display();

    insertBegin(10);
    insertBegin(5);
    insertBegin(1);
    
    display();

    deleteBegin();
    display();
    deleteBegin();
    display();
    
    
return 0;
}
