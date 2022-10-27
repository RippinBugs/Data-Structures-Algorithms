#include<bits/stdc++.h>
using namespace std;
struct node {
    int data;
    struct node *next;
};
int maximum(int a[],int len){
    int mx = 0;
    for(int i=0;i<len;i++){
        if(mx < a[i]){
            mx = a[i];
        }
    }
    //cout<<mx<<endl;
    return mx;
}
void insert(struct node *b[],int val){
    struct node *temp = new node;
    temp->data = val;
    temp->next = NULL;
    if(b[val] == NULL)
        b[val] = temp;
    else{
        temp->next =  b[val];
        b[val] = temp;
    }
}

void Delete(struct node *p,int a[]){
    static int i = 0;
    struct node *q = p;
    if(p == NULL)
        return;
    else{
        while(p){
            struct node *q = p;
            cout<<q->data<<endl;;
            a[i++] = q->data;
            p = q->next;
            delete q;
        }
    }
}
void Bin_BucketSort(int a[],int m,int len){
    struct node *b[m] = {NULL};
    
    for(int i=0;i<len;i++){
        //printf("%d ",b[i]);
        insert(b,a[i]);
    }
    for(int i = 0;i<m;i++){
        Delete(b[i],a);
    }
    for(int i = 0;i<len;i++){
        printf("%d " ,a[i]);
    }
}
int main(){
    int a[] = {1,2,5,6,8,3,3,5,7,9,10,14,8,15,19};
    int len = sizeof(a)/sizeof(int);
    int m = maximum(a,len);
    Bin_BucketSort(a,m+1,len);
}