#include<bits/stdc++.h>

using namespace std;

int main()
{
    char *str;
    gets(str);
    int v = strlen(str);
    printf("%d",v);

    //may be in my system it find some spaces to work with the str but not with all systems
    //i spent two days on this still no actual result probably.

    // cout<<str.c_str()<<"10"<<endl;
    // char *d = &str[0];
    // cout<<d<<endl;
    // for(int i=0;str[i]!='\0';i++)
    // {
    //     if(str[i]>=97 && str[i]<=122){
    //         str[i] = str[i] - 32;
    //     }
    //     else
    //         continue;
    // }
    // cout<<str<<endl;
    
    return 0;
}

