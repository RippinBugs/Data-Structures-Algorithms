#include<bits/stdc++.h>
using namespace std;

int len;
void Merge(int a[],int l,int mid,int h){
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
void RmergeSort(int a[],int l,int h){
    if(l<h){
        int mid = (l+h)/2;
        RmergeSort(a,l,mid);
        RmergeSort(a,mid+1,h);
        Merge(a,l,mid,h);
    }
}
void Display(int a[]){
   for(int x=0;x<len;x++){
        printf("%d ",a[x]);
    }
    cout<<endl;
}

int main(){
    int a[] = {1,2,5,6,8,3,3,5,7,9,10,14,8};
    len = sizeof(a)/sizeof(int);
    //printf("%d ",len);
    RmergeSort(a,0,len-1);
    Display(a);
    return 0;
}