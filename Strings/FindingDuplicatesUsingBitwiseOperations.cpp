#include<bits/stdc++.h>
using namespace std;
int main()
{
    char str[100];
    gets(str);
    int h = 0; //Kinda work as hash table but in this case -
    //instead of using bytes it uses bits. int holds up to 4 bytes and we need 26 bits-
    //so 4 bytes give 32 bits.
    int x = 0; // this one uses for merging and masking.
    for(int i=0;str[i]!='\0';i++){
        x = 1;
        x = x << str[i] - 97; //left shifting, assuming all the letters are in lower cases.
        if((h & x) > 0){
            cout<<str[i]<<" is duplicate"<<endl;
        }
        else
            h = h | x;
    }
    return 0;
}