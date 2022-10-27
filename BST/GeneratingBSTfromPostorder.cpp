#include<bits/stdc++.h>
using namespace std;

//tn = tree node
//stn = stack node
int mini = INT_FAST32_MIN;

struct tn{
    int data;
    struct tn *rc,*lc;
}*root = NULL,*xxx = NULL;

struct stn{
    struct tn *add;
    struct stn *next;
}*top = NULL;

void stPush(struct tn *p){
    struct stn *temp = new stn;
    if(!temp){
        cout<<"stack overflow"<<endl;
        return ;
    }
    temp->add = p;
    temp->next = top;
    top = temp;
}

struct tn* stTop(){
    if(!top){
        //cout<<"stack underflow stacktop\n"<<endl;
        return NULL;
    }
    else{
        return top->add;
    }
}
struct tn* stpop(){
    if(top->add == NULL){
        cout<<"stack underflow\n"<<endl;
        return NULL;
    }
    else{
        struct stn *temp = top;
        top = top->next;
        temp->next = NULL;
        return temp->add;
    }
}
void GenerateBST(int post[],int len){
    struct tn *temp,*p;
    int i = len-1;
    root = new tn;
    root->data = post[i--];
    root->lc = root->rc = NULL;
    p = root;
    while(i>=0){
        if(post[i] > p->data ){
            temp = new tn;
            temp->data = post[i--];
            temp->lc = temp->rc = NULL;
            p->rc = temp;
            stPush(p);
            p = temp;
        }
        else{
            if((stTop()?stTop()->data:mini) < post[i] && p->data > post[i]){
                temp = new tn;
                temp->data = post[i--];
                temp->lc = temp->rc = NULL;
                p->lc = temp;
                p = temp;
            }
            else{
                p = stpop();
            }
        }
    }
}
void inorder(struct tn *p){
    if(p){
        inorder(p->lc);
        printf("%d ",p->data);
        inorder(p->rc);
    }
}
int main(){
    //cout<<maxi<<endl;
    int post[] = {15,10,25,20,45,50,40,30};
    int len = sizeof(post) / sizeof(int);  
    GenerateBST(post,len);
    inorder(root);
    return 0;
}