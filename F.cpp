#pragma clang diagnostic push
#pragma ide diagnostic ignored "hicpp-signed-bitwise"
#include <iostream>
#include <string>
using namespace std;


#define MAXN 100000
#define TreeSize 4*MAXN
#define lson ((n<<1u)+1)
#define rson ((n<<1u)+2)
#define mid ((l+r)/2)
#define LL long long
#define now nodes[n]
#define tmid ((now.l + now.r)/2)
//#define DEBUG
#define isLeaf(a) (nodes[a].l == nodes[a].r)

struct node{
    LL v[3] = {0};
    LL lazy = 0;
    LL l = 0, r = 0;

    void rollover(int t = 1){
        LL tmp[3];
        for (int i = 0; i < 3; i++) {
            tmp[i] = v[i];
        }
        for (int i = 0; i < 3; i++) {
            v[(i + t) % 3] = tmp[i];
        }
    }
};

struct tree{
    node nodes[TreeSize];

    void build(LL n){
        buildTree(0, n-1, 0);
    }

    void buildTree(LL l, LL r, LL n){
        if(l > r)return;
        now.l = l;
        now.r = r;

        if(l == r){
            now.v[1] = 1;
            return;
        }else{
            buildTree(l, mid, lson);
            buildTree(mid+1, r, rson);
            now.v[1] = r-l+1;
        }
    }


    void add(LL l, LL r, int n = 0){
#ifdef DEBUG
        cout<<"Adding "<<l<<" "<<r<<" "<<n<<endl;
#endif
        if(now.l == l and now.r == r){
            now.rollover();
            now.lazy += 1;
            print_tree();
            return;
        }
        pushdown(n);
        if(r <= tmid){
            add(l, r, lson);
        }else if(l >= tmid+1){
            add(l, r, rson);
        }else{
            add(l, tmid, lson);
            add(tmid+1, r, rson);
        }
        now.v[0] = nodes[lson].v[0] + nodes[rson].v[0];
        now.v[1] = nodes[lson].v[1] + nodes[rson].v[1];
        now.v[2] = nodes[lson].v[2] + nodes[rson].v[2];
        print_tree();
    }

    void pushdown(LL n){
        if(now.lazy == 0) return;
        if(now.l == now.r){
            now.lazy = 0;
            return;
        }
        nodes[lson].rollover(now.lazy);
        nodes[rson].rollover(now.lazy);
        nodes[lson].lazy += now.lazy;
        nodes[rson].lazy += now.lazy;
        now.lazy = 0;
    }

    LL query(LL l, LL r, LL n = 0){
        if(now.l == l and now.r == r){
            return now.v[0];
        }
        if(now.lazy){
            pushdown(n);
        }
        if( r <= tmid ){
            return query(l,r,lson);
        }else if(l >= tmid+1){
            return query(l,r, rson);
        }else {
            return query(l, tmid, lson) + query(tmid+1, r, rson);
        }
    }

    void print_tree(){
#ifdef DEBUG
        for(int i = 0;i <= 8; ++ i){
            cout<<"PRINT "<<i<<" L "<<this->nodes[i].l<<" R "<<this->nodes[i].r<<" V "<<this->nodes[i].v[0]<<" "<<this->nodes[i].v[1]<<" "<<this->nodes[i].v[2]<<" "<<" L "<<this->nodes[i].lazy<<endl;
        }
#endif
    }
};

tree tr;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    tr.build(n);
    tr.print_tree();
    string tmp;
    int l,r;
    for(int i = 0 ; i < m ;++ i){
        cin>>tmp>>l>>r;
        if(tmp == "ADD"){
            tr.add(l-1,r-1);
        }else{
            cout<<tr.query(l-1,r-1)<<"\n";
        }
    }
    return 0;
}
#pragma clang diagnostic pop