#include<bits/stdc++.h>
using namespace std;
void palindrome(char a[])
{
    int i,j=strlen(a)-1;
    while(i<=j){
        if(a[i++] == a[j--]){
            continue;
        }
        else{
            cout<<"Not palindrome"<<endl;
            return;
        }
    }
    cout<<"Palindrome"<<endl;
}
int main()
{
    char a[100];
    gets(a);
    palindrome(a);
    return 0;
}