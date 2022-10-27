#include <bits/stdc++.h>

using namespace std;
struct aarray{
    int *A;
    int size;
    int length;
};
int ifSorted(struct aarray a)
{
    for(int i=0;i<a.length-1;i++){
        if(a.A[i]<=a.A[i+1]){
            continue;
        }
        else{
            return 0;
        }
    }
    return 1;
}
void InsertInSortedArray(struct aarray *a,int key)
{
    int i;
    for(i=a->length-1;i>=0;i--)
    {
        if(a->A[i]>key){
            a->A[i+1] = a->A[i];
        }
        else{
            break;
        }
    }
    a->A[i+1] = key;
    a->length++;
}

void NegativeOnTheLeftSide(struct aarray *a)
{
    int i= 0,j = a->length-1;
    while(i<j){
        
         while (a->A[i]<0)
        {
            i++;            
        }
        while (a->A[j]>=0)
        {
            j--;
        }
        if(i<j){
            swap(a->A[i],a->A[j]);
        }
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
    // for(int i=0;i<arr.length;i++)
    // {
    //     int x;
    //     cin>>x;
    //     arr.A[i] = x;
    // }
    // if(ifSorted(arr) == 1){
    //     cout<<"Array is sorted"<<endl;
    // }
    // else
    //     cout<<"Not sorted"<<endl;
    // Display(arr);


    // Input for InsertInSortedArray
    // for(int i=0;i<arr.length;i++)
    // {
    //     arr.A[i] = i+1;
    // }
    
    // int key;
    // cout<<"the key to insert in the sorted array ";
    // cin>>key;
    // Display(arr);
    // InsertInSortedArray(&arr,key);
    // Display(arr);


    for(int i=0;i<arr.length;i++)
    {
        int x;
        cin>>x;
        arr.A[i] = x;
    }
    
    Display(arr);
    NegativeOnTheLeftSide(&arr);
    Display(arr);
    return 0;
}