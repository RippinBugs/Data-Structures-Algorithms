//In this coding example we create a linked list using inserting a node at the last position
//For the first time we need to use a simple logic to get it started.

#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node *next;
}*first = NULL, *last = NULL;

void insertAtLast(int val){
    struct node *temp = new node;
    temp->data = val;
    temp->next = NULL;
    if(first == NULL){
        //this will make point both first and last to temp node
        first = last = temp;
    }
    else{
        last->next = temp;
        last = temp;
    }
}

void Display(struct node *p){
    while(p){
        printf("%d ",p->data);
        p = p->next;
    }
}

int main()
{
    char x;
    int val,looprunner = 1;
    while(looprunner){
        printf("Do you want to insert a new node?(y/n): ");
        cin>>x;
        if(x == 'y'){
            printf("Enter value: ");
            cin>>val;
            insertAtLast(val);
            continue;
        }
        else{
            looprunner = 0;
        }
    }
    Display(first);
    return 0;
}