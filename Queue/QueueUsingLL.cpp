#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node *next;
}*front = NULL,*rear = NULL;

void enqueue(int val){
    struct node *temp = new node;
    if(temp == NULL){
        printf("heap is full thus queue is full\n");
    }
    else{
        temp->data = val;
        temp->next = NULL;
        if(front == NULL){
            front = rear = temp;
        }
        else{
            rear->next = temp;
            rear = temp;
        }
    } 
}

int dequeue(){
    struct node *p = front;
    int x = -1;
    if(front == NULL){
        printf("queue is empty\n");
    }
    else{
        x = p->data;
        front = front->next;
        delete p;
    }
    return x;
}

void display(struct node *p){
    if(p == NULL){
        printf("empty \n");
        return ;
    }
    printf("printing the data in the queue\n");
    while(p){
        printf("%d\n",p->data);
        p = p->next;
    }
}
int main(){
    display(front);
    enqueue(1);
    enqueue(4);
    enqueue(7);
    display(front);
    dequeue();
    display(front);
    dequeue();
    dequeue();
    display(front);
    return 0;
}