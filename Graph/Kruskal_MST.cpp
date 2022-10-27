#include<bits/stdc++.h>
using namespace std;

#define I INT32_MAX
int n = 7,e = 9;
int edge[3][9] = {{1,1,2,2,3,4,4,5,5},
                  {2,6,3,7,4,5,7,6,7},
                  {25,5,12,10,8,16,14,20,18}};

int s[8] = {-1,-1,-1,-1,-1,-1,-1,-1}; //for the set
int included[9] = {0};

void unionUV(int u,int v){
    if(s[u] < s[v]){
        s[u] = s[u] + s[v];
        s[v] = u;
    }
    else{
        s[v] = s[u] + s[v];
        s[u] = v;
    }
}

int find(int ix){
    int x = ix;
    while(s[x]>0){
        x = s[x];
    }
    return x;
}

int main(){
    int t[2][6];
    int i,j,k,min,u,v;
    while(i < n-1){
        min = I;
        for(j=0;j<e;j++){
            if(included[j] == 0 && edge[2][j] < min){
                min = edge[2][j];
                u = edge[0][j];
                v = edge[1][j];
                k = j;
            }
        }
        if(find(u) != find(v)){
            unionUV(find(u),find(v));
            t[0][k] = u;
            t[1][k] = v;
            i++;
            printf("%d ----> %d : %d\n",u,v,edge[2][k]);
        }
        included[k] = 1;
    }
    return 0;
}