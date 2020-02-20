#pragma clang diagnostic push
#pragma ide diagnostic ignored "hicpp-signed-bitwise"
#include <iostream>
#include <algorithm>
#include <cstdio>

#define lson ((now<<1)+1)
#define rson ((now<<1)+2)
#define mid ((l+r)/2)
#define tmid ((this->nodes[now].l+this->nodes[now].r)/2)
#define LL long long

//#define DEBUG

using namespace std;

struct no{
    LL l;
    LL r;
    LL value;
    LL lazy;
    no(){
        l=r=value=lazy = 0;
    }
};

#define MAXN 100010
#define tree_size (4*MAXN)

struct tree{
    struct no nodes[tree_size];

    tree(){}

    void build(LL data[],LL n){
        // 建树 0 - n-1
        buildTree(0,n-1,0,data);
    }

    void buildTree(LL l,LL r,LL now,LL data[]){ // [l,r]
        if(l>r){
            return;
        }
        this->nodes[now].l = l;
        this->nodes[now].r = r;
        if(l==r){
            this->nodes[now].value = data[l];
            return;
        }
        buildTree(l,mid,lson,data);
        buildTree(mid+1,r,rson,data);
        this->nodes[now].value = this->nodes[lson].value + this->nodes[rson].value;
#ifdef DEBUG
        cout<<"BUILDING"<<l<<" "<<r<<endl;
        cout<<"NOW:"<<now<<" "<<this->nodes[now].l <<" "<<this->nodes[now].r<<" "<<this->nodes[now].value<<" "<<this->nodes[now].lazy<<endl;
#endif
    }

    void change(LL pos,LL value,LL now = 0){
        if(this->nodes[now].l == this->nodes[now].r){
            this->nodes[now].value = value;
            return;
        }

        pushdown(now);
        if(pos <= tmid){
            change(pos,value,lson);
        }else{
            change(pos,value,rson);
        }
        this->nodes[now].value = this->nodes[lson].value + this->nodes[rson].value;
    }

    void update(LL l,LL r,LL value,LL now = 0){ //[l,r] += value
        if(this->nodes[now].l == l and this->nodes[now].r == r){
            this->nodes[now].value += (r-l+1)*value;
            this->nodes[now].lazy += value;
#ifdef DEBUG
            cout<<"updating "<<l<<" "<<r<<endl;
            cout<<"NOW:"<<now<<" "<<this->nodes[now].l <<" "<<this->nodes[now].r<<" "<<this->nodes[now].value<<" "<<this->nodes[now].lazy<<endl;
#endif
            return;
        }

        pushdown(now);
        if(r <= tmid){
            update(l,r,value,lson);
        }else if(l >= tmid+1){
            update(l,r,value,rson);
        }else{
            update(l,tmid,value,lson);
            update(tmid+1,r,value,rson);
        }
        this->nodes[now].value = this->nodes[lson].value + this->nodes[rson].value;
#ifdef DEBUG
        cout<<"updating "<<l<<" "<<r<<endl;
        cout<<"NOW:"<<now<<" "<<this->nodes[now].l <<" "<<this->nodes[now].r<<" "<<this->nodes[now].value<<" "<<this->nodes[now].lazy<<endl;
#endif
    }

    void pushdown(LL now){
        if(this->nodes[now].l == this->nodes[now].r){
            this->nodes[now].lazy = 0;
            return;
        }
        this->nodes[lson].value += this->nodes[now].lazy * (this->nodes[lson].r - this->nodes[lson].l + 1);
        this->nodes[rson].value += this->nodes[now].lazy * (this->nodes[rson].r - this->nodes[rson].l + 1);

        this->nodes[lson].lazy +=this->nodes[now].lazy;
        this->nodes[rson].lazy +=this->nodes[now].lazy;
        
        this->nodes[now].lazy = 0;
    }

    LL query(LL l, LL r, LL now = 0){
        if(this->nodes[now].l == l and this->nodes[now].r == r){
            return this->nodes[now].value;
        }
        if(this->nodes[now].lazy){
            pushdown(now);
        }
        if(r <= tmid){
            return query(l,r,lson);
        }else if(l >= tmid+1){
            return query(l,r,rson);
        }else {
            return query(l,tmid,lson) + query(tmid+1,r,rson);
        }
#ifdef DEBUG
        cout<<"querying "<<l<<" "<<r<<endl;
        cout<<"NOW:"<<now<<" "<<this->nodes[now].l <<" "<<this->nodes[now].r<<" "<<this->nodes[now].value<<" "<<this->nodes[now].lazy<<endl;
#endif
    }

    void print_tree(){
#ifdef DEBUG
        for(int i = 0;!( this->nodes[i].l == 0 and this->nodes[i].r == 0 and this->nodes[i].value == 0); ++ i){
            cout<<"PRINT "<<i<<" L "<<this->nodes[i].l<<" R "<<this->nodes[i].r<<" V "<<this->nodes[i].value<<" L "<<this->nodes[i].lazy<<endl;
        }
#endif
    }
};
struct tree tr;
int main(){
    LL n,m;
    LL data[MAXN] = {0};
    cin>>n>>m;
    for(LL i = 0; i < n; ++ i){
        cin>>data[i];
    }
    tr.build(data,n);
    int t1,t2,t3;
    for(int i = 0; i < m; ++ i) {
        cin >> t1;
        if (t1 == 1) {
            cin >> t1 >> t2 >> t3;
            tr.update(t1 - 1, t2 - 1, t3);
            tr.print_tree();
        } else {
            cin >> t2 >> t3;
            tr.print_tree();
            cout << tr.query(t2 - 1, t3 - 1) << endl;
        }
    }
    return 0;
}
#pragma clang diagnostic pop