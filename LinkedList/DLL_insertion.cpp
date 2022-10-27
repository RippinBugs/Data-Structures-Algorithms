#include<bits/stdc++.h>
using namespace std;

//node for doubly linked list
struct node {
    struct node *previous;
    int data;
    struct node *next;
}*first = NULL,*last = NULL;

void CreateDoublyLL()
{
    struct node *temp;
    char x;
    int data,flag = 1;
    //first = last;
    printf("Do you want to have the first node?(y/n): ");
    cin>>x;
    //creating the first node and first pointer points to it
    if(x == 'y'){
        first = new node;
        first->previous = NULL;
        printf("Enter your data: ");
        cin>>data;
        first->data = data;
        first->next = NULL;
    }
    else{
        return ;
    }
    //making last pointer points to the first node.
    last = first;
    while(flag){
        printf("Do you want to have another node?(y/n): ");
        cin>>x;
        if(x == 'y'){
            temp = new node;
            printf("Enter your data: ");
            cin>>data;
            temp->data = data;
            temp->next = last->next;
            temp->previous = last;
            last->next = temp;
            last = temp;
        }
        else
            flag = 0;
    }
}
void insertAtBegin(int data)
{
    struct node *temp;
    temp = new node;
    temp->data = data;
    if(first){
        temp->next = first;
        temp->previous = NULL;
        first->previous = temp;
    }
    else{
        temp->next = temp->previous = NULL;
        // to make the last pointer points to the only node temp.
        last = temp;
    }
    first = temp;
}

void insertAtAny(int pos,int data)
{
    if(pos == 0){
        insertAtBegin(data);
    }
    else{
        struct node *p = first;
        struct node *temp = new node;
        temp ->data = data;
        for(int i=0;i<pos-1;i++){
            p = p->next;
        }
        temp->next = p->next;
        temp->previous = p;
        if(p->next){
            p->next->previous = temp;
        }
        else{
            last = temp;
        }
        p->next = temp;

    }
}

//state of the art Display function(just kidding)
void Display()
{
    struct node *p;
    int flagNor,flagRev;
    flagNor= flagRev = 1;
    
    p = first;
    while(p){
        if(flagNor){
            printf("printing the data in normal order\n");
            flagNor = 0;
        }
        printf("%d\n",p->data);
        p = p->next;
    }
    
    p = last;
    while(p){
        if(flagRev){
            printf("printing the data in reverse order\n");
            flagRev = 0;
        }
        printf("%d\n",p->data);
        p = p->previous;
    }
}
int main()
{
    CreateDoublyLL();
    Display();
    insertAtBegin(12);
    // insertAtAny(1,23);
    // insertAtAny(1,40);
    Display();
    return 0;

}