//infix to postfix using character array not linked list.

#include<bits/stdc++.h>
using namespace std;

struct stack_{
    int size;
    int top;
    char *s;
};

int isEmpty(struct stack_ st){
    if(st.top == -1){
        return 1;
    }
    else 
        return 0;
}
int isOperand(char x){
    if(x == '+' || x == '-' || x == '/' || x == '*')
        return 0;
    else 
        return 1;
}

int precedence(char x){
    if(x == '+' || x == '-')
        return 1;
    else if(x == '/' || x == '*')
        return 2;
    else
        return 0;
}
char stackTop(struct stack_ *st){
    if(st->top == -1){
        //printf("Stack is empty\n");
        return '\0';
    }
    else
        return st->s[st->top];
}
void push(struct stack_ *st,char data){
    if(st->top == (st->size -1)){
        printf("stack overflow\n");
    }
    else{
        st->s[++st->top] = data;
    }
}

char pop(struct stack_ *st){
    if(st->top == -1){
        printf("stack underflow\n");
        return '\0';
    }
    else{
        return st->s[st->top--];
    }
}
char* infix_to_postfix(char *infx_exp)
{
    struct stack_ st, postfx;
    st.top = -1;
    st.size = strlen(infx_exp);
    printf("%d\n",st.size);
    st.s = new char[st.size];
    postfx.s = new char[st.size+1]; //size+1 for '\0' at the end as it will be a string
    int i = 0,j = 0;
    while(infx_exp[i] != '\0'){
        //we use a while loop instead of for because the increment of i and j are not simultaneous. we may need 
        //to change it at different times depending on the situation.
        //check for operand, if operand then we push it to postfix string.
        if(isOperand(infx_exp[i])){
            postfx.s[j++] = infx_exp[i++];
        }
        //now if it's a operator, we first check for the precedence. if the operator's precedence is greater the 
        //stackTop's operator then push it. else pop out the operator but don't increase i.
        else{
            if(precedence(infx_exp[i]) > precedence(stackTop(&st)) ){
                push(&st,infx_exp[i++]);
            }
            else{
                postfx.s[j++] = pop(&st);
            }
        }
    }
    //this part is for all the operators that are still on the stack.
    while(!isEmpty(st)){
        postfx.s[j++] = pop(&st);
    }
    //make it a string by puttina a null character at the end.
    postfx.s[j] = '\0';
    return postfx.s;
}

int main(){
    char exp[100];
    cin>>exp;
    char *postfix = infix_to_postfix(exp);
    printf("The postfix notation is: %s\n",postfix);
    return 0;
}