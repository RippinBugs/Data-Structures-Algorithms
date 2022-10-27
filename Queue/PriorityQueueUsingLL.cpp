#include<bits/stdc++.h>
using namespace std;

struct node{
    char data;
    int priority;
    struct node *next;
}*front = NULL;

void insert(char val, int pri){
    struct node *temp = new node;
    if(temp == NULL){
        printf("Heap is full thus queue is full\n");
    }
    else{
        temp->data = val;
        temp->priority = pri;
        if(front == NULL || pri < front->priority){
            temp->next = front;
            front = temp;
        }
        else{
            struct node *p = front;
            //whenever the priority becomes smaller than the next node's priority the condition stops
            //in other words the loop continues till it finds priority is smaller than the next node's priority 
            while(p->next != NULL && pri >= p->next->priority){
                p = p->next;
            }
            temp->next = p->next;
            p->next = temp;
        }
    }
}
char Delete(){
    char x = '\0';
    if(front == NULL){
        printf("no items to dequeue\n");
    }
    else{
        struct node *temp = front;
        x = temp->data;
        front = front->next;
        delete temp;
    }
    return x;
}
void display(){
    struct node *p = front;
    while(p){
        printf("%c  %d\n",p->data,p->priority);
        p = p->next;
    }
}
int main(){
    insert('a',3);
    insert('b',7);
    insert('c',1);
    insert('d',2);
    display();
    Delete();
    cout<<"after deleting one element"<<endl;
    display();
    return 0;
}