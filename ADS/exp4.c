#include <stdio.h>
#define MAX 5

int queue[MAX]
int front  = -1,rear = -1;

void insert(int ITEM){
    if(front == -1){
        front = 0;
        rear++;
        queue[rear] = ITEM;
    }
}

void delete(){
    if(front != -1){
        int deletedValue =  queue[front];
        front++;
        if(front > rear){
            front =-1
        }
    }
}
int main(){

    return 0;
}