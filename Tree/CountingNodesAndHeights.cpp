#include<bits/stdc++.h>
using namespace std;

struct Queue_node{
    struct tree_node* data;
    struct Queue_node* next;
}*front = NULL, *rear = NULL;

struct tree_node{
    struct tree_node *lchild;
    int data;
    struct tree_node *rchild;
};

struct tree_node *root = NULL;

void enqueue(struct tree_node *val){
    struct Queue_node *temp = new Queue_node;
    if(temp == NULL){
        printf("heap is full thus queue is full\n");
    }
    else{
        temp->data = val;
        temp->next = NULL;
        if(front == NULL){
            front = rear = temp;
        }
        else{
            rear->next = temp;
            rear = temp;
        }
    } 
}

struct tree_node* dequeue(){
    struct Queue_node *p = front;
    struct tree_node* x = NULL;
    if(front == NULL){
        printf("queue is empty\n");
    }
    else{
        x = p->data;
        front = front->next;
        delete p;
    }
    return x;
}

bool isEmpty(struct Queue_node *p){
    if(p == NULL)
        return 1;
    else
        return 0;
}
void TreeCreate(){
    struct tree_node *p,*t;
    int x;
    printf("enter root value: ");
    cin>>x;
    root = new tree_node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(root);
    while(!isEmpty(front)){
        p = dequeue();
        printf("enter left child of %d (if -1 then no lchild): ",p->data);
        cin>>x;
        if(x!=-1){
            t = new tree_node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(t);
        }
        printf("enter right child of %d (if -1 then no rchild): ",p->data);
        cin>>x;
        if(x!=-1){
            t = new tree_node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(t);
        }
    }
}

int countNodes(struct tree_node* p){
    int x,y;
    if(p){
        x = countNodes(p->lchild);
        y = countNodes(p->rchild);
        //when both x and y equal to zero add 1. that means we count a node.
        return x+y+1;
    }
    return 0;
}

int countNodesOfDegreeTwo(struct tree_node* p){
    int x,y;
    if(p){
        x = countNodesOfDegreeTwo(p->lchild);
        y = countNodesOfDegreeTwo(p->rchild);
        if(p->lchild && p->rchild){
            return x+y+1;
        }
        else 
            return x+y;
    }
    return 0;
}

int NodesWithDegreeOne(struct tree_node* p){
    int x,y;
    if(p){
        x = NodesWithDegreeOne(p->lchild);
        y = NodesWithDegreeOne(p->rchild);
        // if((p->lchild && !p->rchild) || (!p->lchild && p->rchild))
        //     return x+y+1;
        //this is because it's like xor function L xor R = LR' || L'R
        if(p->lchild != NULL ^ p->rchild != NULL)
            return x + y + 1;
        else
            return x+y;
    }
    return 0;
}
int countHeight(struct tree_node* p){
    // int x,y;
    // if(p){
    //     x = countHeight(p->lchild);
    //     y = countHeight(p->rchild);
    //     if(x>y){
    //         return x+1;
    //     }
    //     else
    //         return y+1;
    // }
    // return -1;
    if(p==NULL){
        return -1;
    }
    else{
        return (1 + max(countHeight(p->lchild),countHeight(p->rchild)));
    }
}

int leafNode(struct tree_node* p){
    if(p){
        if(p->lchild == NULL && p->rchild == NULL){
            return 1;
        }
        else{
            return leafNode(p->lchild) + leafNode(p->rchild);
        }   
    }
    return 0;
}
int main(){
    TreeCreate();
    cout<<"the number of nodes is: "<<countNodes(root)<<endl;
    cout<<"the number of nodes with degree two is: "<<countNodesOfDegreeTwo(root)<<endl;
    cout<<"the height is: "<<countHeight(root)<<endl;
    cout<<"the number of leaf nodes is: "<<leafNode(root)<<endl; 
    cout<<"the number of nodes with degree one is: "<<NodesWithDegreeOne(root)<<endl;
    return 0;
}