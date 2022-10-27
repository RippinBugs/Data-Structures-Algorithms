#include<bits/stdc++.h>
using namespace std;

void FindDuplicatesAndCountUnsortedArray(int a[],int n)
{
    int i,j,num;
    for(i=0;i<n-1;i++){
        num = 1;
        for(j=i+1;j<=n;j++)
        {
            if(a[i] == a[j] && a[j]!=-1){
                a[j] = -1;
                num++;
            }
            else 
                continue;
            
        }
        if(num>1)
            cout<<a[i]<<" is a duplicate and it has occured "<<num<<" times"<<endl;
        else 
            continue;
    }
}
int main()
{
    int n;
    cout<<"enter the length of the array ";
    cin>>n;
    int a[n];
    for(int i = 0;i<n;i++)
    {
        int x;
        cin>>x;
        a[i] = x;
    }
    FindDuplicatesAndCountUnsortedArray(a,n);
    
    return 0;
}