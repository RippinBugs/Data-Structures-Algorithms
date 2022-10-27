#include <bits/stdc++.h>

using namespace std;
struct aarray{
    int *A;
    int size;
    int length;
};


void RRotateByOne(struct aarray *a){
    int temp = a->A[a->length-1],i;
    for(i =a->length-1;i>0;i--)
    {
       a->A[i] = a->A[i-1];
    }
    a->A[i] = temp;
}

void RRotate(struct aarray a,int d)
{
    for(int i=0;i<d;i++)
    {
        RRotateByOne(&a);
    }
}
void LRotateByOne(struct aarray *a){
    int temp = a->A[0],i;
    for(i =0;i<a->length-1;i++)
    {
       a->A[i] = a->A[i+1];
    }
    a->A[i] = temp;
}

void LRotate(struct aarray a,int d)
{
    for(int i=0;i<d;i++)
    {
        LRotateByOne(&a);
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
    int d;
    // cout<<"enter the number of times to rotate by ";
    // cin>>d;
    // Display(arr);
    // LRotate(arr,d);
    // Display(arr);
    cout<<"enter the number of times to rotate by ";
    cin>>d;
    Display(arr);
    RRotate(arr,d);
    Display(arr);
    return 0;
}