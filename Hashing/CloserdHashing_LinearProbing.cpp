#include<bits/stdc++.h>
using namespace std;
#define sizee 10

int hashfn(int key){
    return key % sizee;
}

int hashfnLP(int h[],int key){
    //this will return the index of the next location which has a value zero i.e. empty
    int l = hashfn(key);
    while(h[l] != 0){
        l = (l+1)%sizee;
    }
    return l;
}

void insert(int h[],int key){
    int index = hashfn(key);
    if(h[index] != 0)
        index = hashfnLP(h,key);
    h[index] = key;

    // if(h[index] == 0){
    //     h[index] = key;
    // }
    // else{
    //     index = hashfnLP(h,key);
    //     h[index] = key;
    // }
}

void display(int h[]){
    for(int i = 0;i<sizee;i++){
        printf("%d\n",h[i]);
    }
}

//deletion in linear probing next task
void search(int h[],int key){
    int i = 0;
    int l = (hashfn(key) + i) % sizee ;
    while(h[l] != 0){
        if(h[l] == key){
            printf("%d is found at index %d\n",key,l);
            return ;
        }
        else{
            i++;
            l = (hashfn(key) + i) % sizee;
        }
    }
    printf("%d not found\n",key);
}
int main(){
    int Ht[sizee] = {0};
    insert(Ht,12);
    insert(Ht,13);
    insert(Ht,14);
    insert(Ht,22);
    insert(Ht,17);
    insert(Ht,27);
    insert(Ht,15);
    display(Ht);
    search(Ht,27);
    return 0;
}