#include<bits/stdc++.h>
using namespace std;

struct stack_{
    int size;
    int top;
    int *s;
};
bool isEmpty(struct stack_ st)
{
    if(st.top == -1)
        return true;
    else
        return false;
}
bool isFull(struct stack_ st){
    if(st.top == (st.size-1))
        return true;
    else
        return false;
}
void push(struct stack_ *st,int val){
    if(st->top == (st->size-1)){
        printf("Stack Overflow\n");
    }
    else{
        st->top++;
        st->s[st->top] = val;
    }
}
int pop(struct stack_ *st){
    int x=-1;
    if(st->top == -1){
        printf("Stack Underflow\n");
    }
    else{
        x = st->s[st->top--];
    }
    return x;
}
int stackTop(struct stack_ st){
    if(st.top == -1)
        return -1;
    return st.s[st.top];

}
int peek(struct stack_ st,int pos)
{   
    //pos starts from 1 not 0.
    //least value of top is 0. so when calculating index if the position
    //is bigger than the stacksize it will result in a negative value for what it's worth.
    //this peek function works as you are looking into it from the top.
    // like a can of balls where you see the first ball which has been inserted lastly.
    int x = -1;
    int index = st.top - pos + 1;
    if(index<0){
        printf("invalid position\n");
    }
    else
        x = st.s[index];
    return x;
}
void Display(struct stack_ st){
    printf("From top view\n");
    for(int i = st.top;i>-1;i--){
        printf("%d\n",st.s[i]);
    }
}
int main()
{
    struct stack_ st;
    printf("Enter the size of the stack: ");
    cin>>st.size;
    //creating a stack with the recent given input.
    st.s = new int[st.size];
    //initialize stack top as -1, becasue there are no value at the stack currently.
    st.top = -1;
    push(&st,12);
    push(&st,2);
    Display(st);
    printf("popped out this value: %d\n",pop(&st));
    Display(st);

}