#include<bits/stdc++.h>
using namespace std;

//Insertion sort is stable and adaptive. thus the conditions inside the if else statement are provided according to it. 
struct node {
    int data;
    struct node *next;
}*first = NULL;

void InsertionSort(int val){
    struct node *q = NULL,*p = first;
    struct node *temp = new node;
    temp->data = val;
    //temp->next = NULL;

    //this part is for first element to be inserted and also when the value is less than the first's data.
    if(p == NULL || val < p->data){
        temp->next = p;
        first = temp;
    }
    //this part is for inbetween values and also for the last element.
    else{
        while(p && val >= p->data ){
            q = p;
            p = p->next;
        }
        temp->next = p;
        q->next = temp;
    }
}

void Display(struct node *p){
    printf("The sorted list is: ");
    while(p){
        printf("%d ",p->data);
        p = p->next;
    }
    cout<<endl;
}
int main(){
    InsertionSort(10);
    InsertionSort(12);
    InsertionSort(34);
    InsertionSort(34);
    InsertionSort(0);
    InsertionSort(50);
    InsertionSort(0);
    InsertionSort(9);
    InsertionSort(45);
    Display(first);
    return 0;
}