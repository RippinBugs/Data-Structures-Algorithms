#include<bits/stdc++.h>
using namespace std;
//tn = tree node
struct tn{
    int data;
    struct tn *lc,*rc;
}*root = NULL;

struct tn* createUsingInsert(struct tn *r,int val){
    struct tn *temp;
    if(r == NULL){
        temp = new tn;
        temp->data = val;
        temp->rc = temp->lc = NULL;
        return temp;
    }
    else{
        if(val < r->data){
            r->lc = createUsingInsert(r->lc,val);
        }
        else if(val > r->data){
            r->rc = createUsingInsert(r->rc,val);
        }
    }
    return r;
}
struct tn *minBST(struct tn *p){
    if(p == NULL)
        return NULL;
    else{
        struct tn *temp = p;
        while(temp->lc){
            temp = temp->lc;
        }
        return temp;
    }
}
struct tn *maxBST(struct tn *p){
    //if tree is empty
    if(p == NULL)
        return NULL;
    //if tree is containing even a single element
    else{
        struct tn *temp = p;
        while(temp->rc){
            temp = temp->rc;
        }
        return temp;
    }
}
void printInorder(struct tn *p){
    if(p){
        printInorder(p->lc);
        printf("%d ",p->data);
        printInorder(p->rc);
    }
}
int main(){
    //if tree contains a single element then both the min and max value will be same.
    root = createUsingInsert(root,12);
    // createUsingInsert(root,23);
    // createUsingInsert(root,11);
    // createUsingInsert(root,13);
    // createUsingInsert(root,22);
    // createUsingInsert(root,111);
    // createUsingInsert(root,110);
    // createUsingInsert(root,231);
    // createUsingInsert(root,1);
    // createUsingInsert(root,19);
    printInorder(root);
    struct tn *val = minBST(root);
    if(val){
        cout<<"min value is: "<<val->data<<endl;
    }
    else{
        cout<<"empty tree"<<endl;
    }
    val = maxBST(root);
    if(val){
        cout<<"max value is: "<<val->data<<endl;
    }
    else{
        cout<<"empty tree"<<endl;
    }
    return 0;
}