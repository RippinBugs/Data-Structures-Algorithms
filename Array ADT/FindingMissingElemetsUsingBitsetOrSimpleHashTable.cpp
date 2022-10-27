#include<bits/stdc++.h>
using namespace std;

//Finding the missing elements using Bitset/Hashtable method
void MissingElements(int a[],int n,int mx)
{
    int ht[mx+1];
    for(int i=0;i<=mx;i++)
    {
        ht[i] = 0;
    }
    for(int i=0;i<n;i++)
    {
        ht[a[i]]++;
    }
    for(int i=0;i<=mx;i++)
    {
        if(ht[i]==0)
            cout<<i<<endl;
        else
            continue;
    }
}
int main()
{
    int n,mx;
    cout<<"Enter the length of the array size ";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        a[i] = val;
    }
    mx = *max_element(a,a+n);
    //cout<<mx;
    MissingElements(a,n,mx);
    return 0;
}