//Rules
//For left to right associativity, out stack prec < in stack prec
//for right to left associativity, out stack prec > in stack prec.

#include<bits/stdc++.h>
using namespace std;
struct node{
    char data;
    struct node* next;
}*top = NULL;

char stackTop(){
    if(top == NULL){
        return '\0';
    }
    else
        return top->data;
}
//when the operator is outside the stack
int outPrec(char input)
{
    switch (input) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '%':
        case '/':
            return 3;
        case '^':
            return 6;
        case '(':
            return 7;
        case ')':
            return 0;
    }
    return 0;
}

//when the operator is inside the stack
int inPrec(char input)
{
    switch (input) {
        case '+':
        case '-':
            return 2;
        case '*':
        case '%':
        case '/':
            return 4;
        case '^':
            return 5;
        case '(':
            return 0;
        case '\0': // when there is no operator at stack top.
            return -1;
        //we don't have a case for ')' because we will never push it to the stack.
        // so there's no point of in stack prec for ')'
    }
    return 0;
}
int isOperand(char input){
      if (input >= 65 && input <= 90
        || input >= 97 && input <= 122)
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
        temp->data = x;
        temp->next = top;
        top = temp;
    }
    else{
        printf("stack overflow\n");
    }
}
char pop(){
    if(top){
        struct node *temp = top;
        top = top->next;
        char ch = temp->data;
        delete temp;
        return ch;
    }
    else{
        return '\0';
    }
}
void infxToPostfx(char *exp){
    int i =0,j=0;
    int len = strlen(exp);
    char pfix[len+1];
    while(exp[i]!='\0'){
        if(isOperand(exp[i])){
            pfix[j++] = exp[i++];
        }
        else{
            if(outPrec(exp[i]) > inPrec(stackTop())){
                push(exp[i++]);
            }
            else{
                if(exp[i] == ')' && stackTop() == '('){
                    pop();
                    i++;
                    continue;
                }
                pfix[j++] = pop();
            }
        }
    }
    while(!isEmpty()){
        pfix[j++] = pop();
    }
    pfix[j] = '\0';
    printf("postfix notation is %s\n",pfix);
    
}
int main(){
    char exp[100];
    cin>>exp;
    infxToPostfx(exp);
    return 0;
}