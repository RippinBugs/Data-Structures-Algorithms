//this program has both the codes for removing duplicates from sorted and unsorted linked lists.

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

void RemovingDuplicates()
{
    struct node *m, *p , *q;
    // m is the pointer which will point to each unique value's node to iterate through.
    m = first;
    while(m){ //not m->next cause this will be similar to NULL->next at the end of the loop
        // p and q are sliding pointers
        p = m;
        q = p->next;
        while(q){
            // this part will check for duplicates and then if found, will delete that node
            if(m->data == q->data){
                p->next = q->next;
                delete q;
                q = p->next;
            }
            else{
            //this one will slide the pointers p and q till the end of the list
                p = q;
                q = q->next;
            }
        }
    m = m->next;
    }
}
void Display(struct node *p)
{
    int i;
    while(p){
        printf("the data of the %dth node is: %d\n",i,p->data);
        p = p->next;
    }
}

int main()
{
    createLinkedList();
    RemovingDuplicates();
    Display(first);
    return 0;
}
