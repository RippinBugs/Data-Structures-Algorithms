#include<bits/stdc++.h>
using namespace std;

struct node{
    char data;
    struct node *next;
}*top = NULL;

bool isEmpty(){
    if(top == NULL){
        return true;
    }
    else
        return false;
}

bool isFull(){
    struct node *t = new node;
    if(!t){
       return true;
    }
    else{
        delete t;
        return false;
    }
}
void push(char data){
    struct node *temp = new node;
    if(temp){
        temp->data  = data;
        temp->next = top;
        top = temp;
    }
    else{
        printf("Stack is full\n");
    }
}

void pop(){
    struct node *temp = top;
    top = top->next;
    delete temp;
}

bool isBalanced(char *exp){
    for(int i = 0;exp[i]!='\0';i++){
        if(exp[i] == '('){
            push(exp[i]);
        }
        else if(exp[i] == ')'){
            if(isEmpty()){
                return false;
            }
            else
                pop();
        }
    }
    if(isEmpty()){
        return true;
    }
    else
        return false;
}
int main(){
    char exp[100];
    cin>>exp;
    if(isBalanced(exp)){
        printf("balanced\n");
    }
    else{
        printf("not balanced\n");
    }
    return 0;
}