//Rules
//For left to right associativity, out stack prec < in stack prec
//for right to left associativity, out stack prec > in stack prec.

#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node* next;
}*top = NULL;

int isOperand(char input){
    if (input >= 48 && input <= 57)
        return 1;
    return 0;
}
int isEmpty(){
    if(top == NULL)
        return 1;
    else
        return 0;
}
void push(char x){
    struct node *temp = new node;
    if(temp){
        temp->data = int(x) ;
        temp->next = top;
        top = temp;
    }
    else{
        printf("stack overflow\n");
    }
}
int pop(){
    if(top){
        struct node *temp = top;
        top = top->next;
        int val = temp->data;
        delete temp;
        return val;
    }
    else{
        return 0;
    }
}
void eval(char *exp){
    int i =0;
    //int len = strlen(exp);
    //char pfix[len+1];
    while(exp[i]!='\0'){
        if(isOperand(exp[i])){
            push(exp[i]-'0');
        }
        else{
            int y = pop();
            int x = pop();
            printf("%d %d\n",y,x);
            switch (exp[i])
            {
            case '+':
                push(x + y);
                break;
            case '-':
                push(x - y);
                break;
            case '/':
                push(x / y);
                break;
            case '*':
                push(x * y);
                break;
            case '^':
                push(pow(x,y));
                break;
            default:
                break;
            }
        }
        i++;
    }
    int output = pop();
    printf("evaluated value is %d\n",output);
    
}
int main(){
    char exp[100];
    cin>>exp;
    eval(exp);
    return 0;
}