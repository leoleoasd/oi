#include <iostream>
#include <algorithm>
using namespace std;

struct P{
    int time;
    int id;
    P(int a,int b){
        time=a;
        id=b;
    }
    bool operator<(struct P a){
        if(time < a.time){
            return true;
        }
        return id < a.id;
    }
};
int main(){
    int n;
    #define MAXN 1000
    P data[MAXN];
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>data[i].time;
        data[i].id=i;
    }
    sort(data,data+n);
    for(int i=0;i<n;++i){
        cout<<data[i].id<<" ";
    }
    return 0;
}