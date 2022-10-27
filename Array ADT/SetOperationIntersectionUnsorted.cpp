#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[10],b[10],c[20];
    int al,bl,cl=0;
    cout<<"Enter the length of a and b arrays ";
    cin>>al>>bl;
    for(int i = 0;i<al;i++){
        int x;
        cin>>x;
        a[i] = x;
    }
    for(int i = 0;i<bl;i++){
        int x;
        cin>>x;
        b[i] = x;
    }
    int i,j,k;
    i=j=k=0;

    for(i=0;i<al;i++)
    {
        for(j=0;j<bl;j++)
        {
            if(a[i] == b[j])
            {
                c[k++] = a[i];
                break;
            }
            else
                continue;
        }
    }
    for(int i=0;i<k;i++){
        cout<<c[i]<<" ";
    }
    return 0;
}


//inputs
// 5 5
// 1 2 4 5 7
// 0 1 2 7 67

//output
//1 2 7

//O(n^2)