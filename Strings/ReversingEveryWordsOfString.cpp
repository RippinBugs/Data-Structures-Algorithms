#include<bits/stdc++.h>
using namespace std;

void ReverseWords(char *s)
{
    int l = strlen(s);
    int k=0,i,j,NWSP;  //NWSP - new word's starting point
    while(s[k]!='\0')
    {
        for(i = k;(s[i]!=' ' && s[i]!='\0');i++)
        {
            ;
        }
        NWSP = i;
        cout<<NWSP<<endl;
        for(j = k,i=i-1; j<i; i--,j++)
        {
            swap(s[i],s[j]);
        }
        if(l == NWSP)
            break;
        else
            k = NWSP+1;

    }
    //cout<<s<<endl;
}
int main()
{
    char str[100];
    gets(str);
    char *s;
    s = str;
    ReverseWords(s);
    cout<<"the reversed words for the string is ";
    cout<<s<<endl;
    return 0;
}