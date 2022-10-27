#include<bits/stdc++.h>
using namespace std;

// int s = -1;
// void InsertionSort(int a[],int key){
//     s++;
//     int x;
//     if(s<100){   
//         int j = s-1;
//         x = key;
//         while(j>-1 && a[j] > x){
//             a[j+1] = a[j];
//             j--;
//         }
//         a[j+1] = x;
//     }
// }

//but insertion sort is by nature adaptive as the inner loop does very less work if the array is already sorted 
// or partially sorted.
void insertionSort(int b[],int n){
    int temp;
    for(int i = 1;i<n;i++){
        int j = i-1;
        temp = b[i]; //keeping the ith value for later used 
        while(j>-1 && b[j] > temp){
            b[j+1] = b[j];
            j--;
        }
        b[j+1] = temp;
    }
}
void Display(int a[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}
int main(){
    // int arr[100];
    // InsertionSort(arr,0);
    // InsertionSort(arr,12);
    // InsertionSort(arr,0);
    // InsertionSort(arr,87);
    // InsertionSort(arr,1);
    // InsertionSort(arr,0);
    // Display(arr,s+1);
    // cout<<endl;

    int brr[] = {1,4,2,5,4,19};
    int size = sizeof(brr)/sizeof(int);
    insertionSort(brr,size);
    Display(brr,size);
    return 0;
}