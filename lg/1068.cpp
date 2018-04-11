#include <bits/stdc++.h>
using namespace std;

class Player{
    public:
        int score;
        int id;
        Player(){
            this->score=0;
            this->id=0;
        }
        Player(int a,int b){
            this->id=a;
            this->score=b;
        }
        bool operator<(const Player &b) const{
            if(this->score != b.score)
            return this->score < b.score;
            return this->id > b.id;
        }
        bool operator>(const Player &b) const{
            if(this->score != b.score)
            return this->score > b.score;
            return this->id < b.id;
        }
};

priority_queue<Player> que;
priority_queue<Player> aque;

int main(){
    int m,n;
    int t1,t2;
    cin>>n>>m;
    for(int i=0;i<n;++i){
        cin>>t1>>t2;
        Player temp(t1,t2);
        que.push(temp);
    }
    for(int i=0;i<m*1.5-1;++i){
        aque.push(que.top());
        que.pop();
    }
    while(aque.top().score == que.top().score){
        aque.push(que.top());
        que.pop();
    }
    cout<<(aque.top().score)<<" "<<aque.size()<<endl;
    while(!aque.empty()){
        cout<<(aque.top().id)<<" "<<(aque.top().score)<<endl;
        aque.pop();
    }
    return 0;
}
