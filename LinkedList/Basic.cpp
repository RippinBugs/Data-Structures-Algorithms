#include<bits/stdc++.h>
using namespace std;
struct node 
{
    int data;
    struct node *next;
}*first;

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

int main()
{
    createLinkedList();
    Display(first);
    return 0;
}
