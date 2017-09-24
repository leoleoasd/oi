#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct road{
    int from;
    int to;
    int data;
};

struct road data[100020];
 
int cmp(struct road a,struct road b){
    return a.data<b.data;
}

void read(int &x){
    char p = getchar();
    while(('0'>= p or p >='9') and p != '-'){
        p = getchar();
    }
    int f=1;
    x=0;
    if(p=='-'){
        f=-1;
        p=getchar();
    }
    while('0'<= p and p <= '9'){
        x = ((x<<3) + (x<<1))+p-'0';
        p=getchar();
    }
    x*=f;
}
int n,m,q;
int mmmmmmm = 0;
short father[20020];
short rank[20020];
int find_set(int node){  
    if (father[node] != node) {  
        father[node] = find_set(father[node]);
    }
    return father[node];
}
int merge(int pa,int qa){
    int root1 = find_set(pa);  
    int root2 = find_set(qa);  
    if(root1==root2){
        return 0;
    }
    if(rank[root1] > rank[root2]){
        father[root2] = root1;
        rank[root1] += rank[root2];
        rank[root2]=0;
    }  
    else{
        father[root1] = root2;  
        rank[root2] += rank[root1];  
        rank[root1]=0;
    }  
    return 1;  
}  
void zt(){
    read(n);
    read(m);
    read(q);
    for(int i=0;i<m;i++){
        read(data[i].from);
        read(data[i].to);
        read(data[i].data);
    }
    sort(data,data+m,cmp);
    for(int i=0;i<q;i++){
        for(int j = 1;j < n;++j){  
            father[j] = j;  
            rank[j] = 1;
        }
        read(mmmmmmm);
        for(int j=0;j<m;j++){
            if(data[j].data > mmmmmmm){
                break;
            }
            merge(data[j].from-1,data[j].to-1);
        } 
        int output=0;
        for(int j=0;j<n;j++){
            output+=(rank[j]*(rank[j]-1));
        }
        cout<<output<<endl;
    }
}

int main(){
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    int test;
    read(test);
    while(--test>=0){
        zt();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}