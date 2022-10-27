#include<bits/stdc++.h>
using namespace std;
#define sizee 10


int hashfn(int key){
    return key % sizee;
}

int hashfnQP(int h[],int key){
    int l = hashfn(key),i=0;
    while(h[l] != 0){
        i++;
        l = (l + i*i) % sizee;
    }
    return l;
}

void insert(int h[],int key){
    int index = hashfn(key);
    if(h[index] != 0)
        index = hashfnQP(h,key);
    h[index] = key;
}

void display(int h[]){
    for(int i = 0;i<sizee ; i++){
        printf("%d\n",h[i]);
    }
}

//it needs to modify for later.
void search(int h[],int key){
    int i = 0;
    int l = (hashfn(key) + i * i) % sizee ;
    while(h[l] != 0){
        if(h[l] == key){
            printf("%d is found at index %d\n",key,l);
            return ;
        }
        else{
            i++;
            l = (hashfn(key) + i * i) % sizee;
        }
    }
    printf("%d not found\n",key);
}

int main(){
    int ht[sizee] = {0};
    insert(ht,13);
    insert(ht,23);
    insert(ht,33);
    insert(ht,17);
    display(ht);
    search(ht,13);
}