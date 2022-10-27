#include <bits/stdc++.h>

using namespace std;
struct aarray{
    int *A;
    int size;
    int length;
};

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
    
    Display(arr);
    return 0;
}