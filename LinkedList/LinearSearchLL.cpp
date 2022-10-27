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

struct node* linearSearchLL(struct node *p,int key)
{
    while(p){
        if(p->data == key){
            return p;
        }
        p = p->next;
    }
    return NULL;
}

struct node* RecurLinearSearchLL(struct node *p, int key)
{   
    if(p==NULL){
        return NULL;
    }
    else{
        if(p->data == key)
            return p;
        else{
            p = p->next;
            return RecurLinearSearchLL(p,key);
        }
    }
}

struct node *MoveToHead(struct node *p,int key)
{   
    int iter =0;
    //q is a tail pointer
    struct node *q = NULL;
    while(p){
        iter++;
        //after finding the key, move the node to head and link together other nodes 
        if(p->data == key){
            q->next = p->next;
            p->next = first;
            first = p;
            printf("Number of iteration it takes to find the key is %d\n",iter);
            return p;
        }
        //until we found the key
        
        q=p;
        p = p->next;
        
        
    }
    return NULL;
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
    int key;
    printf("Enter the key to find: ");
    cin>>key;
    //printf("The address is %p\n",linearSearchLL(first,key));

    /*
    struct node *temp = linearSearchLL(first,key);
    if(temp)
        printf("key is found at %p \n",temp->next);
    else
        printf("key is not found\n");
    */

    /*struct node *temp = RecurLinearSearchLL(first,key);
    if(temp)
        printf("key is found at %p \n",temp->next);
    else
        printf("key is not found\n");
    */
    Display(first);
    struct node *temp = MoveToHead(first,key);
    if(temp)
        printf("key is found and the key is %d \n",temp->data);
    else
        printf("key is not found\n");
    
    Display(first);

    return 0;
}