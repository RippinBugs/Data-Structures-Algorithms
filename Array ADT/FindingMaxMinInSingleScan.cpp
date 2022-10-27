#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[100],len;
    cout<<"enter the length of the array ";
    cin>>len;
    for(int i = 0;i<len ; i++){
        int x;
        cin>>x;
        a[i] = x;
    }
    int min,max;
    min = max = a[0];
    for(int i = 1;i<len;i++){
        if(a[i]<min)
            min = a[i];
        if(a[i]>max)
            max = a[i];
    }
    cout<<"min is "<<min<<" max is "<<max<<endl;
}