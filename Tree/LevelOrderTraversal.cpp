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
        printf("enter left child(if -1 then no lchild): ");
        cin>>x;
        if(x!=-1){
            t = new tree_node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(t);
        }
        printf("enter right child(if -1 then no rchild): ");
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

void LevelOrderTraversal(struct tree_node *p){
    printf("%d ",p->data);
    enqueue(p);
    while(!isEmpty(front)){
        p = dequeue();
        if(p->lchild){
            printf("%d ",p->lchild->data);
            enqueue(p->lchild);
        }
        if(p->rchild){
            printf("%d ",p->rchild->data);
            enqueue(p->rchild);
        }
    }
}
int main(){
    TreeCreate();
    LevelOrderTraversal(root);
    return 0;
}