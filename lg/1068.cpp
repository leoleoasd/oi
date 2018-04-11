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

        bool operator<(const Player &b){
            return this->score < b.score;
        }
};

int main(){
    Player a,b;
    a.score=1;
    b.score=2;
    cout<<(a<b);
    return 0;
}
