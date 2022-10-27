#include<bits/stdc++.h>
using namespace std;

void MissingElementsINSortedArray(int a[],int len)
{
    int misnum,i;
    int diff = a[0] - 0;
    for(i =0;i<len;i++)
    {
        if((a[i]-i) != diff){
            while(diff<(a[i]-i)){
            misnum = diff + i;
            cout<<misnum<<endl;
            diff++;
            }
        }
    }
}
int main()
{
    int a[100],len;
    cout<<"Enter the length of the array ";
    cin>>len;
    for(int i=0;i<len;i++)
    {
        int x;
        cin>>x;
        a[i] = x;
    }
    MissingElementsINSortedArray(a,len);
    return 0;
}

//input
//5
//1 4 7 8 9

//output
// 2 3 5 6