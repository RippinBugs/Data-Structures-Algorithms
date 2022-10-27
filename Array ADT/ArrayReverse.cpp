#include <bits/stdc++.h>
using namespace std;

struct arrayy{
    int *A;
    int size;
    int length;
};

void reverse(struct arrayy *a){
    for(int i=0,j=a->length-1;i<j;i++,j--){
        // swap(a[i],a[j]);
        int temp = a->A[i]; 
        a->A[i] = a->A[j];
        a->A[j] = temp;
    }
}
void display(struct arrayy a){
    for(int i=0;i<a.length;i++){
        cout<<i<<"th length value is "<<a.A[i]<<endl;
    }
}
int main()
{
    struct arrayy arr;
    cout<<"Enter the array size ";
    cin>>arr.size;
    cout<<"enter the length of the array ";
    cin>>arr.length;
    arr.A = new int [arr.size];
    for(int i=0;i<arr.length;i++){
        arr.A[i] = i+2;
    }
    display(arr);
    reverse(&arr);
    display(arr);
}