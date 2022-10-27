#include<bits/stdc++.h>
using namespace std;

#define N 7
int deq[N];
int f = -1, r = -1;
void insertRear(int val){
    if(((r+1) % N) == f){
        printf("Queue is full\n");
    }
    else if(f == -1 && r == -1){
        f = r = 0;
        deq[r] = val;
    }
    else if(r == N-1){
        r = 0;
        deq[r] = val;
    }
    else{
        r++;
        deq[r] = val;
    }
}

void insertFront(int val){
    if(((r+1) % N) == f){
        printf("Queue is full\n");
    }
    else if(f == -1 && r == -1){
        f = r = 0;
        deq[f] = val;
    }
    else if(f == 0){
        f = N-1;
        deq[f] = val;
    }
    else{
        f--;
        deq[f] = val;
    }
}
int DeleteRear(){
    int x = -1;
    if(f == -1 && r == -1){
        printf("Queue is empty\n");
    }
    else if(f == r){
        //when there is only one element left. and after deleting we set r and f pointing to -1
        f = r = -1;
    }
    else if(r == 0){
        x = deq[r];
        r = N-1;
    }
    else{
        x = deq[r];
        r--;
    }
    return x;
}
int DeleteFront(){
    int x = -1;
    if(f == -1 && r == -1){
        printf("Queue is empty\n");
    }
    else if(f == r){
        //when there is only one element left. and after deleting we set r and f pointing to -1
        f = r = -1;
    }
    else if(f == N-1){
        x = deq[f];
        f = 0;
    }
    else{
        x = deq[f];
        f++;
    }
    return x;
}

void Display(){
   int i  = f;
   do{
       printf("%d\n",deq[i]);
       i = (i+1)%N;
   }while(i!= (r+1)%N);
}
int main(){
    insertFront(12);
    insertFront(23);
    insertRear(11);
    insertRear(1);
    insertFront(7);
    insertFront(90);
    insertFront(111);
    insertRear(124);
    cout<<"Display after insertion"<<endl;
    Display();
    DeleteFront();
    DeleteRear();
    DeleteFront();
    cout<<"Display after deletion"<<endl;
    Display();
    return 0;
}