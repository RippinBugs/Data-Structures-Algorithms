#include<bits/stdc++.h>
using namespace std;

struct tree_node{
    struct tree_node *lc,*rc;
    int data;
}*root = NULL,*pre = NULL,*suc = NULL;

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
    // else if(val == p->data){
    //     return temp;
    // }
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

void pre_suc(struct tree_node *r,struct tree_node *&pre,struct tree_node *&suc, int key){
    if(r== NULL){
        return ;
    }
    if(r->data == key){
        if(r->lc){
            struct tree_node *temp = r->lc;
            while(temp->rc){
                temp = temp->rc;
            }
            pre = temp;
        }
        if(r->rc){
            struct tree_node *temp = r->rc;
            while(temp->lc){
                temp = temp->lc;
            }
            suc = temp;
        }
        //return;
    }
    else if(key < r->data){
        suc = r;
        pre_suc(r->lc,pre,suc,key);
    }
    else if(key>r->data){
        pre = r;
        pre_suc(r->rc,pre,suc,key);
    }
}

int main(){
    root = CreateUsingInsert(root,78);
    CreateUsingInsert(root,12);
    CreateUsingInsert(root,1);
    CreateUsingInsert(root,120);
    CreateUsingInsert(root,23);
    CreateUsingInsert(root,23);
    CreateUsingInsert(root,10);
    CreateUsingInsert(root,76);
    printInorder(root);
    cout<<endl;
    pre_suc(root,pre,suc,50);
    if(pre){
        cout<<"predecessor: "<<pre->data<<endl;
    }
    if(suc){
        cout<<"succssor: "<<suc->data<<endl;
    }
    return 0;
}


//The node *& is a reference to a pointer, whereas node* is simply a pointer.
//In that way, node *& adds an additional level of indirection 
//and it is basically a second name for some node * (pointer to node). It is most frequently used for argument passing.