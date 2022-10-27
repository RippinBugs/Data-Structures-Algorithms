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
//Recursive way to display the elements of the linked list
void Display(struct node *p)
{
    if(p){
        printf("%d ",p->data);
        Display(p->next);
    }
    else
        printf("\n");

}

//recursive Display function but this time it prints the data in reverse order
void RevDisplay(struct node *p)
{
    if(p!=NULL){
        RevDisplay(p->next);
        printf("%d ",p->data);
    }
    /*else
        printf("\n");
    // not necessary actually.
    */
}

int CountNodes(struct node *p){
    int c = 0;
    while(p){
        c++;
        p = p->next;
    }
    return c;
}

int RecursivelyCountingNodes(struct node *p){
    if(p){
        return RecursivelyCountingNodes(p->next) + 1;
        //return 1 + RecursivelyCountingNodes(p->next);
    }
    else
        return 0;
}
int SumOfLinkedListValues(struct node *p)
{
    int sum = 0;
    while(p){
        sum+=p->data;
        p = p->next;
    }
    return sum;
}

int RecursivelySumOfLinkedListValues(struct node *p)
{
    if(p==NULL)
        return 0;
    else{
        return RecursivelySumOfLinkedListValues(p->next) + p->data;
    }
    
}
int maxLL(struct node *p)
{   int maximum = p->data;
    while(p){
        if(p->data > maximum)
            maximum = p->data;
        
        p = p->next;
    }
    return maximum;
}

int gettingMax(struct node *p)
{
    int x;
    if(p==NULL)
        return INT32_MIN;
    else{
        x = gettingMax(p->next);
        return x > p->data? x : p->data;
    }
}
int main()
{
    createLinkedList();
    Display(first);
    RevDisplay(first);
    printf("\nThe number of nodes in the linked list is %d\n",CountNodes(first));
    printf("The number of nodes in the linked list is %d\n",RecursivelyCountingNodes(first));
    printf("The sum of the values of the nodes in the linked list is %d\n",SumOfLinkedListValues(first));
    printf("The sum of the values of the nodes in the linked list by recursion is %d\n",RecursivelySumOfLinkedListValues(first));
    int mx = maxLL(first);
    printf("the maximum value in the linked list is %d\n",mx);
    printf("the maximum value in the linked list is %d\n",gettingMax(first));
    return 0;
}