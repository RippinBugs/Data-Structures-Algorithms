#include<bits/stdc++.h>
using namespace std;

//c = child
struct tree_node{
    struct tree_node *lc,*rc;
    int data;
}*root = NULL;

struct tree_node* CreatUsingInsert(struct tree_node *p,int val){
    struct tree_node* temp;
    if(!p){
        temp = new tree_node;
        temp->data = val;
        temp->lc = temp->rc = NULL;
        return temp;
    }
    if(val < p->data){
        p->lc = CreatUsingInsert(p->lc,val);
    }
    else{
        p->rc = CreatUsingInsert(p->rc,val);
    }
    return p;
}

void printInorder(struct tree_node* p){
    if(p){
        printInorder(p->lc);
        printf("%d ",p->data);
        printInorder(p->rc);
    }
}

struct tree_node* searchKey(struct tree_node* p,int key){
    if((!p) || (p->data == key)){
        return p;
    }
    else if(key < p->data){
        return searchKey(p->lc, key);
    }
    else{
        return searchKey(p->rc,key);
    }
}

struct tree_node* iterativeSearch(struct tree_node *p,int key){
    while(p){
        if(p->data == key){
            return p;
        }
        else if(key < p->data){
            p = p->lc;
        }
        else{
            p = p->rc;
        }
    }
    return NULL;
}

int main(){
    root = CreatUsingInsert(root,78);
    CreatUsingInsert(root,12);
    CreatUsingInsert(root,1);
    CreatUsingInsert(root,120);
    CreatUsingInsert(root,23);
    CreatUsingInsert(root,45);
    printInorder(root);
    printf("\n");
    if(iterativeSearch(root,1200)){
        printf("Key found\n");
    }
    else{
        printf("key not found\n");
    }

    if(searchKey(root,2300)){
        printf("key found\n");
    }
    else{
        printf("key not found\n");
    }

}

//Search complexity is O(logn)
//Basically depends on tree height.