#include <bits/stdc++.h>

using namespace std;
struct aarray{
    int *A;
    int size;
    int length;
};

/*int LinearSearch(struct aarray a, int key)
{
    for(int i = 0;i<a.length;i++)
    {
        if(a.A[i] == key){
            cout<<"the key is in index "<<i<<endl;
            return i;
        }
    }
    cout<<"Not found"<<endl;
    return -1;
}
*/


/* int LinearSearchTransposition(struct aarray a, int key)
{
    for(int i = 0;i<a.length;i++)
    {
        if(a.A[i] == key && i == 0)
        {
            cout<<"the key is in index "<<i<<endl;
            return i;
        }
        else if(a.A[i] == key && (i>0 && i<a.length)){
            swap(a.A[i],a.A[i-1]);
            cout<<"the key is in index "<<i-1<<endl;
            return i-1;
        }
        else
            ;
    }
    cout<<"Not found"<<endl;
    return -1;
} */

int LinearSearchMoveToHead(struct aarray a, int key)
{
    for(int i = 0;i<a.length;i++)
    {
        if(a.A[i] == key){
            swap(a.A[i],a.A[0]);
            cout<<"The value is in index 0"<<endl;
            return 0;
        }
    }
    cout<<"Not found"<<endl;
    return -1;
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
    int key;
    cout<<"enter the key "<<endl;
    cin>>key;
    //LinearSearch(arr,key);
    // LinearSearchTransposition(arr,key);
    LinearSearchMoveToHead(arr,key);
    Display(arr);

    return 0;
}