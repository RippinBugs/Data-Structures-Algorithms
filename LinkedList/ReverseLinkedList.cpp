#include<bits/stdc++.h>
using namespace std;
struct node 
{
    int data;
    struct node *next;
}*first,*p=NULL,*pp=NULL,*ppp=NULL;

void createLinkedList()
{
    int data,n;
    char flag;
    //first = NULL;
    struct node *last,*t;

    //creating the first node and work on it
    first = new node;
    printf("enter the data: ");
        cin>>data;
    first->data = data;
    first->next = NULL;

    //here last is a pointer which traverses through different nodes
    last = first;
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
            last->next = t;
            last = t;
        }
        else{
            //times = 0; redundant
            break;
        }
    }
    printf("There are %d node(s)\n",n);
}

void Display(struct node *p)
{
    int i=0;
    while(p){
        printf("the data of the %dth node is: %d\n",i++,p->data);
        p = p->next;
    }
}

void ReversingLinks(struct node *p)
{
    
    //This procedure works on by sliding the tailing pointers
    //ppp = prev_prev_prev, pp = prev_prev 
    while(p){
        ppp = pp;
        pp = p;
        p = p->next;
        pp->next = ppp;
    }
    first = pp;
}
void RecursiveReverse(struct node *q, struct node *p){
    if(p){
        RecursiveReverse(p,p->next);
        p->next = q;
    }
    else 
        first = q;
}

int countNodes(struct node *p)
{
    int i = 0;
    p = first;
    while(p){
        i++;
        p = p->next;
    }
    return i-1;
}
void ReversingElements(struct node *p){
    int n = countNodes(first);
    int a[n];
    p = first;
    int i = 0;
    while(p){
        a[i++] = p->data;
        p = p->next;
    }
    p = first;
    while(p){
        p->data = a[--i];
        p = p->next;
    }
}

int main()
{
    createLinkedList();
    Display(first);
    /*
    // This is for Recursive Reverse 
    RecursiveReverse(NULL,first);
    printf("After reversing the linked list\n");
    Display(first);
    */

    /*
    //This is for Reversing the linked list using nodes.
    ReversingLinks(first);
    printf("After reversing the linked list\n");
    Display(first);
    */

     
    //This is for Reversing the linked list using elements but not nodes.
    ReversingElements(first);
    printf("After reversing the linked list\n");
    Display(first);
    

    return 0;
}
