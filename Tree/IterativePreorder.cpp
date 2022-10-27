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

struct stack_node{
    struct tree_node *val;
    struct stack_node *next;
}*top = NULL;

struct tree_node *root = NULL;

void push(struct tree_node *x){
    struct stack_node* temp = new stack_node;
    if(!temp){
        printf("heap overflow\n");
    }
    else{
        temp->val = x;
        temp->next = top;
        top = temp;
    }
}

struct tree_node* pop(){
    struct tree_node* x = NULL;
    struct stack_node* temp = top;
    if(top == NULL){
        printf("stack underflow\n");
    }
    else{
        x = top->val;
        top = top->next;
        delete temp;
    }
    return x;
}
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

bool isEmpty(struct stack_node *p){
    if(p == NULL)
        return 1;
    else
        return 0;
}

struct stack_node* stack_top(){
    if(top){
        return top;
    }
    else{
        return NULL;
    }
}
bool QisEmpty(struct Queue_node *p){
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
    while(!QisEmpty(front)){
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

void IterativePreOrder(struct tree_node* p){
    while(p || !isEmpty(top)){
        if(p){
            printf("%d ",p->data);
            push(p);
            p = p->lchild;
        }
        else{
            p = pop();
            p = p->rchild;
        }
    }
    cout<<endl;
}

void IterativeInOrder(struct tree_node* p){
    while(p || !isEmpty(top)){
        if(p){
            push(p);
            p = p->lchild;
        }
        else{
            p = pop();
            printf("%d ",p->data);
            p = p->rchild;
        }
    }
    cout<<endl;
}

void IterativePostOrder(struct tree_node* p){
    struct tree_node *prev = NULL;
    while(p || !isEmpty(top)){
        if(p){
            push(p);
            p = p->lchild;
        }
        else{
            //if we pop out the values now then root's position will be popped out too and it will lose track.
            p = stack_top()->val;
            if(p->rchild == NULL || p->rchild == prev){
                //first condition to check if a node's both child is null or not as lchild is already null.
                //second condtion is for checking to see both child of a node are went through or not.
                printf("%d ",p->data);
                pop();
                prev = p;
                p = NULL;
            }
            else{
                p = p->rchild;
            }
            
        }
    }
    cout<<endl;
}

int main(){
    TreeCreate();
    IterativePreOrder(root);
    IterativeInOrder(root);
    IterativePostOrder(root);
    return 0;
}