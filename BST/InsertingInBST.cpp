#include<bits/stdc++.h>
using namespace std;

struct tree_node{
    struct tree_node *lc,*rc;
    int data;
}*root = NULL;

struct tree_node* CreateUsingInsert(struct tree_node *p,int val){
    struct tree_node* temp;
    if(!p){
        temp = new tree_node;
        temp->data = val;
        temp->lc = temp->rc = NULL;
        return temp;
    }
    if(val < p->data){
        p->lc = CreateUsingInsert(p->lc,val);
    }
    else if(val > p->data){
        p->rc = CreateUsingInsert(p->rc,val);
    }
    //in this case p will not be connected to any other node and simply will return.
    else if(val == p->data){
        return NULL;
    }
    return p;
}

void InsertAnElement(struct tree_node *r,int val){
    struct tree_node *t = NULL;
    while(r){
        t = r;
        if(r->data == val){
            return ;
        }
        else if(val < r->data){
            r = r->lc;
        }
        else{
            r = r->rc;
        }
    }
    struct tree_node *temp = new tree_node;
    temp->data = val;
    temp->lc = temp->rc = NULL;
    if(temp->data < t->data)
        t->lc = temp;
    else
        t->rc = temp;
}
void printInorder(struct tree_node* p){
    if(p){
        printInorder(p->lc);
        printf("%d ",p->data);
        printInorder(p->rc);
    }
}

int main(){
    root = CreateUsingInsert(root,78);
    CreateUsingInsert(root,12);
    CreateUsingInsert(root,1);
    CreateUsingInsert(root,120);
    CreateUsingInsert(root,23);
    CreateUsingInsert(root,23);
    CreateUsingInsert(root,23);
    CreateUsingInsert(root,45);
    CreateUsingInsert(root,10);
    CreateUsingInsert(root,76);
    printInorder(root);
    cout<<endl;
    int val;
    printf("Enter the value: ");
    cin>>val;
    InsertAnElement(root,val);
    printInorder(root);
 
}