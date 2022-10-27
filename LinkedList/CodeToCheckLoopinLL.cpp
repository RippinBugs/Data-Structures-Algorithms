//This is probably the most badly written code ever. but it does the work ig.

#include<bits/stdc++.h>
using namespace std;
struct node 
{
    int data;
    struct node *next;
}*first=NULL,*last=NULL,*second=NULL,*lastsec;

void createLinkedList()
{
    int data,n;
    char flag;
    struct node *t;

    //creating the first node and work on it
    second = new node;
    printf("enter the data: ");
        cin>>data;
    second->data = data;
    second->next = NULL;

    //here last is a pointer which traverses through different nodes
    lastsec = second;
    //n is the number of times we create a node
    n=1;

    //times is nothing but a flag to loop over whether to create a node or not?
    int times = 1;

    //for creating nodes other than first
    while(times){   
        printf("Do you want to create another node?(y/n)");
        cin>>flag;
        if(flag == 'y'){
            n++;
            t = new node;
            printf("enter the data: ");
            cin>>data;
            t->data = data;
            t->next = NULL;
            lastsec->next = t;
            lastsec = t;
        }
        else{
            //times = 0; redundant
            break;
        }
    }
    printf("There are %d node(s)\n",n);
}

void createLinkedListLoop()
{
    int data;
    char flag;
    //first = NULL;
    struct node *t;

    //creating the first node and work on it
    first = new node;
    printf("enter the data: ");
        cin>>data;
    first->data = data;
    first->next = NULL;

    //here last is a pointer which traverses through different nodes
    last = first;
    //n is the number of times we create a node

    //times is nothing but a flag to loop over whether to create a node or not?
    int times = 1;

    //for creating nodes other than first
    while(times){   
        printf("Do you want to create another node?(y/n)");
        cin>>flag;
        if(flag == 'y'){
            t = new node;
            printf("enter the data: ");
            cin>>data;
            t->data = data;
            t->next = NULL;
            last->next = t;
            last = t;
        }
        else{
            //times = 0; redundant
            break;
        }
    }
    //printf("There are %d node(s)\n",n);
}

//making a looped linked list
void LLhavingLoop(int pos)
{
    // if(pos == 1){
    //     last->next = first;
    // }
    struct node *p = first;
    for(int i = 1;i<pos;i++){
        p = p->next;
    }
    last->next = p;
}

//This ones for understanding.
void NDisplay(struct node *p)
{
    int i=0;
    while(p){
        printf("the data of the %dth node is: %d\n",i++,p->data);
        p = p->next;
    }
}
int lengthLL(){
    int n = 0;
    struct node *p = last->next;
    do{
        ++n;
        p = p->next;
    }while(p!=last->next);
    //printf("the length is %d\n",n);
    return n;
}
//Even though we have a loop we are able to print all the data once.
void Display(struct node *p)
{
    int i=0;
    static int flag = 0;
    //if length equals to zero or one, use another code block to print data else use the do while loop
    if(lengthLL() == 1){
        printf("%d",p->data);
    }
    else if(lengthLL() == 0){
        printf("no nodes\n");
    }
    else{
        do{
            // printf("the data of the %dth node is: %d\n",i++,p->data);
            if(p->next == last->next)
                flag = 1;
                
            printf("the data of the %dth node is: %d\n",i++,p->data);
            p = p->next;
            
        }while(p->next != last->next || flag == 0);
        printf("%d\n",p->data);
        flag = 0;
    }
}

//detecting a loop using two pointers
void detectLoop(struct node *f){
    struct node *p,*q;
    p = q = f;
    do{
        p = p->next;
        q = q->next;
        q = (q != NULL)? q->next : q;
    }while(p != q );
    if(p == q && (p && q))
        printf("loop\n");
    else
        printf("not loop\n");

}
int main()
{
    createLinkedListLoop();
    LLhavingLoop(1);
    Display(first);
    //NDisplay(first);
    detectLoop(first);
    createLinkedList();
    detectLoop(second);
    return 0;
}
