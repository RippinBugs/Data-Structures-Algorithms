/* this seemed tough at first but concept wise it's easy*/

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

void DeleteAtBegin()
{
    struct node *temp;
    if(first == NULL){
        printf("no nodes to delete\n");
    }
    else{
        temp = first;
        first = first->next;
        if(first){
            first->previous = NULL;
        }
        else{
            last =NULL; // when there is one node, then you point the last node to null.
        }
        temp->next = NULL;
        delete temp;
    }
}

int DLL_length()
{
    struct node *p = first;
    int i = 0;
    while(p){
        i++;
        p = p->next;
    }
    return i;
}

void DeleteAtAny(int pos)
{   
    if(pos<0 || pos>DLL_length()){
        printf("not valid\n");
        return ;
    }
    struct node *p = first;
    if(first == last){
        DeleteAtBegin();
    }
    else{
        struct node *temp;
        int l = DLL_length();
        for(int i = 1;i<pos-1;i++){
            p = p->next;
        }
        
        temp = p->next;
        //moving the last pointer to point at the last node.
        if(temp->next==NULL)
            last = p;
        p->next = temp->next;
        if(temp->next){
            temp->next->previous = p;
        }
        temp->next = temp->previous =NULL;
        delete temp;
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
    //DeleteAtBegin();
    Display();
    insertAtBegin(12);
    insertAtAny(1,23);
    insertAtAny(1,40);
    insertAtAny(3,100);
    Display();

    DeleteAtAny(7);
    Display();
    DeleteAtBegin();
    Display();
    DeleteAtAny(4);
    Display();
    return 0;

}