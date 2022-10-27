#include<bits/stdc++.h>
using namespace std;

//Finding duplicates using the hash table method
//O(n)

void findingDuplicate(char *s)
{
    
    int ht[26] ={0};
    for(int i = 0;s[i]!='\0';i++){
        if(s[i]>=97 && s[i]<=122){
            ht[s[i]-97]++;
        }
    }
    
    for(int i=0;i<26;i++){
        if(ht[i]>1){
            cout<<"The character "<< char(97+i)<< " has occured "<<ht[i]<<" times"<<endl;
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