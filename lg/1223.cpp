#include <iostream>
#include <algorithm>
using namespace std;

struct P{
    int time;
    int id;
    P(){}
    P(int a,int b){
        time=a;
        id=b;
    }
    bool operator<(struct P a){
        if(time > a.time){
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
    for(int i=n;i>0;--i){
        cout<<data[i-1].id+1<<" ";
    }
    return 0;
}