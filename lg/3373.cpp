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

int p;

struct no{
    LL l;
    LL r;
    LL value;
    LL lazy1; // 乘法
    LL lazy2; // 加法
    no(){
        l=r=value=lazy2=0;
        lazy1=1;
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
            this->nodes[now].value %= p;
            return;
        }
        buildTree(l,mid,lson,data);
        buildTree(mid+1,r,rson,data);
        this->nodes[now].value = this->nodes[lson].value + this->nodes[rson].value;
        this->nodes[now].value %= p;
#ifdef DEBUG
        cout<<"BUILDING"<<l<<" "<<r<<endl;
        cout<<"NOW:"<<now<<" "<<this->nodes[now].l <<" "<<this->nodes[now].r<<" "<<this->nodes[now].value<<" "<<this->nodes[now].lazy2<<endl;
#endif
    }

    void change(LL pos,LL value,LL now = 0){
        if(this->nodes[now].l == this->nodes[now].r){
            this->nodes[now].value = value;
            return;
        }
        if(pos <= tmid){
            change(pos,value,lson);
        }else{
            change(pos,value,rson);
        }
        pushdown(now);
        this->nodes[now].value = this->nodes[lson].value + this->nodes[rson].value;
        this->nodes[now].value %= p;
    }
    
    void update1(LL l,LL r,LL value,LL now = 0){//[l,r] *= value
        if(this->nodes[now].l == l and this->nodes[now].r == r){
            this->nodes[now].value *= value;
            this->nodes[now].lazy1 *= value;
            this->nodes[now].lazy2 *= value;
            this->nodes[now].value %= p;
            this->nodes[now].lazy1 %= p;
            this->nodes[now].lazy2 %= p;
#ifdef DEBUG
            cout<<"updating1 "<<l<<" "<<r<<endl;
            cout<<"NOW:"<<now<<" "<<this->nodes[now].l <<" "<<this->nodes[now].r<<" "<<this->nodes[now].value<<" "<<this->nodes[now].lazy2<<endl;
#endif
            return;
        }
        pushdown(now);
        if(r <= tmid){
            update1(l,r,value,lson);
        }else if(l >= tmid+1){
            update1(l,r,value,rson);
        }else{
            update1(l,tmid,value,lson);
            update1(tmid+1,r,value,rson);
        }
        this->nodes[now].value = this->nodes[lson].value + this->nodes[rson].value;
        this->nodes[now].value %= p;
    }

    void update2(LL l,LL r,LL value,LL now = 0){ //[l,r] += value
        if(this->nodes[now].l == l and this->nodes[now].r == r){
            this->nodes[now].value += (r-l+1)*value;
            this->nodes[now].value %= p;
            this->nodes[now].lazy2 += value;
#ifdef DEBUG
            cout<<"updating2 "<<l<<" "<<r<<endl;
            cout<<"NOW:"<<now<<" "<<this->nodes[now].l <<" "<<this->nodes[now].r<<" "<<this->nodes[now].value<<" "<<this->nodes[now].lazy1<<" "<<this->nodes[now].lazy2<<endl;
#endif
            return;
        }
        pushdown(now);
        if(r <= tmid){
            update2(l,r,value,lson);
        }else if(l >= tmid+1){
            update2(l,r,value,rson);
        }else{
            update2(l,tmid,value,lson);
            update2(tmid+1,r,value,rson);
        }
        this->nodes[now].value = this->nodes[lson].value + this->nodes[rson].value;
        this->nodes[now].value %= p;
#ifdef DEBUG
        cout<<"updating "<<l<<" "<<r<<endl;
        cout<<"NOW:"<<now<<" "<<this->nodes[now].l <<" "<<this->nodes[now].r<<" "<<this->nodes[now].value<<" "<<this->nodes[now].lazy2<<endl;
#endif
    }

    void pushdown(LL now){
        if(this->nodes[now].l == this->nodes[now].r){
            this->nodes[now].lazy1 = 1;
            this->nodes[now].lazy2 = 0;
            return;
        }
        this->nodes[lson].value *= this->nodes[now].lazy1;
        this->nodes[rson].value *= this->nodes[now].lazy1;

        this->nodes[lson].value %= p;
        this->nodes[rson].value %= p;

        this->nodes[lson].value += this->nodes[now].lazy2 * (this->nodes[lson].r - this->nodes[lson].l + 1);
        this->nodes[rson].value += this->nodes[now].lazy2 * (this->nodes[rson].r - this->nodes[rson].l + 1);

        this->nodes[lson].value %= p;
        this->nodes[rson].value %= p;

        this->nodes[lson].lazy1 *= this->nodes[now].lazy1;
        this->nodes[rson].lazy1 *= this->nodes[now].lazy1;

        this->nodes[lson].lazy2 +=this->nodes[now].lazy2;
        this->nodes[rson].lazy2 +=this->nodes[now].lazy2;

        this->nodes[now].lazy1 = 1;
        this->nodes[now].lazy2 = 0;
    }

    LL query(LL l, LL r, LL now = 0){
        if(this->nodes[now].l == l and this->nodes[now].r == r){
            return this->nodes[now].value % p;
        }
        pushdown(now);
        if(r <= tmid){
            return query(l,r,lson) % p;
        }else if(l >= tmid+1){
            return query(l,r,rson) % p;
        }else {
            return (query(l,tmid,lson) + query(tmid+1,r,rson)) % p;
        }
#ifdef DEBUG
        cout<<"querying "<<l<<" "<<r<<endl;
        cout<<"NOW:"<<now<<" "<<this->nodes[now].l <<" "<<this->nodes[now].r<<" "<<this->nodes[now].value<<" "<<this->nodes[now].lazy2<<endl;
#endif
    }

    void print_tree(){
#ifdef DEBUG
        for(int i = 0;!( this->nodes[i].l == 0 and this->nodes[i].r == 0 and this->nodes[i].value == 0); ++ i){
            cout<<"PRINT "<<i<<" L "<<this->nodes[i].l<<" R "<<this->nodes[i].r<<" V "<<this->nodes[i].value<<" L "<<this->nodes[i].lazy2<<endl;
        }
#endif
    }
};
struct tree tr;
int main(){
    LL n,m;
    LL data[MAXN] = {0};
    cin>>n>>m>>p;
    for(LL i = 0; i < n; ++ i){
        cin>>data[i];
    }
    tr.build(data,n);
    int t1,t2,t3;
    for(LL i = 0; i < m; ++ i) {
        cin >> t1;
        if(t1 == 1){
            cin>>t1>>t2>>t3;
            tr.update1(t1-1,t2-1,t3);
            tr.print_tree();
        } else if (t1 == 2) {
            cin >> t1 >> t2 >> t3;
            tr.update2(t1 - 1, t2 - 1, t3);
            tr.print_tree();
        } else if(t1 == 3) {
            cin >> t2 >> t3;
            tr.print_tree();
            cout << tr.query(t2 - 1, t3 - 1) << endl;
        }
    }
    return 0;
}
#pragma clang diagnostic pop