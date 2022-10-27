//The best procedure to use queue as an array.
//uses mod operator to make this circular.
//in this way free spaces can be used easily.

#include<bits/stdc++.h>
using namespace std;

struct queue_{
    int size;
    int front;
    int rear;
    int *q;
};

void enqueue(struct queue_ *qu,int val){
    if((qu->rear + 1) % qu->size == qu->front){
        printf("Queue is full\n");
    }
    else{
        qu->rear = (qu->rear+1) % qu->size;
        qu->q[qu->rear] = val;
    }
}

int dequeue(struct queue_ *qu){
    int x = -1;
    if(qu->rear == qu->front){
        printf("Queue is empty\n");
    }
    else{
        qu->front = (qu->front + 1) % qu->size;
        x = qu->q[qu->front];
    }
    return x;
}

void display(struct queue_ *qu){
    int i = qu->front + 1;
    // do while loop whenever the program is circular
    do{
        printf("%d\n",qu->q[i]);
        i = (i + 1) % qu->size;
    }while(i != (qu->rear + 1) % qu->size);
}

int main(){
    struct queue_ Q;
    Q.front = Q.rear = 0;
    printf("Enter the size of the queue: ");
    cin>>Q.size;
    Q.q = new int[Q.size];
    enqueue(&Q,12);
    enqueue(&Q,1);
    enqueue(&Q,2);
    enqueue(&Q,22);
    display(&Q);
    dequeue(&Q);
    dequeue(&Q);
    display(&Q);
    return 0;
}