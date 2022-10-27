#include<bits/stdc++.h>
using namespace std;

struct tree_node{
    struct tree_node *lchild;
    int data;
    struct tree_node *rchild;
};

int searchIndex(int arr[],int start,int end,int val);

tree_node* buildTree(int in[],int pre[],int inStart,int inEnd){
    static int preIndex = 0;
    if(inStart > inEnd){
        return NULL;
    }
    tree_node* temp = new tree_node;
    temp->data = pre[preIndex++];
    temp->rchild = temp->lchild = NULL;
    if(inStart == inEnd){
        return temp;
    }
    int inIndex = searchIndex(in,inStart,inEnd,temp->data);

    temp->lchild = buildTree(in,pre,inStart,inIndex-1);
    temp->rchild = buildTree(in,pre,inIndex+1,inEnd);

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
    int in[] = { 9, 8, 4, 2, 10, 5, 10, 1, 6, 3, 13, 12, 7 };
    int pre[] = { 1, 2, 4, 8, 9, 5, 10, 10, 3, 6, 7, 12, 13 };
    int len = sizeof(in)/sizeof(int);
    tree_node* root = buildTree(in,pre,0,len-1);
    inorderTraversal(root);

    return 0;
}