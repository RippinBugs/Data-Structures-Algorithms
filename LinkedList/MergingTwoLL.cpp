#include<bits/stdc++.h>
using namespace std;
struct node 
{
    int data;
    struct node *next;
}head1,head2,*third;
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

void Merging(struct node *first, struct node *second){
    struct node *last = NULL;
    //This part is for the pointing of third and last pointer to the first node which has the lesser value 
    //of two first nodes of head1 and head2 linked lists
    if(first->data <= second->data){
        third = last = first;
        first = first->next;
        last->next = NULL;
    }
    else{
        third = last = second;
        second = second->next;
        last->next = NULL;
    }
    //and this loop continues while any one of the Linked lists has finished
    while(first && second){
        if(first->data <= second->data){
            last->next = first;
            last = first;
            first = first->next;
            last->next = NULL;
        }
        else{
            last->next = second;
            last = second;
            second = second->next;
            last->next = NULL;
        }
    }
    //this last part is for the rest of the nodes of the remained nodes of a linked list
    if(first){
        last->next = first;
    }
    if(second){
        last->next = second;
    }
}
int main()
{
    
    createLinkedList(&head1);
    
    createLinkedList(&head2);
    
    Merging(&head1,&head2);
    Display(third); 

    return 0;
}
