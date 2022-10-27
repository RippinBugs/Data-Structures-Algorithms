#include<bits/stdc++.h>
using namespace std;


void ToUpper(char *str)
{
    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]>=97 && str[i]<=122){
            str[i] = str[i] - 32;
        }
        else
            continue;
    }
}
void ToLower(char str[])
{
    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]>=65 && str[i]<=90){
            str[i] = str[i] + 32;
        }
        else
            continue;
    }
}
int main()
{
    char str[100];
    gets(str);
    ToLower(str);
    cout<<"The uppercase string is "<<str<<endl;
    ToUpper(str);
    cout<<"The uppercase string is "<<str<<endl;
    return 0;
}