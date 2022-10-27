#include<bits/stdc++.h>
using namespace std;

int len;
void merging(int a[],int l,int mid,int h){
    int b[len];
    int i,j,k;
    //i is the value for the start of the initial sub array
    //j is the value for the start of the last sub array
    //k is assigned the value from where it should start working on the values.
    i = l; j=mid+1; k = l;
    while(i<=mid && j<=h){
        if(a[i] <= a[j]){
            b[k++] = a[i++];
        }
        else{
            b[k++] = a[j++];
        }
    }
    while(i<=mid){
        b[k++] = a[i++];
    }
    while(j<=h){
        b[k++] = a[j++];
    }
    for(int x=l;x<=h;x++){
        a[x] = b[x];
    }
}

void ImergeSort(int a[],int n){
    int p,i,l,mid,h;
    // no of passes is logn 
    for(p = 2; p<=n ;p=p*2){
        for(i=0; i+p-1<n; i=i+p){
            l = i;
            h = i+p-1;
            mid = (l+h)/2;
            merging(a,l,mid,h);
        }
    }
    //in case if there are odd number of elements
    if(p/2 < n){
        merging(a,0,p/2,n-1);
    }
}

void Display(int a[]){
   for(int x=0;x<len;x++){
        printf("%d ",a[x]);
    }
    cout<<endl;
}

int main(){
    int a[] = {1,2,5,6,8,3,3,5,7,9,10,14};
    len = sizeof(a)/sizeof(int);
    //printf("%d ",len);
    ImergeSort(a,len);
    Display(a);
    return 0;
}