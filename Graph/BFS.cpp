#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *next;
}*first = NULL, *last = NULL;

void enqueue(int val){
    struct node *temp = new node;
    temp->data = val;
    temp->next = NULL;
    if(first == NULL){
        first = temp;
        last = first;
    }
    else{
        last->next = temp;
        last = temp;
    }
}
int dequeue(){
    int x=0;
    if(first == last){
        x = first->data;
        first = last = NULL;
    }
    else{
        struct node *p = first;
        x = p->data;
        first = first->next;
        delete p;
    }
    return x;
}
int isEmpty(){
    return ((first==NULL)?1:0);
}
void BreadthFirstSearch(int mtx[][8],int v[],int index){
    printf("%d ",index);
    v[index] = 1;
    enqueue(index);
    while(!isEmpty()){
        int val = dequeue();
        for(int i=1;i<8;i++){
            if(mtx[val][i] == 1 && v[i]==0){
                printf("%d ",i);
                v[i] = 1;
                enqueue(i);
            }
        }
    }
}
int main(){
    int x;
    // cout<<"Enter the number of vertices:  ";
    // //add one for vertices to work properly.
    // cin>>n;
    int adjacency_matrix[8][8] ={{0,0,0,0,0,0,0,0},
                                 {0,1,1,1,0,0,0,0},
                                 {0,1,0,1,0,0,0,0},
                                 {0,1,1,0,1,1,0,0},
                                 {0,1,0,1,0,1,0,0},
                                 {0,0,0,1,1,0,1,1},
                                 {0,0,0,0,0,1,0,0},
                                 {0,0,0,0,0,1,0,0}};
    // for(int i = 1;i<n;i++){
    //     for(int j = 1;j<n;j++){
    //         cout<<"Enter value for am[%d][%d]: ";
    //         cin>>x; //it is either 0 or 1 according to if there is a path or not.
    //         adjacency_matrix[i][j] = x;
    //     }
    // }
    int visited[8] = {0};
    printf("Enter any vertex: ");
    cin>>x;
    BreadthFirstSearch(adjacency_matrix,visited,x);
    return 0;
}