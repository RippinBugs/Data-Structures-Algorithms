#include<bits/stdc++.h>
using namespace std;

//Finding duplicates comparing elements table method
//O(n^2)

void findingDuplicate(char *s)
{
    int len= strlen(s),num;
    for(int i=0;i<len-1;i++){
        num = 1;
        for(int j=i+1;j<len;j++){
            if((s[i]==s[j]) && (s[i]!=' ')){
                s[j] = ' ';   // in term of duplicate value i assigned space in that location.
                num++;
            }
        }
        if(num>1){
            cout<<s[i]<<" is duplicate and it has occured "<<num<<" times"<<endl;
        }
    }
}

int main()
{
    char str[100];
    gets(str);
    char *s;
    s = str;
    findingDuplicate(s);
}