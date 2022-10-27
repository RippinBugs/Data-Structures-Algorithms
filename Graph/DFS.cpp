#include<bits/stdc++.h>
using namespace std;


void DepthFirstSearch(int mtx[][8],int index){
    static int visited[8]={0};
    printf("%d ",index);
    visited[index] = 1;
    for(int i=1;i<8;i++){
        if(mtx[index][i] == 1 && visited[i]==0){
            DepthFirstSearch(mtx,i);
        }
    }
}
int main(){
    int x;
    int adjacency_matrix[8][8] ={{0,0,0,0,0,0,0,0},
                                 {0,1,1,1,0,0,0,0},
                                 {0,1,0,1,0,0,0,0},
                                 {0,1,1,0,1,1,0,0},
                                 {0,1,0,1,0,1,0,0},
                                 {0,0,0,1,1,0,1,1},
                                 {0,0,0,0,0,1,0,0},
                                 {0,0,0,0,0,1,0,0}};
    printf("Enter any vertex: ");
    cin>>x;
    DepthFirstSearch(adjacency_matrix,x);
    return 0;
}