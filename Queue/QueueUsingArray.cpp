//Queue is a logical data structure which follows the order FIFO. First In First Out

#include<bits/stdc++.h>
using namespace std;

struct queue_{
    int size;
    int front;
    int rear;
    int *q;
};

void enqueue(struct queue_ *qu,int val){
    if((qu->size - 1) == qu->rear)
        printf("Queue is full\n");
    else{
        qu->rear++;
        qu->q[qu->rear] = val;
    }
}

int dequeue(struct queue_ *qu){
    int x = -1;
    if(qu->front == qu->rear)
        printf("Queue is empty\n");
    else{
        qu->front++;
        x = qu->q[qu->front];
        qu->front = -1; // deleting the front element by making it's value as -1
    }
    return x;
}
void display(struct queue_ *qu){
    for(int i = 0; i <= qu->rear; i++){
        printf("%d\n",qu->q[i]);
    }
}
int main(){
    struct queue_ Q;
    Q.front = Q.rear = -1;
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