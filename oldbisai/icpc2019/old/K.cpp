#include <iostream>
#include <map>
#define MAXN 1010

using namespace std;

class point{
    public:
        int x,y;
        bool operator<(const point& t) const{
            if(x != t.x){
                return x < t.x;
            }
            return y < t.y;
        }
};

int Xs[MAXN] = {0};
int Ys[MAXN] = {0}; // 储存点的坐标
/*
int cxs[MAXN * MAXN] = {0};
int cys[MAXN * MAXN] = {0};
int count[MAXN * MAXN] = {0};
*/
int n;

map<point,int> data1;

struct point make_point(int x,int y){
    struct point p;
    p.x = x;
    p.y = y;
    return p;
}

//int c = 0;
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    int t1,t2;
    for(int i = 0;i < n; ++ i){
        cin>>Xs[i]>>Ys[i];
    }
    for(int i = 0; i < n; ++ i){
        for(int j = 0; j < n; ++ j){
            //if((Xs[i] + Xs[j]) % 2 == 0 and (Ys[i] + Ys[j]) % 2 == 0){
                data1[make_point(Xs[i] + Xs[j] ,  Ys[i] + Ys[j])] += 1;
                //cout<<1;
            //}
            //cout<<i<<" "<<j<<endl;
        }
    }
    struct point maxp;
    int ma=0;
    for(auto i = data1.begin(); i != data1.end(); ++ i){
        if(i->second > ma){
            ma = i->second;
            maxp = i->first;
        }
        //cout<< i->first.x <<" " << i->first.y <<" " <<  i->second << endl;
    }
    /*
    for(int i = 0; i < n; ++ i){
        if(maxp.x / 2.0 == Xs[i] and maxp.y / 2.0 == Ys[i]){
            cout<<(n - 2 * ma + 1);
            return 0;
        }
    }
    */
    cout<<(n - ma);
    return 0;
}