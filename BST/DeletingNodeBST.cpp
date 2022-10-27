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

void PreSuc(struct tn *r,struct tn *&pre,struct tn *&suc,int val){
    if(r == NULL)
        return ;
    if(val == r->data){
        if(r->lc){
            struct tn *temp = r->lc;
            while(temp->rc){
                temp = temp->rc;
            }
            pre = temp;
        }
        if(r->rc){
            struct tn *temp = r->rc;
            while(temp->lc){
                temp = temp->lc;
            }
            suc = temp;
        }
        return ;
    }
    else if(val < r->data){
        //if value is less than the root then root will be the successor
        suc = r;
        //repeat the process using recursion
        PreSuc(r->lc,pre,suc,val);
    }
    else{
        //if value is greater than the root,then root will be the predecessor.
        pre = r;
        PreSuc(r->rc,pre,suc,val);
    }
    return ;
}

int height(struct tn *r){
    
    if(r == NULL)
        return -1;
    else{
        return (max(height(r->lc) , height(r->rc)) + 1);
    }
}

struct tn* deleteNode(struct tn *r,int val){
    if(r == NULL){
        return r;
    }
    if(val < r->data){
        r->lc = deleteNode(r->lc,val);
    }
    else if(val > r->data){
        r->rc = deleteNode(r->rc,val);
    }
    else{
        // in this scope the value is found. and need to be deleted.
        //when there is no child. that is it's a leaf node.
        if(!r->lc && !r->rc){
            delete r;
            return NULL;
        }
        //when the node has two child.
        else if(r->lc && r->rc){
            //first get the suc and pre of that node.then depending upon the height of the tree use them wisely. 
            struct tn *pre = NULL,*suc = NULL;
            PreSuc(r,pre,suc,r->data);
            if(height(r->lc) > height(r->rc)){
                r->data = pre->data;
                r->lc = deleteNode(r->lc,pre->data);
            }
            else{
                r->data = suc->data;
                r->rc = deleteNode(r->rc,suc->data);
            }
        }
        else{
            struct tn *child = (r->lc)?r->lc:r->rc;
            struct tn *cur = r;
            r = child;
            delete cur;
        }
    }
    return r;
}
void printInorder(struct tn *p){
    if(p){
        printInorder(p->lc);
        printf("%d ",p->data);
        printInorder(p->rc);
    }
}
int main(){
    root = createUsingInsert(root,12);
    createUsingInsert(root,23);
    createUsingInsert(root,11);
    createUsingInsert(root,13);
    createUsingInsert(root,22);
    createUsingInsert(root,111);
    createUsingInsert(root,110);
    createUsingInsert(root,231);
    createUsingInsert(root,1);
    createUsingInsert(root,19);
    printInorder(root);
    struct tn *pre = NULL,*suc = NULL;
    PreSuc(root,pre,suc,23);
    if(pre){
        cout<<"predecessor: "<<pre->data<<endl;
    }
    if(suc){
        cout<<"succssor: "<<suc->data<<endl;
    }
    deleteNode(root,1);
    printInorder(root);
    return 0;
}