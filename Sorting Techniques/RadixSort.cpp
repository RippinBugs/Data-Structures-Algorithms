#include<bits/stdc++.h>
using namespace std;
struct node {
    int data;
    struct node *next;
};

//no of buckets
#define bucket 10 

int it = 0; //this iterator is used for traversing the array with bucket size
int Digits(int a[],int len){
    int mx = a[0];
    for(int i=1;i<len;i++){
        if(mx < a[i]){
            mx = a[i];
        }
    }
    int n=0;
    while(mx>0){
        mx/=10;
        n++;
    }
    cout<<n<<endl;
    return n;
}
void insert(struct node *b[],int val,int index){
    struct node *temp = new node;
    temp->data = val;
    temp->next = NULL;
    if(b[index] == NULL)
        b[index] = temp;
    else{
        struct node *p = b[index];
        struct node *q = NULL;
        while(p){
            q = p;
            p = p->next;
        }
        q->next = temp;
    }
}

void Delete(struct node *p,int a[]){
    //this has to change 
    //static int i = 0;
    struct node *q = p;
    if(p == NULL)
        return;
    else{
        while(p){
            struct node *q = p;
            cout<<q->data <<" "<<it<<endl;;
            a[it++] = q->data;
            p = q->next;
            delete q;
        }
    }
}
void RadixSort(int a[],int len){
    struct node *b[bucket] = {NULL};
    int k = 1,num = Digits(a,len);

    for(int j = 0;j<num;j++){
        it = 0;
        for(int i=0;i<len;i++){
            int index = (a[i]/k) % 10;
            insert(b,a[i],index);
        }
        for(int i = 0;i<bucket;i++){
            Delete(b[i],a);
        }
        for(int i = 0;i<len;i++){
            printf("%d " ,a[i]);
        }
        cout<<endl;
        for(int i = 0;i<bucket;i++){
            b[i] = NULL;
        }
        k = k*10;
    }
}
int main(){
    int a[] = {237,146,259,348,152,163,235,48,36,62};
    int len = sizeof(a)/sizeof(int);
    RadixSort(a,len);
}