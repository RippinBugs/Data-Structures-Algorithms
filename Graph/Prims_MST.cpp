#include<bits/stdc++.h>
using namespace std;

#define I INT32_MAX
#define n 7 

int main(){
    int cost[][8]= {{I,I,I,I,I,I,I,I}, 
                {I,I,25,I,I,I,5,I}, 
                {I,25,I,12,I,I,I,10}, 
                {I,I,12,I,8,I,I,I}, 
                {I,I,I,8,I,16,I,6}, 
                {I,I,I,I,16,I,20,1}, 
                {I,5,I,I,I,20,I,I}, 
                {I,I,10,I,6,1,I,I}};

    int near[8]={I,I,I,I,I,I,I,I}; 
    int t[2][6];
    int i,j,u,v;
    int min = I;
    for(i=1;i<=n;i++){
        for(j=1;j<i;j++){
            if(cost[i][j] < min){
                min =cost[i][j];
                u = i; v=j;
            }
        }
    }
    t[0][0] = u;
    t[1][0] = v;
    near[u] = near[v] = 0;
    cout<<"Prim's Minimum Spanning Tree: "<<endl;
    cout<<v<<" ----> "<<u<<"  "<<min<<endl;

    for(i = 1;i<n-1;i++){
        for(j=1;j<=n;j++){
            if(cost[u][j] < cost[v][j] && near[j]!=0){
                near[j] = u;
            }
            else if(cost[u][j] >= cost[v][j] && near[j]!=0){
                near[j] = v;
            }
        }
        min = I;
        for(int k=1;k<=n;k++){
            if(cost[k][near[k]] < min){
                min = cost[k][near[k]];
                u = k;
                v = near[k];
            }
        }
        t[0][i] = u;
        t[1][i] = v;
        near[u] = near[v] = 0;
        cout<<v<<" ----> "<<u<<"  "<<min<<endl;

    }
    return 0;
}