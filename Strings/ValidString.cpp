#include<bits/stdc++.h>
using namespace std;

int validStringOrNot(char *s)
{
    for(int i=0;s[i]!=0;i++){
        if((s[i]>=65 && s[i]<=90) || (s[i]>=97 && s[i]<=122) || (s[i]>=48 && s[i]<=57))
            continue;
        else{
            return 0;
        }
    }
    return 1;
}
int main()
{
    char *s;
    char a[100];
    gets(a);
    s = a;
    int x = validStringOrNot(s);
    if(x == 1)
        cout<<"Valid"<<endl;
    else
        cout<<"Not Valid"<<endl;
    return 0;
}