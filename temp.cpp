/*
Source Code

Problem: 2135		User: CCGV2
Memory: 1564K		Time: 219MS
Language: G++		Result: Accepted
Source Code
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>
#define inf 1000000000
using namespace std;

struct edge
{
    int dest,f,w;
    edge *next,*rev;
};
struct CostFlow
{
    static const int N=2500;
    static const int M=400100;
    edge pool[M],*head[N],*pre[N];
    int dist[N],vis[N],tot;
    void clear()
    {
        tot=0;
        memset(head,0,sizeof head);
    }
    void add(int u,int v,int f,int w)
    {
        edge *p=&pool[++tot],*q=&pool[++tot];
        p->dest=v;p->f=f;p->next=head[u];p->rev=q;head[u]=p;p->w=w;
        q->dest=u;q->f=0;q->next=head[v];q->rev=p;head[v]=q;q->w=-w;
    }
    pair<int,int> run(int s,int t)
    {
        int ret=0;
        int flow=inf;
        while (1)
        {
            memset(dist,100,sizeof dist);
            memset(pre,0,sizeof pre);
            memset(vis,0,sizeof vis);
            queue <int> Q;
            Q.push(s);
            vis[s]=1;
            dist[s]=0;
            while (!Q.empty())
            {
                int u=Q.front();
                Q.pop();
                vis[u]=0;
                for(edge *p=head[u];p;p=p->next)
                {
                    int v=p->dest;
                    if (!p->f)  continue;
                    if (dist[v]>dist[u]+p->w)
                    {
                        dist[v]=dist[u]+p->w;
                        if (!vis[v])
                            vis[v]=1,Q.push(v);
                        pre[v]=p;
                    }
                }

            }
            if (dist[t]>inf)break;
            flow = inf;
            for (edge *p=pre[t];p;p=pre[p->rev->dest])
            {
                flow=min(flow,p->f);
            }
            for (edge *p=pre[t];p;p=pre[p->rev->dest])
            {
                p->f-=flow;
                p->rev->f+=flow;
                ret+=flow*p->w;
            }
        }
        return make_pair(flow, ret);
    }
}F;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    F.clear();
    int n,m;
    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
    cin >> n >> m;
    int a,b;
    cin>>a>>b;
    int s = n + 1;
    // F.add(s, 1, 2, 0);
    // cout << n << ' ' << m << '\n';
    while (m--) {
        // cout << "1";
        int u,v,f,w;
        cin>>u>>v>>f>>w;
        F.add(u, v, f, w);
        F.add(v, u,
            f, w);
    }
    auto xx = F.run(a,b);
    cout << xx.first << xx.second << endl;
}