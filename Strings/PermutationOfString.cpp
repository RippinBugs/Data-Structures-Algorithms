#include<bits/stdc++.h>
using namespace std;

void permutation(char s[],int k){
    static int flag[4] = {0};
    static char result[4];
    int i;
    if(s[k] == '\0'){
        result[k] == '\0';
        cout<<result<<endl;
    }
    else{
        for(i = 0;s[i]!='\0';i++){
            if(flag[i]== 0 ){
                result[k] = s[i];
                flag[i] = 1;
                permutation(s,k+1);
                flag[i] = 0;
            }
        }
    }
}
int main(){
    char str[100];
    gets(str);
    //int len= strlen(str);
    permutation(str,0);
    return 0;
}