#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

// push
int push(int item){
    if(top == MAX -1){
    printf("Stack Overflow! Cannot insert %d\n", item);
    }else{
        top++;
        stack[top] = item;
        printf("%d pushed into the stack \n",item);
    }
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow! No element to pop\n");
    } else {
        printf("%d popped from stack\n", stack[top]);
        top--;
    }
}

void peek() {
    if (top == -1) {
        printf("Stack is empty!\n");
    } else {
        printf("Top element is: %d\n", stack[top]);
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty!\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main(){

    push(10);
    push(20);
    push(30);
    push(40);
    push(50);

    peek();
    pop();
    peek();
    display();
    return 0;
}