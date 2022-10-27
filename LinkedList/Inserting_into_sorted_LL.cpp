#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node *next;
}*first=NULL,*pp=NULL,*p=NULL;

void createSortedLL(){
    int val,looprunner = 1;
    char x;
    struct node *p,*temp = new node;
    printf("Enter the value of the first node: ");
    cin>>val;
    temp->data = val;
    temp->next = NULL;
    first = temp;
    p = first;
    while(looprunner){
        printf("Do you want to create another node?(y/n): ");
        cin>>x;
        if(x == 'y'){
            temp = new node;
            printf("Enter the value for this node: ");
            cin>>val;
            temp->data = val;
            temp->next = NULL;
            p->next = temp;
            p = p->next;
        }
        else
            looprunner = 0;
    }
}

void insertIntoSortedLL(int val){
    struct node *temp = new node;
    temp->data = val;
    temp->next = NULL;
    p = first;
    //say we don't have a sorted LL, then the node we insert is the only node in the LL.
    if(first == NULL)
        first = temp;
    //Whenever there is already a sorted linked list created and all we need is to insert another node so 
    // that the resulting LL will be sorted automatically.
    else{
        while(p && p->data < val){
            pp = p;
            p = p->next;
        }
        if(p == first){
            temp->next = first;
            first = temp;
        }
        else{
            temp->next = pp->next;
            pp->next = temp;
        }
    }
}

void Display(struct node *p){
    while(p){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}
int main(){
    createSortedLL();
    Display(first);
    int x;
    printf("Enter the value for new node: ");
    cin>>x;
    insertIntoSortedLL(x);
    Display(first);
    return 0;
}