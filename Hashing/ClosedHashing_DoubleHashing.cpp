#include<bits/stdc++.h>
using namespace std;
#define sizee 10


int hashfn1(int key){
    return key % sizee;
}

int hashfn2(int key){
    //Rule is: get the highest prime number within the value of the size. 
    //like if the size is 10, then highest prime number is 7 
    //prime_number - (key % prime_number)
    return 7 - (key % 7);
}
int hashfnDH(int h[],int key){
    int l = hashfn1(key),i=0;
    while(h[l] != 0){
        i++;
        l = (hashfn1(key) + i*hashfn2(key)) % sizee;
    }
    return l;
}

void insert(int h[],int key){
    int index = hashfn1(key);
    if(h[index] != 0)
        index = hashfnDH(h,key);
    h[index] = key;
}

void display(int h[]){
    for(int i = 0;i<sizee ; i++){
        printf("%d\n",h[i]);
    }
}

//Stop doing linear search, you stupid 
//stupid later reply with this solution xD
void search(int h[],int key){
    int i = 0;
    int l = (hashfn1(key) + i * hashfn2(key)) % sizee ;
    while(h[l] != 0){
        if(h[l] == key){
            printf("%d is found at index %d\n",key,l);
            return ;
        }
        else{
            i++;
            l = (hashfn1(key) + i * hashfn2(key)) % sizee;
        }
    }
    printf("%d not found\n",key);
}

int main(){
    int ht[sizee] = {0};
    insert(ht,5);
    insert(ht,25);
    insert(ht,15);
    insert(ht,35);
    insert(ht,95);
    display(ht);
    search(ht,131);
}