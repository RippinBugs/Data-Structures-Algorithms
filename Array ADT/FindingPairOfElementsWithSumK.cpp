#include<bits/stdc++.h>
using namespace std;

//This one outputs a pair and then set the value -1
//O(n^2)
void FindPairWithSum(int a[],int n,int k)
{
    for(int i =0;i<n-1;i++){
        if(a[i]!=-1){
            for(int j=i+1;j<n;j++){
                if(a[i]+a[j] == k){
                    cout<<a[i]<<" "<<a[j]<<" = "<<k <<endl;
                    a[i] = a[j] = -1;
                    break;
                }
            }
        }
    }
}

//This one provides every pair respect to every a[i]
//O(n^2)
void FindPairWithSumMethod2(int a[],int n,int k)
{
    for(int i =0;i<n-1;i++){
        
        for(int j=i+1;j<n;j++){
            if(a[i]+a[j] == k){
                cout<<a[i]<<" "<<a[j]<<" = "<<k << "with index "<< i << " and "<<j<<endl;                    
            }
        }
    }
}

//using simple hash table
//O(n)
void FindingPairWithSumUsingHashTable(int a[],int n,int k)
{
    int max = *max_element(a,a+n);
    int ht[max+1] = {0};
    // for(int i=0;i<n;i++){
    //     ht[a[i]]++;
    // }
    for(int i=0;i<n;i++){
        if(ht[k-a[i]]>0 && (k-a[i])>0){
            cout<<a[i] <<" + "<<k-a[i]<<" = "<<k<<endl;
        }
        ht[a[i]]++;
    }
    
}

//Finding a pair for sorted array 
//O(n)
void FindPairForSumInSortedArray(int a[],int n,int k)
{
    int i=0,j=n-1;
    while(i<j){
        if(a[i] + a[j] == k){
            cout<<a[i]<< " + "<<a[j]<<" = "<<k<<endl;
            i++;
            j--;
        }
        //if the sum of the elements are greater than k then reduce from the right i.e. j
        else if(a[i]+a[j]>k){
            j--;
        }
        else
            i++;
    }
}
int main()
{
    int a[100],len;
    cout<<"Enter the length of the array ";
    cin>>len;
    for(int i =0;i<len;i++){
        int x;
        cin>>x;
        a[i] =x;
    }
    int sumK;
    cout<<"Enter the sum K ";
    cin>>sumK;
    //FindPairWithSum(a,len,sumK);
    //FindPairWithSumMethod2(a,len,sumK);
    //FindingPairWithSumUsingHashTable(a,len,sumK);
    FindPairForSumInSortedArray(a,len,sumK);
    return 0;
}