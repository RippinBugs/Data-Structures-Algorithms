#include<bits/stdc++.h>
using namespace std;

//tn = tree node
//stn = stack node
int maxi = INT_FAST32_MAX;

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
void GenerateBST(int pre[],int len){
    struct tn *temp,*p;
    int i = 0;
    //first create the root.
    root = new tn;
    root->data = pre[i++];
    root->lc = root->rc = NULL;
    p = root;
    //cout<<root->data<<endl;
    while(i<len){
        //if pre[i]'s value is less than p->data then go to left. create node link it to p's left child. then push the 
        //address of p to stack. After that point p to the newly created node.
        if(pre[i] < p->data){
            temp = new tn;
            temp->data = pre[i++];
            temp->lc = temp->rc = NULL;
            p->lc = temp;
            stPush(p);
            p = temp;
        }
        else{
            //but if the pre[i]'s value is greater than p->data then first check the value(pre[i]) is in between stacktop 
            //and the p->data. if yes then do the below code. Also when the stack is empty check (pre[i]) value if it's lies
            //within positive infinity  and p->data. then also do the below procedure. Else just pop out the stack one time and
            //don't increment i.
            if(pre[i] > p->data && pre[i] < (stTop()?stTop()->data:maxi)){
                temp = new tn;
                temp->data = pre[i++];
                temp->lc = temp->rc = NULL;
                p->rc = temp;
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
    int pre[] = {1,2,3};
    int len = sizeof(pre) / sizeof(int);  
    GenerateBST(pre,len);
    inorder(root);
    return 0;
}