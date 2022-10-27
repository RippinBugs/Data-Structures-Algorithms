#include <bits/stdc++.h>

using namespace std;
struct aarray{
    int *A;
    int size;
    int length;
};

void MergingSortedArrays(struct aarray *a, struct aarray *b,struct aarray *c)
{
    int i = 0,j=0,k=0;
    while(i<a->length && j<b->length){
        if(a->A[i] <= b->A[j]){
            c->A[k++] = a->A[i++];
        }
        else
            c->A[k++] = b->A[j++];
    }
    for(;i<a->length;i++)
    {
        c->A[k++] = a->A[i];
    }
    for(;j<b->length;j++)
    {
        c->A[k++] = b->A[j];
    }
}
void Display(struct aarray a)
{
    for(int i = 0;i<a.length;i++)
    {
        cout<<"the number is "<<a.A[i]<<endl;
    }
}

int main()
{
    struct aarray a,b,c;
    cout<<"Enter the size of the array a and b "<<endl;
    cin>>a.size>>b.size;
    a.A = new int[a.size];
    b.A = new int[b.size];
    cout<<"Enter the length of the arrays "<<endl;
    cin>>a.length>>b.length;
    c.length = a.length + b.length;
    c.A = new int[c.length];
    for(int i=0;i<a.length;i++)
    {
        int x;
        cin>>x;
        a.A[i] =x;
    }
    for(int i=0;i<b.length;i++)
    {
        int y;
        cin>>y;
        b.A[i] =y;
    }
    Display(a);
    Display(b);
    MergingSortedArrays(&a,&b,&c);
    
    Display(c);
    return 0;
}