#include <stdio.h>
#define MAX 5

int STACK[MAX];
int top = -1;

void push(int ITEM){
    if(top == MAX - 1){ 
        printf("Stack Overflow! Cannot add %d\n", ITEM);
    } else {
        top = top + 1;
        STACK[top] = ITEM;
        printf("%d added to the stack\n", ITEM);
    }
}

int pop() {
    if(top == -1) {  
        printf("Stack Underflow! Nothing to pop\n");
        return -1;  
    } else {
        int ITEM = STACK[top];
        top = top - 1;
        printf("%d popped from the stack\n", ITEM);
        return ITEM;
    }
}

void display() {
    if(top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack contents from top to bottom:\n");
        for(int i = top; i >= 0; i--) {
            printf("%d\n", STACK[i]);
        }
    }
}

int main() {
    push(30);
    push(40);
    push(50);
    push(60);
    push(70);
    push(80); 

    display();

    pop();
    pop();

    display();

    return 0;
}
