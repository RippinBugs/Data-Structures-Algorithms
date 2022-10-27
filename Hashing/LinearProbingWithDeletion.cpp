//deleting in linear probing needs rehashing.
//Or we can just use 2-d matrix where a col will be used as a flag to know if the value is already deleted or not
//so that we don't need to rehash. 


#include<bits/stdc++.h>
using namespace std;
#define sizee 10
//int Ht[sizee] = {0};

int hashfn(int key){
    return key % sizee;
}

int hashfnLP(int h[][2],int key){
    //this will return the index of the next location which has a value zero i.e. empty
    int l = hashfn(key);
    while(h[l][0] != 0){
        l = (l+1)%sizee;
    }
    return l;
}

void insert(int h[][2],int key){
    int index = hashfn(key);
    if(h[index][0] != 0)
        index = hashfnLP(h,key);
    h[index][0] = key;
    h[index][1] = 1;

}

void display(int h[][2]){
    for(int i=0;i<sizee;i++){
        printf("%d %d\n",h[i][0],h[i][1]);
    }
}

//deletion in linear probing next task
void search(int h[][2],int key){
    int i = 0;
    int l = (hashfn(key) + i) % sizee ;
    while(h[l][0] != 0){
        if(h[l][0] == key && h[l][1] == 1){
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
void Delete(int h[][2],int key){
    int i = 0;
    int l = (hashfn(key) + i) % sizee ;
    while(h[l][0] != 0){
        if(h[l][0] == key){
            h[l][1] = 0;
            return ;
        }
        else{
            i++;
            l = (hashfn(key) + i) % sizee;
        }
    }
}

int main(){
    int Ht[sizee][2] = {{0},{0}};
    insert(Ht,12);
    insert(Ht,13);
    insert(Ht,14);
    insert(Ht,22);
    insert(Ht,17);
    insert(Ht,27);
    insert(Ht,15);
    display(Ht);

    search(Ht,22);
    Delete(Ht,22);
    display(Ht);
    
    search(Ht,22);
    Delete(Ht,22);
    return 0;
}