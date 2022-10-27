//Creating a linked list using insertion at any point
//Make sure to follow the order. Otherwise it will result in ambiguous output.
//p is a tail pointer.

#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *next;
}*first = NULL;

void insertAndCreate(int pos,int val){
    struct node *p,*temp = new node;

    if(pos == 0){
        p = first;
        temp->data = val;
        temp->next = p;
        first = temp;
    }
    else if(pos>0){
        p = first;
        for(int i = 0;i<pos-1 && p;i++){
            p=p->next;
        }
        if(p){
            temp->data = val;
            temp->next = p->next;
            p->next = temp;
        }
    }
    
}

void Display(struct node *p){
    while(p){
        printf("%d ",p->data);
        p = p->next;
    }
}
int main(){
    char x;
    int pos,val,looprunner = 1;
    printf("make sure to start with position zero\n");
    while(looprunner){
        printf("Do you want to insert a new node?(y/n): ");
        cin>>x;
        if(x == 'y'){
            printf("Enter the position and value: ");
            cin>>pos>>val;
            insertAndCreate(pos,val);
            continue;
        }
        else{
            looprunner = 0;
        }
    }
    Display(first);
    return 0;
}