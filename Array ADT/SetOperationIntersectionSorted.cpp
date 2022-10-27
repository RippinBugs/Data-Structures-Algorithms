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

    while(i<al && j<bl){
        if(a[i]<b[j])
        {
            i++;
        }
        else if(a[i]>b[j])
        {
            j++;
        }
        else{
            c[k++] = a[i];
            i++;j++;
        }
    }
    for(int i =0;i<k;i++){
        cout<<c[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}


//inputs
// 6 5
// 3 4 5 6 10 12
// 2 4 5 7 12

//output
//4 5 12