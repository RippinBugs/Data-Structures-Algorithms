#include<bits/stdc++.h>
using namespace std;

void heapifyMaxHeap(int a[],int n,int i){
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if(l<n && a[l] > a[largest])
        largest = l;
    if(r<n && a[r] > a[largest])
        largest = r;
    if(largest != i){
        swap(a[i],a[largest]);
        heapifyMaxHeap(a,n,largest);
    }
}

void heapifyMinHeap(int a[],int n,int i){
    int s=i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if(l<n && a[l] < a[s])
        s = l;
    if(r<n && a[r] < a[s])
        s = r;
    if(s != i){
        swap(a[i],a[s]);
        heapifyMinHeap(a,n,s);
    }
}

void Display(int a[],int n){
    for(int i = 0;i<n;i++){
        printf("%d ",a[i]);
    }
    cout<<endl;
}
int main(){
    int arr[] = {35,15,30,5,12,27,25,1,2,9,5,21,20,23};
    //int arr[] = {25,5,30,15,12,27,35};
    int len = sizeof(arr)/sizeof(int);

    //Building max heap
    for(int i = len/2-1;i>=0;i--)
        heapifyMaxHeap(arr,len,i);
    cout<<"max heap"<<endl;
    Display(arr,len);

    //Buildin min heap
    for(int i = len/2-1;i>=0;i--)
        heapifyMinHeap(arr,len,i);
    cout<<"min heap"<<endl;
    Display(arr,len);
    return 0;
}