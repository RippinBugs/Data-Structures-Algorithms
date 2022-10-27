#include<bits/stdc++.h>
using namespace std;
void insert(int ar[],int n){
    //this insertion is basically max heap process
    int temp,i = n;
    temp = ar[i];
    while(i>0 && temp > ar[i/2]){
        ar[i] = ar[i/2];
        i = i/2;
    }
    ar[i] = temp;
}
void display(int a[],int n){
    for(int i = 0;i<n;i++){
        printf("%d ",a[i]);
    }
}
int main(){
    int arr[100] = {40,30,15,20,5,10,12,6,0};
    int x,arr_len=0;
    printf("print the value to insert: ");
    cin>>x;
    for(int i = 0;i<100;i++){
        if(arr[i] != 0)
            arr_len++;
        else
            break;
    }
    printf("%d \n",arr_len);
    arr[arr_len] = x;
    insert(arr,arr_len);
    display(arr,arr_len);
    return 0;
}