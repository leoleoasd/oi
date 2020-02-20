#include <iostream>
#include <queue>
using namespace std;

#define endl "\n"
#define MAXN 1010

int father[MAXN] = {0};
int root = -1;

vector<int> childrens[MAXN];

int main(){
    int n;
    cin>>n;
    if(n == 0){
        cout<<0<<endl;
        return 0;
    }
    for(int i = 1; i <= n; ++ i){
        cin>>father[i];
        if(father[i] == 0) root = i;
        childrens[father[i]].push_back(i);
    }
    queue< pair<int, int> > que;
    que.push(make_pair(root, 1));
    int ans = -1;
    while(!que.empty()){
        auto p = que.front();
        que.pop();
        if(p.second > ans){
            ans = p.second;
        }
        for(auto i = childrens[p.first].begin(); i != childrens[p.first].end(); ++ i){
            que.push(make_pair(*i,p.second+1));
        }
    }
    cout<<ans<<endl;
    return 0;
}