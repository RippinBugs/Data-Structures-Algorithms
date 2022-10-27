#include<bits/stdc++.h>
using namespace std;

int partition(int a[],int l,int h){
    int pivot = a[l];
    int i = l,j = h;
    while(i<j){
        do{i++;}while(pivot >= a[i]);
        do{j--;}while(pivot < a[j]);
        if(i<j)
            swap(a[i],a[j]);
    }
    //printf("%d %d %d\n",pivot,a[l],a[j]);
    // why not pivot instead of a[l], because pivot is a variable and we are swapping array elements.
    swap(a[l],a[j]);
    return j;
}

void quickSort(int a[],int l,int h){
    if(l<h){
        int j = partition(a,l,h);
        quickSort(a,l,j);
        quickSort(a,j+1,h);
    }
}

void Display(int a[],int n){
    printf("The sorted list is: ");
    for(int i = 0;i<n-1;i++){
        printf("%d ",a[i]);
    }
    cout<<endl;
}

int main(){
    //Here int32_max is an end of list marker(largest number)
    int arr[] = {5,7,6,9,4,8,1,2,3,INT32_MAX}; 
    int size = sizeof(arr)/sizeof(int);
    quickSort(arr,0,size-1);
    Display(arr,size);
    return 0;
}