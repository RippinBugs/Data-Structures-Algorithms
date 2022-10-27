//queue using two stacks where the stacks are implemented using Linked lists.
//probably the worst code I've ever written so far. Basically it's hard coded xD
#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node* next;
}*top1=NULL,*top2=NULL;

bool isEmpty(struct node *stk){
    if(stk == NULL)
        return 1;
    else
        return 0;
}

void push1(int val){
    struct node *temp = new node;
    if(!temp){
        printf("stack overflow\n");
    }
    else{
        temp->data = val;
        temp->next =top1;
        top1 = temp;
    }
}
void push2(int val){
    struct node *temp = new node;
    if(!temp){
        printf("stack overflow\n");
    }
    else{
        temp->data = val;
        temp->next =top2;
        top2 = temp;
    }
}

void enqueue(int val){
    push1(val);
}
int pop1(){
    int x = -1;
    if(top1 == NULL){
        printf("Stack underflow\n");
    }
    else{
        struct node *temp = top1;
        x = temp->data;
        top1 = top1->next;
        temp->next = NULL;
        delete temp;
    }

    //printf("popped up value is %d\n",x);
    return x;
}

int pop2(){
    int x;
    if(top2 == NULL){
        printf("Stack underflow\n");
        return 0;
    }
    else{
        struct node *temp = top2;
        x = temp->data;
        top2 = top2->next;
        temp->next = NULL;
        delete temp;
    }

    //printf("popped up value is %d\n",x);
    return x;
}

void dequeue(){
    if(isEmpty(top2)){
        if(isEmpty(top1)){
            printf("queue is empty\n");
            return ;
        }
        else{
            while(!isEmpty(top1)){
                push2(pop1());
            }
        }
    }
    printf("popped up value is %d\n",pop2());
}

void display(struct node *p){
    if(p == NULL){
        printf("empty\n");
    }
    while(p){
        printf("%d\n",p->data);
        p = p->next;
    }
}
int main(){
    
    enqueue(5);
    enqueue(10);
    enqueue(20);
    enqueue(12);
    display(top1);
    dequeue();
    dequeue();
    cout<<endl;
    display(top2);
    enqueue(111);
    enqueue(222);
    cout<<endl;
    display(top1);
    dequeue();
    cout<<endl;
    display(top2);
    dequeue();
    dequeue();
    cout<<endl;
    display(top1);
    cout<<endl;
    display(top2);
    return 0;
}