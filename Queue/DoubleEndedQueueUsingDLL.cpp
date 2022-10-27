#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node* next;
    struct node *prev;
}*front = NULL, *rear = NULL;

void insertFront(int val){
    struct node *temp = new node;
    if(!temp){
        printf("Queue is full\n");
    }
    else{
        temp->data = val;
        if(front == NULL){
            temp->next = temp->prev = NULL;
            front = rear = temp;
        }
        else{
            temp->prev = NULL;
            temp->next = front;
            front->prev = temp;
            front = temp;
        }
    }
}
void insertRear(int val){
    struct node *temp = new node;
    if(!temp){
        printf("Queue is full\n");
    }
    else{
        temp->data = val;
        if(rear == NULL){
            temp->next = temp->prev = NULL;
            front = rear = temp;
        }
        else{
            temp->prev = rear;
            temp->next = NULL;
            rear->next = temp;
            rear = temp;
        }
    }
}
void DeleteFront(){
    if(front == NULL){
        printf("Queue is empty\n");
    }
    else{
        struct node *temp = front;
        front = front->next;
        if(front == NULL){
            rear = NULL;
        }
        else{
            front->prev = NULL;
        }
        delete temp;
    }   
}

void DeleteRear(){
    if(rear == NULL){
        printf("Queue is empty\n");
    }
    else{     
        struct node *temp = rear;
        rear = rear->prev;
        rear->next = NULL;
        if(rear == NULL){
             front = NULL;
        }
        else{
            rear->next = NULL;
        }  
        delete temp;       
    }
}

void display(){
    struct node *p = front;
    while(p){
        printf("%d\n",p->data);
        p = p->next;
    }
}
int main(){
    insertRear(12);
    insertRear(1);
    insertFront(22);
    insertFront(111);
    cout<<"display after insertion"<<endl;
    display();
    DeleteFront();
    DeleteRear();
    DeleteRear();
    cout<<"display after deletion"<<endl;
    display();
    DeleteFront();
    cout<<"another display"<<endl;
    //this will print nothing as there are no nodes inside the deque
    display();
    return 0;
}