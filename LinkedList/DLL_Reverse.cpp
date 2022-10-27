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

void reverse(struct node *p)
{
    struct node *temp;
    while(p){
        temp = p->next;
        p->next = p->previous;
        p->previous = temp;
        p = p->previous;
        //this works
        if(p && p->next == NULL){
            first = p;
        }  

        //but this doesn't work for the below code
        //because inside if, it interprets as null->next as p already becomes NULL
        // so in the above code it first checks that p is wether null or not. if p is null then returns 0 a
        //and thus no need to check for the next term which is null->next. and hence, not get confused or lost at runtime.

        // if(p->next == NULL && p){
        //     first = p;
        // }
    }
    //this below works when we don't use the if statement at all.
    // p = first;
    // first = last;
    // last = p;
}

void Display(struct node *p)
{
    while(p){
        printf("%d\n",p->data);
        p = p->next;
    }
}
int main()
{
    CreateDoublyLL();
    Display(first);
    reverse(first);
    Display(first);
    return 0;

}