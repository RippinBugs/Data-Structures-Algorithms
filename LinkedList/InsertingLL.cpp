#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *next;
}*first,*last;

void createLinkedList()
{
    int data,loop_runner= 1;
    char x;
    printf("enter the data for the first node: ");
    cin>>data;
    first = new node;
    first->data = data;
    first->next = NULL;
    last = first;
    struct node *t;
    
    while(loop_runner){
        printf("Do you want to add another node?(y/n): ");
        cin>>x;
        if(x=='y'){
            t= new node;
            printf("enter the data for this node: ");
            cin>>data;
            t->data = data;
            t->next = NULL;
            last->next = t;
            last = t;
        }
        else
            break;
    }
}

void insertingLL(int pos,int value)
{   
    struct node *p = NULL;
    struct node *temp;
    // for inserting before first
    if(pos==0){
        temp = new node;
        temp->data = value;
        temp->next = first;
        first = temp;
    }
    // for inserting in a given position
    else if(pos>0){
        p = first; // to make p point the first node.
        for(int i=0;i<pos-1 && p;i++){
            p = p->next;
        }
        // to check if the position is out of bound or not
        //if that happens it is unreachable to that point.
        if(p){
            temp = new node;
            temp->data = value;
            temp->next = p->next;
            p->next = temp;
        }
    }
}

void Display(struct node *p)
{
    int i;
    while(p){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    createLinkedList();
    int pos, value;
    printf("Enter the position and the value: ");
    cin>>pos>>value;
    insertingLL(pos,value);
    Display(first);
    return 0;
}

//min time complexity is O(1),when pos is zero
//max time complexity is O(n), when position is some value n