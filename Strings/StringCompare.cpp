#include<bits/stdc++.h>
using namespace std;
void compare(char a[],char b[])
{
    int i,j;
    for(i = 0,j=0;a[i]!='\0' && b[j]!='\0';i++,j++){
        if(a[i]!=b[j])
            break;
    }
    if(a[i]==b[j])
        cout<<"equal"<<endl;
    else if(a[i]<b[j])
        cout<<"A is smaller"<<endl;
    else
        cout<<"B is smaller"<<endl;
}
int main()
{
    char a[100],b[100];
    gets(a);
    gets(b);
    compare(a,b);
}