#include<bits/stdc++.h>
using namespace std;

struct stack_{
    int size;
    int top;
    char *s;
};
void push(struct stack_ *st,char val){
    if(st->top == (st->size-1)){
        printf("Stack Overflow\n");
    }
    else{
        st->top++;
        st->s[st->top] = val;
    }
}

char pop(struct stack_ *st){
    char x=-1;
    if(st->top == -1){
        printf("Stack Underflow\n");
    }
    else{
        x = st->s[st->top--];
    }
    return x;
}
bool isEmpty(struct stack_ st)
{
    if(st.top == -1)
        return true;
    else
        return false;
}


bool isBalanced(char *exp){
    struct stack_ st;
    st.top = -1;
    st.size = strlen(exp);
    st.s = new char[st.size];
    for(int i = 0;exp[i]!='\0';i++){
        if(exp[i] == '('){
            push(&st,'(');
            printf("%c\n",exp[i]);
        }
        else if(exp[i] == ')'){
            if(isEmpty(st)){
                return false;
            }
            else{
                printf("%c\n",exp[i]);
                pop(&st);
            }
        }
        else
            continue;
    }
    return (isEmpty(st))?true:false;
    
}
int main(){
    //taking an expression as input
    char exp[100];
    cin>>exp;

    //checking if the parenthesis are balanced or not.
    if(isBalanced(exp)){
        printf("balanced\n");
    }
    else{
        printf("not balanced\n");
    }
    
}