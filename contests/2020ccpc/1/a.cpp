#include <iostream>
#include <queue>
using namespace std;
#define MAXN 100050
#define endl '\n'
int a[MAXN] = {0};
int used[MAXN] = {0};
struct city {
    int price;
    int id;
    bool operator<(const city &c) const {
        return price < c.price;
    }
    bool operator>(const city &c) const {
        return price > c.price;
    }
};
city cities_temp[MAXN];
int city_count = 0;
void solve() {
    int n;
    long long result = 0;
    int op = 0;
    cin>>n;
    for(int i = 0; i < n; ++ i){
        cin>>a[i];
    }
    priority_queue<city> bigQ;
    priority_queue<city, vector<city>, greater<city> > smallQ;
    for(int i = 0; i < n; ++ i){
        bigQ.push(city{a[i],i+1});
        smallQ.push(city{a[i],i+1});
    }
    while(!bigQ.empty() && !smallQ.empty()) {
        city biggest;
        city smallest;
        int flag = 0;
        biggest = bigQ.top();
        bigQ.pop();
        while(used[biggest.id]) {
            if (bigQ.empty()){
                flag = 1;
                break;
            }
            biggest = bigQ.top();
            bigQ.pop();
        }
        used[biggest.id] = 1;
        if (flag) {
            break;
        }
        int t = 0;
        while(true){
            if (smallQ.empty()) {
                flag = 1;
                break;
            }
            cities_temp[t] = smallQ.top();
            smallQ.pop();
            if (cities_temp[t].id < biggest.id && !used[cities_temp[t].id]) {
                smallest = cities_temp[t];
                t -= 1;
                while(t >= 0){
                    smallQ.push(cities_temp[t]);
                    t--;
                }
                break;
            }
            t++;
        }
        if (flag) {
            // zhao bu dao
            break;
        }
        used[smallest.id] = 1;
        result += biggest.price - smallest.price;
        cout<<biggest.price - smallest.price<<" "<<biggest.id<<" "<<smallest.id<<endl;
        op += 2;
    }
    cout<<result<<" "<<op<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;

    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}