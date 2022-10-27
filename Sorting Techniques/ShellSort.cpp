#include<bits/stdc++.h>
using namespace std;

void shellSort(int a[],int n){
    for(int gap = n/2;gap>0;gap=gap/2){
        for(int j=gap;j<n;j++){
            for(int i=j-gap;i>=0;i = i-gap){
                if(a[i+gap] >= a[i])
                    break;
                else{
                    swap(a[i+gap],a[i]);
                }
            }
        }
    }
    for(int i = 0;i<n;i++){
        printf("%d ",a[i]);
    }
}
int main(){
    int a[] = {6,5,10,8,13,9,12,16,4,2,3};
    int len = sizeof(a)/sizeof(int);
    shellSort(a,len);
    return 0;
}