//programming is fun. Try harder amit.

#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *next;
    struct node *prev;
}*first=NULL,*last=NULL;

void createDLL()
{
    int data,flag = 1;
    char x;
    printf("Do you want the first node?(y/n): ");
    cin>>x;
    if(x == 'y'){
        first = new node;
        printf("Enter the data: ");
        cin>>data;
        first->data = data;
        first->next = NULL;
        first->prev = NULL;
    }
    else
        return;
    last = first;
    while(flag){
        printf("Do you want another node?(y/n): ");
        cin>>x;
        if(x == 'y'){
            struct node *temp;
            temp = new node;
            printf("Enter the data: ");
            cin>>data;
            temp->data = data;
            temp->next = NULL;
            temp->prev = last;
            last->next = temp;
            last = temp;
        }
        else
            flag = 0;
    }
}
int lengthCDLL()
{
    int i = 0;
    struct node *p = first;
    if(!first)
        return 0;
    else{
        do{
            i++;
            p = p->next;
        }while(p!=first);
        return i;
    }
}
void makingCircular(){
    if(!last && !first){
        last = first;
        first = last;
        return;
    }
    last->next = first;
    first->prev = last;
}


void Display()
{
    struct node *p;
    int flagNor;
    flagNor = 1;
    
    p = first;
    while(p){
        if(flagNor){
            printf("printing the data in normal order\n");
            flagNor = 0;
        }
        printf("%d\n",p->data);
        p = p->next;
    }
    
}

void CirDisplay()
{
    struct node *p;
    int flagNor = 1;
    
    // p=first;
    // do{
    //     printf("%d\n",p->data);
    //     p=p->next;
    // }while(p!=first);
    p = first;
    if(p){
        do{
            if(flagNor){
                printf("printing the data in normal order\n");
                flagNor = 0;
            }
            printf("%d\n",p->data);
            p = p->next;
        }while(p != first);
    }
    else{
        printf("No nodes in the CDLL\n");
    }
}
void insertAtFirst(int val){
    struct node *p = first;
    struct node *temp;
    temp = new node;
    temp->data = val;
    if(!p){
        temp->next = temp->prev = first;
        first = last = temp;
        //this below line make the one node circular.
        temp->next = temp->prev = temp;
    }
    else{
        temp->next = p;
        temp->prev = last;
        last->next = temp;
        p->prev = temp;
        first = temp;
    }
}
void insertAtAny(int pos,int val){
    struct node *temp,*p;
    p = first;
    if(pos<0 || pos>lengthCDLL()){
        printf("invalid\n");
        return ;
    }
    if(pos == 0){
        insertAtFirst(val);
        return ;
    }
    for(int i =0;i<pos-1;i++){
        p=p->next;
    }
    temp = new node;
    temp->data = val;
    temp->next = p->next;
    temp->prev = p;
    p->next = temp;
    p->next->prev = temp;
    
    //if temp->next == first that means temp will be the last node. in other cases temp will be in between node.
    if(temp->next == first){
        last = temp;
    }
}

void DeleteAtBegin()
{
    struct node *temp;
    temp = first;
    if(!temp){
        printf("no nodes to delete\n");
    }
    else if(temp->next == first){
        first = last = NULL;
        delete temp;
    }
    else{
        first->next->prev = last;
        last->next = first->next;
        delete temp;
        first = last->next;
    }
}
void DeleteAtAny(int pos){
    struct node *temp;
    if(pos == 1){
        DeleteAtBegin();
    }
    else if((pos-1) == lengthCDLL()){
        //position - 1 because in length function we start from 0 for insertion 
        // but in delete the position starts from 1 instead of 0.
        temp = last;
        last->prev->next = first;
        first->prev = last->prev;
        delete temp;
        last = first->prev;
    }
    else{
        struct node *p = first;
        for(int i = 1;i<pos-1;i++){
            p= p->next;
        }
        temp = p->next;
        p->next = temp->next;
        temp->next->prev = p;
        delete temp;
    }
}
int main(){
    createDLL();
    Display();
    char x;
    printf("Do you want to make it circular?(y/n): ");
    cin>>x;
    if(x = 'y'){
        makingCircular();
    }
    else{
        printf("User don't want to make it circular\n");
    }
    insertAtFirst(1);
    CirDisplay();
    DeleteAtBegin();
    CirDisplay();
    insertAtFirst(5);
    insertAtAny(1,23);
    insertAtAny(2,45);
    insertAtAny(1,40);
    insertAtAny(3,111);
    CirDisplay();
    DeleteAtAny(3);
    CirDisplay();
    DeleteAtAny(1);
    CirDisplay();
    DeleteAtAny(3);
    CirDisplay();
    insertAtAny(2,999);
    insertAtFirst(1000);
    CirDisplay();
    return 0;
}
