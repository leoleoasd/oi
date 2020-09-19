#include <algorithm>
#include <iostream>
using namespace std;
struct edge {
    int u, v, w;
} edges[1000*1000+20];
int cmp (edge a, edge b) {
    return a.w < b.w;
}
int father[1020];

int findSet(int k) {
    return father[k] == k ? k : father[k] = findSet(father[k]);
}

int main() {
    ios::sync_with_stdio(false);
    int n, nos, wt = 0;
    int t = 0;
    int p = 0;
    cin>>n;
    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= n; ++ j){
            cin>>t;
            if (i < j) {
                edges[p++] = edge{
                    i,j,t
                };
            }
        }
    }
    sort(edges, edges+p, cmp);
    for (int k = 1; k <= n; k++) {
        father[k] = k;
    }
    nos = n;
    for (int k = 0; k < p && nos > 1; k++) {
        int fu = findSet(edges[k].u);
        int fv = findSet(edges[k].v);
        if (fu != fv) {
            father[fu] = fv;
            wt += edges[k].w;
            nos--;
        }
    }
    printf("%d", wt);
    return 0;
}
