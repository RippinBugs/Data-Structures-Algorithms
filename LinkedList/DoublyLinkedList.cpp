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

void Display()
{
    struct node *p;
    printf("printing the data in normal order\n");
    p = first;
    while(p){
        printf("%d\n",p->data);
        p = p->next;
    }
    printf("printing the data in reverse order\n");
    p = last;
    while(p){
        printf("%d\n",p->data);
        p = p->previous;
    }
}
int main()
{
    CreateDoublyLL();
    Display();
    return 0;

}