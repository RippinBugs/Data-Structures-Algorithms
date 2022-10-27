#include <bits/stdc++.h>

using namespace std;
struct aarray{
    int *A;
    int size;
    int length;
};

// void LShift(struct aarray *a,int n){
//     int i;
//     for(i=0;i<a->length-n;i++){
//         a->A[i] = a->A[i+n];
//     }
//     for(;i<a->length;i++){
//         a->A[i] = 0;
//     }
// }

void RShift(struct aarray *a,int n){
    int i;
    for(i=a->length-1;i >= a->length-(n+1);i--){
        a->A[i] = a->A[i-n];
    }
    for(i=0;i<n;i++){
        a->A[i] = 0;
    }
}

void Display(aarray a)
{
    for(int i = 0;i<a.length;i++)
    {
        cout<<"the number is "<<a.A[i]<<endl;
    }
}

int main()
{
    struct aarray arr;
    cout<<"Enter the size of the array"<<endl;
    cin>>arr.size;
    arr.A = new int[arr.size];
    cout<<"Enter the length of the array"<<endl;
    cin>>arr.length;
    for(int i=0;i<arr.length;i++)
    {
        arr.A[i] = i+1;
    }
    
    int n;
    cout<<"Enter the number of times to shift left ";
    cin>>n;
    Display(arr);
    RShift(&arr,n);
    Display(arr);
    return 0;
}