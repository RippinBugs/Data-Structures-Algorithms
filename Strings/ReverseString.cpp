#include<bits/stdc++.h>
using namespace std;

void reverseString(char *s)
{
    int i,j;
    for(i=0;s[i]!='\0';i++){
        ;
    }
    cout<<"Length of the string "<<i<<endl;
    j = i-1;
    for(i=0;i<j;i++,j--){
        char temp = s[i];
        s[i] = s[j];
        s[j] =temp;
    }
}
int wordCount(char *s)
{
    int i,wc=0;
    for(i=0;s[i]!='\0';i++){
        if(s[i]==' ')
            wc++;
        else
            continue;
    }
    return wc+1;
}
int main()
{
    char *s;
    char str[100];
    gets(str);
    s = str;
    reverseString(s);
    cout<<"the reversed string is ";
    cout<<s<<endl;

    cout<<wordCount(s)<<endl;
    return 0;
}