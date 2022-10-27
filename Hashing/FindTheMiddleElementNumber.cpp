//may be this code can be used inside a hash funtion.

#include<bits/stdc++.h>
using namespace std;
int middle_Number(long long int x){
    int length = log10(x) + 1;
    cout<<length<<endl;
    int mid = int(x / pow(10,(length / 2))) % 10;
    return mid;
}
int main(){
    printf("enter the number: ");
    long long int x;
    cin>>x;
    int mid = middle_Number(x);
    printf("The middle value is %d\n",mid);
    return 0;
}