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
        c[i] = a[i];
        cl++;
    }
    for(int i = 0;i<bl;i++){
        int x;
        cin>>x;
        b[i] = x;
    }
    int flag = 0;
    for(int i=0;i<bl;i++){
        for(int j=0;j<cl;j++){
            if(b[i] == c[j]){
                flag = 1;
                break;
            }
            else{
                flag = 0;
                continue;
            }
        }
        if(flag == 0){
            c[cl++] = b[i];
        }
        else
            continue;
    }

    for(int i =0;i<cl;i++){
        cout<<c[i]<<" ";
    }
    cout<<endl;
}

//inputs
// 5 5
// 7 3 2 10 2
// 0 1 2 7 67
// 0 1 2 7 3 10 67