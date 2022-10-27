#include<bits/stdc++.h>
using namespace std;

struct tree_node{
    struct tree_node *lchild;
    int data;
    struct tree_node *rchild;
};

int searchIndex(int arr[],int start,int end,int val);

tree_node* buildTree(int in[],int post[],int inStart,int inEnd){
    static int postIndex = inEnd;
    if(inStart > inEnd){
        return NULL;
    }
    tree_node* temp = new tree_node;
    temp->data = post[postIndex--];
    temp->rchild = temp->lchild = NULL;
    if(inStart == inEnd){
        return temp;
    }
    int inIndex = searchIndex(in,inStart,inEnd,temp->data);

    temp->rchild = buildTree(in,post,inIndex+1,inEnd);
    temp->lchild = buildTree(in,post,inStart,inIndex-1);
    

    return temp;
}

int searchIndex(int arr[],int start,int end,int val){
    for(int i = start;i<=end;i++){
        if(arr[i] == val){
            return i;
        }
    }
    return 0;
}

void inorderTraversal(struct tree_node* p){
    if(p){
        inorderTraversal(p->lchild);
        printf("%d ",p->data);
        inorderTraversal(p->rchild);
    }
}
int main(){
    int in[] = { 4, 8, 2, 5, 1, 6, 3, 7 };
    int post[] = { 8, 4, 5, 2, 6, 7, 3, 1 };
    int len = sizeof(in)/sizeof(int);
    tree_node* root = buildTree(in,post,0,len-1);
    inorderTraversal(root);

    return 0;
}