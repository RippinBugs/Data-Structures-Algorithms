#include<bits/stdc++.h>
using namespace std;

void insertMaxHeap(int a[],int n){
    int temp,i = n;
    temp = a[i];
    //max heap
    //i-1 will make it look more like a binary tree with small valu
    while(i>0 && temp > a[(i-1)/2]){
        a[i] = a[(i-1)/2];
        i = (i-1)/2;
    }
    a[i] = temp;
}

void insertMinHeap(int a[],int n){
    int temp,i = n;
    temp = a[i];
    //min heap
    //i-1 will make it look more like a binary tree with small valu
    while(i>0 && temp < a[(i-1)/2]){
        a[i] = a[(i-1)/2];
        i = (i-1)/2;
    }
    a[i] = temp;
}
void Delete(int a[],int n){
    //j will point to left child of i and i will point to the head node
    int i=0,j=2*i+1;
    int x = a[i];
    a[i] = a[n-1];
    while(j<n){
        if(a[j+1] > a[j])
            j = j+1;
        if(a[i] < a[j]){
            swap(a[i],a[j]);
            i = j;
            j = 2*i + 1;
        }
        else
            break;
    }
    printf("Deleted value is %d\n",x);
}
void display(int a[],int n){
    for(int i = 0;i<n;i++){
        printf("%d ",a[i]);
    }
}

int main(){
    int arr[] = {10,20,30,25,5,40,35};
    int len = sizeof(arr)/sizeof(int);
    for(int i = 1;i<len;i++){
        insertMinHeap(arr,i);
    }
    display(arr,len);
    cout<<endl;
    
    for(int i = 1;i<len;i++){
        insertMaxHeap(arr,i);
    }
    display(arr,len);
    cout<<endl;
    
    Delete(arr,len);
    display(arr,len);
    return 0;
}