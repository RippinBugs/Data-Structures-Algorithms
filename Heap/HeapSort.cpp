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
void DeleteMaxHeap(int a[],int n){
    //j will point to left child of i and i will point to the head node
    int i=0,j=2*i+1;
    int x = a[i];
    a[i] = a[n-1];
    while(j<n-1){
        //the condition n-1 means a value inside array is already deleted so the length will be 1 less.
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
    a[n-1] = x;
    //printf("Deleted value is %d\n",x);

}

void DeleteMinHeap(int a[],int n){
    //j will point to left child of i and i will point to the head node
    int i=0,j=2*i+1;
    int x = a[i];
    a[i] = a[n-1];
    while(j<n-1){
        //the condition n-1 means a value inside array is already deleted so the length will be 1 less.
        if(a[j+1] < a[j])
            j = j+1;
        if(a[i] > a[j]){
            swap(a[i],a[j]);
            i = j;
            j = 2*i + 1;
        }
        else
            break;
    }
    a[n-1] = x;
    //printf("Deleted value is %d\n",x);

}

void HeapSortMxH(int a[],int n){
    for(int i = 0;i<n;i++){
        DeleteMaxHeap(a,n-i);
    }
}

void HeapSortMH(int a[],int n){
    for(int i = 0;i<n;i++){
        DeleteMinHeap(a,n-i);
    }
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
        insertMaxHeap(arr,i);
    }
    display(arr,len);
    cout<<endl;
    cout<<"Heap Sort using Max Heap"<<endl;
    HeapSortMxH(arr,len);
    display(arr,len);
    cout<<endl;

    for(int i = 1;i<len;i++){
        insertMinHeap(arr,i);
    }
    display(arr,len);
    cout<<endl;
    cout<<"Heap Sort using Min Heap"<<endl;
    HeapSortMH(arr,len);
    display(arr,len);

    return 0;
}

//Using maxheap we can sort the array in ascending order
//Using minheap we can sort the array in descending order