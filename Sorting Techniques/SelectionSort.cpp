#include<bits/stdc++.h>
using namespace std;

void selectionSort(int a[],int n){
    int i,j,k;
    for(i=0;i<n-1;i++){
        j = k = i;
        //Finding the minimum element for that position
        for(j = i+1;j<n;j++){
            if(a[k] > a[j]){
                //moving k to j's position.
                k = j;
            }
        }
        //swapping the selected positional value with minimum value for that position
        swap(a[i],a[k]);
    }
}

void Display(int a[],int n){
    printf("The sorted list is: ");
    for(int i = 0;i<n;i++){
        printf("%d ",a[i]);
    }
    cout<<endl;
}

int main(){
    int arr[] = {8,3,6,4,1,1,1,0};
    int size = sizeof(arr)/sizeof(int);
    selectionSort(arr,size);
    Display(arr,size);
    return 0;
}