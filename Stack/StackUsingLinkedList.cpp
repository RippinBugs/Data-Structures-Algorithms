#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *next;
}*top = NULL;

void push(int val){
    struct node *temp;
    temp = new node;
    if(!temp){
        printf("Stack overflow\n");
        return ;
    }
    temp->data = val;
    temp->next = top;
    top = temp;

}

int pop(){
    int x = -1;
    if(top == NULL){
        printf("Stack is empty from pop_fn\n");;
    }
    else{
        struct node *temp = top;
        x = top->data;
        top = top->next;
        delete temp;
    }
    return x;
}

int stackTop(){
    if(top){
        return top->data;
    }
    else
        return -1;

}
void isEmpty(){
    bool r = top?false:true;
    if(r){
        printf("The stack is empty\n");
    }
    else{
        printf("The stack is not empty\n");
    }
}
void isFull(){
    struct node *temp = new node;
    //when temp is positive that means the stack is not full
    //when temp is null that means the stack couldn't manage another node thus is full.
    bool r = temp?false:true;
    delete temp;
    if(r){
        printf("The stack is full\n");
    }
    else{
        printf("The stack is not full\n");
    }
}
int peek(int pos){
    struct node *p = top;
    for(int i = 0;i<pos-1 && pos;i++){
        p = p->next;
    }
    if(p){
        return p->data;
    }
    else
        return -1;
}
void Display(){
    struct node *p = top;
    int flag = 1;
    if(p == NULL){
        printf("The stack is empty\n");
        return ;
    }
    while(p){
        if(flag){
            printf("Displaying all the values of the stack\n");
            flag = 0;
        }
        printf("%d\n",p->data);
        p = p->next;
    }
}
int main(){
    
    isFull();
    isEmpty();
    push(10);
    push(12);
    push(2);
    push(16);
    Display();
    pop();
    Display();
    pop();
    pop();
    pop();
    Display();
    pop();
    Display();
    return 0;
}