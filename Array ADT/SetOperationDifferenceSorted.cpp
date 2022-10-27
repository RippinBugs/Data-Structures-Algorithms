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
    
    while (i<al && j<bl)
    {
        if(a[i]<b[j]){
            c[k++] = a[i++];
        }
        else if(a[i]>b[j]){
            j++;
        }
        else
        {
            i++;j++;
        }
    }
    
    
    for(int i =0;i<k;i++)
    {
        cout<<c[i]<<" ";
    }
    cout<<endl;
    return 0;
}


//inputs
// 5 5
// 3 5 10 4 6
// 12 4 7 2 5

//output
//3 10 6

//O(n^2)