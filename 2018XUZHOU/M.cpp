#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
#define MAXN 1010
#define inf 0x3f3f3f3f
#define max(a, b) ((a) > (b) ? (a) : (b))
#define LL long long
int n, m;

LL xs[MAXN] = {0};
LL ys[MAXN] = {0};
LL lxs[MAXN] = {0};
LL lys[MAXN] = {0};
LL dat[MAXN][MAXN] = {0};

struct fg // 覆盖
{
    int l, s;
} fgs[MAXN];

int cmp(fg a, fg b) {
    if (a.l != b.l) {
        return a.l < b.l;
    }
    return a.s < b.s;
}

void solve() {
    for (int i = 0; i < m; ++i) // 枚举每个灯泡
    {
        for (int j = 0; j < n; ++j) // 枚举每个顶点
        {
            int next = (j == 0) ? n - 1 : j - 1;
            // p1 : x[j] p2: lx[i] p3: x[next]
            dat[i][j] = (lxs[i] - xs[j]) * (ys[next] - lys[i]) -
                        (lys[i] - ys[j]) * (xs[next] - lxs[i]);
            dat[i][j] = dat[i][j] < 0 ? 1 : 0;
        }
    }
    /*
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << dat[i][j] << " ";
        }
        cout << endl;
    }
    */
    for (int i = 0; i < m; ++i) {
        int beg = -1;
        int end = -1;
        for (int j = 0; j < n; ++j) {
            if (dat[i][j] == 0 and dat[i][(j + 1) % n] == 1) {
                beg = (j + 1) % n;
            }
        }
        for (int j = 0; j < n; ++j) {
            if (dat[i][j] == 1 and dat[i][(j + 1) % n] == 0) {
                end = j;
            }
        }
        fgs[i].l = beg;
        fgs[i].s = (end+1-beg+n)%n;
    }
    /*
    for (int i = 0; i < m; ++i) {
        cout << fgs[i].l << " " << fgs[i].s << endl;
    }
    */
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        for (int j = 0; j < m; ++j) {
            cnt += dat[j][i];
        }
        if (cnt == 0) {
            cout << "-1" << endl;
            return;
        }
    }
    sort(fgs,fgs+m,cmp);
    int mincnt = 0x3fffffff;
    int cnt = 1;
    int minstart = -1;
    for(int i = 0; i < m; ++ i){ // 枚举灯,起点
        int now = fgs[i].s;
        int to_go = -1;
        for(int j = i+1;j != i;){
            // 枚举每一个区间
            if(fgs[j].l <= (fgs[i].l+now)%n){
                if(fgs[j].s + fgs[j].l - fgs[i].l > now)
                    to_go = max(to_go, fgs[j].s + fgs[j].l - fgs[i].l - now);
                j = (j+1)%m;
                continue;
            }
            if(to_go != -1){
                cnt++;
                now = now + to_go;
                to_go = -1;
                if(now >= n){
                    //完成了
                    break;
                }
                continue;
            }
            break;
        }
        if(now < n){
            if(to_go != -1){
                cnt++;
                now = now + to_go;
            }
        }
        if(now<n)continue;
        //cout<<cnt<<"C"<<endl;
        if(cnt < mincnt){
            mincnt = cnt;
            minstart = i;
        }
    }
    cout<<mincnt<<endl;
    cnt = 1;
    for(int i = minstart;;){ // 枚举灯,起点
        cout<<i+1<<" ";
        int now = fgs[i].s;
        int to_go = -1;
        int t = 0;
        for(int j = (i+1)%n; j != i;){
            // 枚举每一个区间
            if(fgs[j].l <= (fgs[i].l+now)%n){
                if(fgs[j].s + fgs[j].l - fgs[i].l > now)
                    if(to_go < fgs[j].s + fgs[j].l - fgs[i].l - now){
                        to_go = fgs[j].s + fgs[j].l - fgs[i].l - now;
                        t = j;
                    }
                j = (j+1)%m;
                continue;
            }
            if(to_go != -1){
                cout<<t+1<<" ";
                cnt++;
                now = now + to_go;
                to_go = -1;
                if(now >= n){
                    cout<<endl;
                    //完成了
                    break;
                }
                continue;
            }
            j = (j+1)%m;
        }
        if(now < n){
            if(to_go != -1){
                cout<<t+1<<endl;
                now = now + to_go;
            }
        }
        break;
    }
    /*
    sort(fgs, fgs + m, cmp);
    int minn = inf, wei = -1;
    for (int i = 0; i < m; ++i) // qidian
    {
      int r = fgs[i].r;
      int cnt = 1;
      int flag = -1;
      int flagg = -1;
      for (int j = i + 1; j != i; j = (j + 1) % m) {
        if (fgs[j].l <= r + 1 && fgs[j].r > r) {
          flag = max(flag, (fgs[i].r - r + n) % n);
        } else {
          if (flag != -1) {
            cnt++;
            //                    int u=-1;
            if ((r + flag + 1) % n >= fgs[i].l) {
              flagg = 0;
            }
            //                    if(r+flag>=n)
            r = (r + flag) % n;
            flag = -1;
            if (flagg == 1)
              break;
          } else
            break;
        }
      }
      if (minn > cnt) {
        minn = cnt;
        wei = i;
      }
    }
    int r = fgs[wei].r;
    //        int cnt = 1;
    int flag = -1;
    cout << minn << endl;
    cout << wei + 1 << " ";
    int y = -1, c = 1;
    for (int j = wei; j != wei; j = (j + 1) % n) {
      if (fgs[j].l <= r + 1 && fgs[j].r > r) {
        if (flag < (fgs[j].r - r + n) % n) {
          flag = (fgs[j].r - r + n) % n;
          y = j;
        }
        //            flag=max(flag,);
      } else {
        if (flag != -1) {
          cout << j + 1 << " ";
          //                if(r+flag>=n)
          //                    flagg=0;
          r = (r + flag) % n;
          c++;
          if (c >= minn)
            break;
          flag = -1;
        } else
          break;
      }
    }
    */
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            cin >> xs[i] >> ys[i];
        }
        for (int i = 0; i < m; ++i) {
            cin >> lxs[i] >> lys[i];
        }
        solve();
    }
    return 0;
}
/*
2
3 3
0 0
1 0
0 1
-1 -1
3 -1
-1 3
3 3
0 0
2 1
1 2
2 0
0 2
2 2
*/