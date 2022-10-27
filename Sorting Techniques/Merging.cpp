#include<bits/stdc++.h>
using namespace std;

void mergeSort2(int a[],int len,int n){
    int b[len];
    //n gives the value of partitioned point of sorted values and thus we work accordingly to it
    int i=0,j=n+1,k=0;
    while(i<n+1 && j<len){
        if(a[i]<=a[j]){
            b[k++] = a[i++];
        }
        else{
            b[k++] = a[j++];
        }
    }
    while(i<n+1){
        b[k++] = a[i++];
    }
    while(j<len){
        b[k++] = a[j++];
    }
    for(int i = 0;i<len;i++){
        printf("%d ",b[i]);
    }
}

void mergeSort(int a[],int b[],int m,int n){
    //This combines two sorted arrays into one sorted array.
    int c[m+n];
    int i,j,k;
    i = j = k = 0;
    while(i<m && j<n){
        if(a[i]<=b[j]){
            c[k++] = a[i++];
        }
        else{
            c[k++] = b[j++];
        }
    }
    while(i<m){
        c[k++] = a[i++];
    }
    while(j<n){
        c[k++] = b[j++];
    }

    for(int i = 0;i<m+n;i++){
        printf("%d ",c[i]);
    }
}
int main(){
    int a[] = {1,2,5,6,8};
    int b[] = {3,3,5,7,9,10,14};
    int len_a = sizeof(a)/sizeof(int);
    int len_b = sizeof(b)/sizeof(int);
    cout<<"Merge sort by combining two sorted arrays: ";
    mergeSort(a,b,len_a,len_b);
    cout<<endl;

    int c[] = {1,2,5,6,8,3,3,5,7,9,10,14};
    int len_c = sizeof(c)/sizeof(int);
    int i = 0;
    while(1){
        if(c[i]>c[i+1]){
            break;
        }
        i++;
    }

    cout<<"Merge sort when two different list of sorted values lies inside one array: ";
    mergeSort2(c,len_c,i);
    cout<<endl;
    return 0;
}