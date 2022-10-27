#include<bits/stdc++.h>
using namespace std;
struct node 
{
    int data;
    struct node *next;
}*first;

void createCircularLinkedList()
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
    //making it circular by pointing to the first node. 
    //we can do it to point at any node and make them circular by our choices.
    last->next = first;
    printf("There are %d node(s)\n",n);
}

void Display(struct node *p)
{
    int i=0;
    //we use a do while loop because we have to execute the printing statement for atleast one time.
    // because of the nature of circular linked list.
    do{
        printf("the data of the %dth node is: %d\n",i++,p->data);
        p = p->next;
    }while(p!=first);
}

void RecursiveDisplay(struct node *p){
    // make the flag static so that it works out perfectly
    static int flag = 0;
    if(p!=first || flag == 0){
        flag = 1;
        printf("%d\n",p->data);
        RecursiveDisplay(p->next);
    }
    //making flag 0, so that next time when we call the function, it works perfectly.
    flag = 0;
}

int main()
{
    createCircularLinkedList();
    Display(first);
    RecursiveDisplay(first);
    return 0;
}
