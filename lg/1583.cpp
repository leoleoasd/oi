#include <bits/stdc++.h>
using namespace std;
#define MAXN 20005

// Vars
int n,k;
int e[11]={0};

class Player{
    public:
    int score;
    int id;
    Player(int a,int b){
        this->id = a;
        this->score = b;
    }
    Player(){
        this->id=0;
        this->score=0;
    }
    bool operator< (const Player a) const{
        if(this->score != a.score){
            return this->score < a.score;
        }
        return this->id > a.id;
    }
    bool operator> (const Player a) const{
        if(this->score != a.score){
            return this->score > a.score;
        }
        return this->id < a.id;
    }
};

Player w[MAXN];

int main(){
    int t1,t2;
    cin>>n>>k;
    for(int i=1;i<=10;++i)
        cin>>e[i];
    for(int j=1;j<=n;++j){
        cin>>t1;
        w[j] = Player(j,t1);
    }
    sort(w+1,w+n+1,greater<Player>());
    for(int i=1;i<=n;++i){
        t1 = (i-1) % 10 + 1;
        w[i].score += e[t1];
    }
    
    sort(w+1,w+n+1,greater<Player>());
    for(int i=1;i<=k;++i){
    cout<<w[i].id<<" ";
    }
    return 0;
}