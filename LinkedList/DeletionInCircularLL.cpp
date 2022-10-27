#include<bits/stdc++.h>
using namespace std;
struct node 
{
    int data;
    struct node *next;
}*tail=NULL;

int lengthLL(){
    int n = 0;
    struct node *p = tail->next;
    do{
        ++n;
        p = p->next;
    }while(p!=tail->next);
    printf("the length is %d\n",n);
    return n;
}

void Display(struct node *p)
{
    //static int flag = 0;
    int i=0;
    if(p==NULL){
        printf("lineked list is empty\n");
    }
    else{
        p = tail->next;
        do{
            //flag = 1;
            printf("the data of the %dth node is: %d\n",i++,p->data);
            p = p->next;
        }while(p!=tail->next);
    }
    //flag = 0;
}

void DeleteBegin()
{
    struct node *p;;
    // when there is no node in the circular linked list
    if(tail == NULL){
        printf("The circular linked list is empty already\n");
    }
    //when there is only one node at the linked list
    else{
        p=tail->next;
        if(p->next == p){
            tail = NULL;
            delete p;
        }
        //when there are a no of nodes and we want to delete the first node
        else{
            tail->next = p->next;
            delete p;
        }
    }
}

void DeleteEnd()
{
    struct node *pp, *p;
    
    if(tail == NULL){
        printf("There is no node to delete\n");
    }
    else{
        p = tail->next;
        if(p->next == p){
            tail = NULL;
            delete p;
        }
        else{
            while(p->next != tail->next){
                pp = p;
                p = p->next;
            }
            pp->next = tail->next;
            tail = pp;
            delete p;
    }
    }
}
void DeleteAtAnyPoint(int pos)
{
    struct node *current, *nextnode;
    current = tail->next;
    int i =1 ;
    //here we think of position in terms of nodes. i.e if there are 4 nodes there are 4 positions.
    if(pos<1 || pos>lengthLL()){
        printf("invalid position");
    }
    else if(pos == 1)
        DeleteBegin();
    else if(pos == lengthLL())
        DeleteEnd();
    else{
        while(i<pos-1){
            current = current->next;
            i++;
        }
        nextnode = current->next;
        current->next = nextnode->next;
        delete nextnode;
    }
}
void insertEmpty(int val)
{
    if(tail == NULL){
        struct node *temp = new node;
        temp->data = val;
        tail = temp;
        temp->next = temp;
    }
    else
        printf("Linked list is not empty\n");
}

void insertBegin(int val)
{
    if(tail == NULL){
        insertEmpty(val);
    }
    else{
        struct node *temp = new node;
        temp->data = val;
        temp->next = tail->next;
        tail->next = temp;
    }
    
}
void insertEnd(int val)
{
    if(tail == NULL){
        insertEmpty(val);
    }
    else{
        struct node *temp = new node;
        temp->data = val;
        temp->next = tail->next;
        tail->next = temp;
        tail = temp;
    }
    
}

void insertAfter(int pos, int val)
{
    if(pos<0 || pos>=lengthLL()){
        printf("invalid position\n");
        return;
    }
    struct node *p = tail->next;
    if(p == NULL){
        insertEmpty(val);
    }
    else{
        for(int i =0;i<pos-1;i++){
            p = p->next;
        }
        struct node *temp = new node;
        temp->data = val;
        temp->next = p->next;
        p->next = temp;
    }
    
}
int main()
{   
    DeleteBegin();
    Display(tail);
    insertBegin(12);
    insertBegin(23);
    insertEnd(35);
    insertAfter(2,45);
    insertAfter(3,500); 
    insertBegin(1);
    insertAfter(4,55); 
    Display(tail);
    DeleteBegin();
    DeleteEnd();
    DeleteAtAnyPoint(4);
    Display(tail);
    return 0;
}
