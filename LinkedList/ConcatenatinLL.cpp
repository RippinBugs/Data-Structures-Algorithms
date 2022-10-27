#include<bits/stdc++.h>
using namespace std;
struct node 
{
    int data;
    struct node *next;
}head1,head2;
//we take two nodes instead of pointers and then call by reference to work this problem

//if we take *head1 then the head1 pointer will point to null initially and the pointer p will move along as we create 
//new nodes but unfortunately as we didn't linked together p and head1 we can't be able to work properly. But if we 
//want to work with pointer passing then in main we have to create the first node and pass it on to create function.
//in this way it can work properly.


void createLinkedList(struct node *p)
{
    int data,n;
    char flag;

    struct node *last,*t;

    printf("enter the data: ");
        cin>>data;
    p->data = data;
    p->next = NULL;

    //here last is a pointer which traverses through different nodes
    last = p;
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

void concate(struct node *p, struct node *q){
    while(p->next){
        //Here we check p->next instead of p, that's because if i'm checking the condition
        //with p, then at some point p will point to null and then it's impossible to concatenate.
        p = p->next;
    }
    //setting up the connection between two nodes
    p->next = q;
    //making q point to nothing or in other words making head2 point to nothing.
    q = NULL;
}
int main()
{
    
    createLinkedList(&head1);
    Display(&head1);

    createLinkedList(&head2);
    Display(&head2);

    concate(&head1,&head2);
    struct node first = head1;
    Display(&first);

    // when working with *head1 i need to solve the problem like this.
    // head1 = new node;
    // head1->data = 2;
    // head1->next = NULL;
    // createLinkedList(head1);
    // Display(head1);

    return 0;
}
