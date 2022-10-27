#include <iostream>

using namespace std;

int binarySearch(int a[],int key,int l,int h)
{
    int mid;
    while(l<=h)
    {
        mid = (l+h)/2;
        if (a[mid] == key)
        {
            return mid;
        }
        else if(key > a[mid])
        {
            l = mid + 1;

        }
        else
            h= mid -1;
    }
    return -1;

}
int binarySearchRecursive(int a[],int key,int l,int h)
{
    if(l<=h){
        int mid = (l+h)/2;
        if(a[mid] == key)
            return mid;
        else if(key<a[mid])
            return binarySearchRecursive(a,key,l,mid-1);

        else
            return binarySearchRecursive(a,key,mid+1,h);
        }
    return -1;
}

int main()
{
    int *a;
    int n,key;
    cin>>n;
    a = new int [n];
    for(int i =0;i<n;i++){
        a[i] = i+1;
    }
    cin>>key;
    int l,h;
    l = 0;
    h = n;
    cout<<binarySearch(a,key,l,h)<<endl;
    
    // cout<<binarySearchRecursive(a,key,l,h)<<endl;
    return 0;
}
