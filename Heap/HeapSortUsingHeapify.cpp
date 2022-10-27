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

void BuildMaxHeap(int a[],int n){
    for(int i = n/2-1;i>=0;i--)
        heapifyMaxHeap(a,n,i);
}

void Delete(int a[],int n){
    {
        //swapping the last and first element
        swap(a[n],a[0]);
        //after that we do heapifying but with one element less as we moved the first element to last
        // and it no longer in the heapify procedure.
        // the condition below works for all the non leaf nodes.
        for(int i = n/2-1;i>=0;i--){
            heapifyMaxHeap(a,n,i);
        }
        cout<<"heapify stage: ";
        for(int i=0;i<n;i++){
            printf("%d ",a[i]);
        }
        printf("\n");
    }
}


void HeapSort(int a[],int n){
    //Deleting every element to sort out the values
    for(int i =n-1;i>0;i--){
        Delete(a,i);
        cout<<"sorting stage: ";
        for(int i=0;i<n;i++){
            printf("%d ",a[i]);
        }
        printf("\n");
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
    BuildMaxHeap(arr,len);
    cout<<"max heap"<<endl;
    Display(arr,len);

    //HeapSort
    
    HeapSort(arr,len);
    cout<<"Heap sort is"<<endl;
    Display(arr,len);
    return 0;
}