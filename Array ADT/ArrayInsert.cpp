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

void append(struct aarray *a, int value)
{
    if((a->length) < (a->size))
    {
        a->A[a->length] = value;
        a->length++;
    }
    else
    {
        cout<<"Its impossible"<<endl;
    }
}

void Insert(struct aarray *a,int p,int v)
{
    if(p>=0 && p<= a->length){
        for(int i=a->length;i>p;i--)
        {
            a->A[i] = a->A[i-1];
        }
    }
    else{
        cout<<"not possible"<<endl;
        return ;
    }
    a->A[p] = v;
    a->length++;
}

void Delete(struct aarray *a,int index)
{
    if(index <a->length && index >= 0)
    {
        for(int i=index;i<a->length-1;i++)
        {
            a->A[i] = a->A[i+1];
        }
        a->length--;
    }
    else{
        cout<<"not possible"<<endl;
        return ;
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
        arr.A[i] = rand();
    }
    
    int appval;
    cout<<"Enter append value"<<endl;
    cin>>appval;
    append(&arr,appval);
    Display(arr);
    int pos,value;
    cout<<"insert the position and also the value  "<<endl;
    cin>>pos>>value;
    Insert(&arr,pos,value);
    Display(arr);
    int index;
    cout<<"insert the index to delete ";
    cin>>index;
    Delete(&arr,index);
    Display(arr);

    return 0;
}