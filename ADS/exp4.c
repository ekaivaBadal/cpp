#include <stdio.h>
#define MAX 5

int queue[MAX];
int front  = -1;
int rear = -1;

void enqueue(int item){

if (rear == MAX - 1) {
        printf("Queue Overflow! Cannot insert %d\n", item);
    } else {
        if (front == -1) front = 0;  // first element
        rear++;
        queue[rear] = item;
        printf("%d inserted into queue\n", item);
    }
}

// Dequeue (Delete)
void dequeue() {
    if (front == -1) {
        printf("Queue Underflow! No element to delete\n");
    } else {
        printf("%d deleted from queue\n", queue[front]);
        if (front == rear) {
            front = rear = -1;  // queue becomes empty  
        } else {
            front++;
        }
    }
}

// Peek (Front element)
void peek() {
    if (front == -1) {
        printf("Queue is empty!\n");
    } else {
        printf("Front element is: %d\n", queue[front]);
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}
int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    peek();
    dequeue();
    peek();
    display();
    return 0;
}