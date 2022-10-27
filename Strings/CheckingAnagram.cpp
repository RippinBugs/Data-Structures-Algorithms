#include<bits/stdc++.h>
using namespace std;

void anagram(char a[],char b[])
{
    int i;
    char alpha[26] = {0};
    int l1,l2;
    l1 = strlen(a);
    l2 = strlen(b);
    if(l1 != l2){
        cout<<"not anagram"<<endl;
        return;
    }
    else{
        for(i =0;a[i]!='\0';i++)
        {
            alpha[a[i]-97]++;
        }   
        for(i=0;b[i]!='\0';i++)
        {
            alpha[b[i]-97]--;
            if(alpha[b[i]-97] < 0){
                cout<<"Not anagram"<<endl;
                break;
            }
        }
    }
    if(b[i]=='\0'){
        cout<<"Anagram"<<endl;
    }
    
}
int main()
{
    char a[100],b[100];
    gets(a);
    gets(b);
    anagram(a,b);
    return 0;
}