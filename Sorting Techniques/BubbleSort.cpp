#include<bits/stdc++.h>
using namespace std;

//By nature it's not adaptive because even when the array is sorted the outer loop needs to run multiple times
// and we make it adaptive by using flag.
//i used flag here to see in which pass it becomes sorted and then as it gets sorted, we break the loop.
void BubbleSort(int a[],int n){
    int flag, pass_count = 0;
    for(int i = 0;i<n-1;i++){
        flag = 0;
        for(int j = 0;j<n-1-i;j++){
            if(a[j] > a[j+1]){
                swap(a[j],a[j+1]);
                flag = 1;
            }
        }
        pass_count++;
        if(flag == 0){
            break ;
        }
    }
    printf("no of passes is %d\n",pass_count);
}

void Display(int a[],int n){
    for(int i = 0;i<n;i++){
        printf("%d ",a[i]);
    }
}
int main(){
    int arr[100];
    int x,num;
    cout<<"enter the number of elements to be sorted: ";
    cin>>x;
    for(int i = 0;i<x;i++){
        cout<<"Enter the number: ";
        cin>>num;
        arr[i] = num;
    }
    BubbleSort(arr,x);
    Display(arr,x);
    return 0;
}