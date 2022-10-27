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

void Display(struct node *p)
{
    int i=0;
    while(p){
        printf("the data of the %dth node is: %d\n",i++,p->data);
        p = p->next;
    }
}

struct node* transposition(struct node *cur,int key){
    struct node *prev_prev,*prev;
    prev_prev = NULL;
    prev = NULL;
    while(cur){
        if(cur->data == key){
            //if the key is in 3rd node or above
            if(prev_prev){
                prev_prev->next = cur;
                prev->next = cur->next;
                cur->next = prev;
                return cur;

            }
            //if the key is in the second node
            //more like back to head method
            else if(prev){
                prev->next = cur->next;
                cur->next = prev;
                first = cur;
                return cur;
            }
        }
        else{
            prev_prev = prev;
            prev = cur;
            cur = cur->next;
        }
    }
    return NULL;
}


int main()
{
    createLinkedList();
    Display(first);

    int key;
    printf("Enter the key: ");
    cin>>key;
    struct node *temp = transposition(first,key);
    if(temp)
        printf("exist\n");
    else
        printf("not exist\n");

    Display(first);
    printf("enter another key: ");
    cin>>key;
    temp = transposition(first,key);
    if(temp)
        printf("exist\n");
    else
        printf("not exist\n");
    
    Display(first);

    return 0;
}