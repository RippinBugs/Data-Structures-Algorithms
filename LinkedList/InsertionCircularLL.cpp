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
    Display(tail);
    insertBegin(12);
    insertBegin(23);
    insertEnd(35);
    insertAfter(2,45);
    //insertAfter(3,500); //works perfectly if we withdraw the comment.
    insertAfter(4,55); // because 4 means its the last node and we have specific function for it.
    Display(tail);
    return 0;
}
