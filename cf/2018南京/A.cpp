#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
#define MAXN 1000010
class bits{
    public:
        int a;
};
int cnt = 0;
int prime[MAXN]={0};//存素数 
bool vis[MAXN]={0};//保证不做素数的倍数 
bool isPrime[MAXN] = {0};
//int app[MAXN][11] = {0};
int a[MAXN] = {0};
int n = 0; 
vector<int> app[MAXN];
int indexes[MAXN] = {0};
int ivis[MAXN] = {0};
int icnt = 0;
int main(){
    for(int i = 2; i <= MAXN; i++)
    {
        if(!vis[i])//不是目前找到的素数的倍数 
        prime[cnt++] = i;//找到素数~ 
        isPrime[i] = 1;
        for(int j = 0; j<cnt && i*prime[j]<=MAXN; j++)
        {
            vis[i*prime[j]] = true;//找到的素数的倍数不访问 
            if(i % prime[j] == 0) break;//关键！！！！ 
        }
    }
    
    scanf("%d",&n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d",&a[i]);
    }
    long long ans = 0;
    /*
    for(int i = 0; i < cnt; ++ i){
        app = vector<int>(0);
        for(int j = 1; j <= n; ++ j ){
            if(a[j] % prime[i] == 0){
                app.push_back(j);
            }
        }
        if(app.size()){
            for(int j = 0; j < app.size()-1; ++ j){
                ans += (app[j]) * (app[j+1] - app[j]);
            }
            ans += (app.back()) * (n+1-app.back());
        }
    }
    */
    for(int j = 1; j <= n; ++ j){
        if(isPrime[a[j]]){
            app[a[j]].push_back(j);
            indexes[icnt++]=a[j];
            continue;
        }
        for(int i = 0; i < cnt; ++ i){
            if(a[j] % prime[i] == 0){
                app[prime[i]].push_back(j);
                indexes[icnt++] = prime[i];
                while(a[j] % prime[i] == 0){
                    a[j] /= prime[i];
                }
            }
            if(a[j] < prime[i]) break;
            if(isPrime[a[j]]){
                app[a[j]].push_back(j);
                indexes[icnt++]=a[j];
                break;
            }
        }
    }
    for(auto i = 0;i<icnt; ++ i){
        if(ivis[indexes[i]]) continue;
        ivis[indexes[i]] = 1;
        if(app[indexes[i]].size()){
            for(int j = 0; j < app[indexes[i]].size()-1; ++ j){
                ans += (long long)(app[indexes[i]][j]) * (app[indexes[i]][j+1] - app[indexes[i]][j]);
            }
            ans += (long long)(app[indexes[i]].back()) * (n+1-app[indexes[i]].back());
        }
    }
    cout<<ans;
    return 0;
}