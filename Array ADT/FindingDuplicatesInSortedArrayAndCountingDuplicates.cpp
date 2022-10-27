#include<bits/stdc++.h>
using namespace std;

void FindDuplicate(int a[],int n)
{
    int lastdup = 0;
    for(int i=0;i<n-1;i++)
    {
       if(a[i] == a[i+1] && a[i]!=lastdup){
           cout<<a[i]<<endl;
           lastdup = a[i];
       }
    }

}
void countDuplicate(int a[],int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        if(a[i] == a[i+1]){
            j=i+1;
            while(a[i] == a[j+1]){
                j++;
            }
            cout<<a[i]<<" has occured "<<(j-i)+1<<" times"<<endl;
            i = j-1;
        }
    }
}
void findingAndCountingDuplicatesUsingSimpleHashTable(int a[],int n)
{
    int max = *max_element(a,a+n);
    cout<<max<<endl;
    int ht[max+1] = {0};
    
    for(int i =0;i<n;i++)
    {
        ht[a[i]]++;
    }
    for(int i = 0;i<=max;i++){
        if(ht[i]>1){
            cout<<i<<" has occured "<<ht[i]<<" times"<<endl;
        }
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
    //FindDuplicate(a,n);
    //coduntDuplicate(a,n);
    findingAndCountingDuplicatesUsingSimpleHashTable(a,n);
    return 0;
}