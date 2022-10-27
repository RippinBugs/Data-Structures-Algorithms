#include<bits/stdc++.h>
using namespace std;
int sizee = 10;  //Bucket size or Loading factor here is 10
struct node{
    int data;
    struct node *next;
};

struct node *ht[10] = {NULL};

void sortedInsert(int index,int key){
    struct node *p = ht[index];
    struct node *q = NULL;
    struct node *temp = new node;
    temp->data = key;
    temp->next = NULL;
//to make sure the location are set up properly. when using *p = ht[index] and use p inside if(), It doesn't change the location address permanently
//It is more like call by value than reference so instead use ht[index].
            //Or
//first of all make sure all locations of the array points to some valid address then you can use other pointer variables like *p = ht[index]
    if(p == NULL){
        ht[index] = temp;
    }
    else{
        //here p is used inside while so that we don't get into a situation, where p == NULL and we are doing p->data i.e NULL->data.
        while(p && p->data < key){
            q = p;
            p = p->next;
        }
        //when the value is at the first place 
        if(p == ht[index]){
            temp->next = p;
            p = temp;
        }
        //when the value is in between the values and also at the last place
        else{
            temp->next = p;
            q->next = temp;
        }
    }
}
int hashfn(int key){
    return key % sizee;
}

void insert(int key){
    int index = hashfn(key);
    sortedInsert(index,key);
}
void DeleteFn(int index,int key){
    struct node *p = ht[index];
    struct node *q = NULL;
    //for first element
    if(p->data == key){
        ht[index] = p->next;
        delete p;
    }
    //for any other element
    else{
        while(p){
            if(p->data == key){
                q->next = p->next;
                p = NULL;
                // if we delete p here then we will be deleting the looping variable
            }
            else{
                q = p;
                p = p->next;
            }
        }
        //so we delete p here.
        delete p;
    }
}
void deletee(int key){
    int index = hashfn(key);
    DeleteFn(index,key);
}
void Display(){
    for(int i =0;i<sizee;i++){
        printf("%d :",i);
        struct node *prin = ht[i];
        while(prin){
            printf("%d ",prin->data);
            prin = prin->next;
        }
        printf("\n");
    }
}

void search(int key){
        struct node *p = ht[hashfn(key)];
        while(p){
            if(p->data == key){
                printf("%d key found at %d row\n",p->data,hashfn(key));
                return ;
            }
            else{
                p = p->next;
            }
        }
    
    printf("not found\n");
}

int main(){
    
    insert(12);
    insert(22);
    insert(32);
    insert(11);
    insert(23);
    insert(24);
    insert(14);
    insert(156);

    Display();
    search(22);

    deletee(12);
    Display();
    return 0;
}