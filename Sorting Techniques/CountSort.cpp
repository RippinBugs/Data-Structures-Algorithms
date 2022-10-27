#include<bits/stdc++.h>
using namespace std;

int maximum(int a[],int len){
    int mx = 0;
    for(int i=0;i<len;i++){
        if(mx < a[i]){
            mx = a[i];
        }
    }
    cout<<mx<<endl;
    return mx;
}

void countSort(int a[],int m,int len){
    int b[m] = {0};
    //In this part, we use the values of the elements as indices for another array and according to their repetition
    //we increment the value inside those indexed positions by one.
    for(int i=0;i<len;i++){
        b[a[i]]++;
    }
    int i = 0,j=0;
    while(i<m){
        if(b[i] > 0){
            a[j++] = i;
            b[i]--;
        }
        else{
            i++;
        }
    }
}
void Display(int a[],int len){
   for(int x=0;x<len;x++){
        printf("%d ",a[x]);
    }
    cout<<endl;
}

int main(){
    int a[] = {1,2,5,6,8,3,3,5,7,9,10,14,8,15,19};
    int len = sizeof(a)/sizeof(int);
    int m = maximum(a,len);
    //cout<<m<<endl;
    
    countSort(a,m+1,len);
    Display(a,len);
    return 0;
}