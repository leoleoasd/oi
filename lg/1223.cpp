#include <iostream>
#include <algorithm>
#include <cstdio>
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
        if(time != a.time){
            return time>a.time;
        }
        return id < a.id;
    }
};
int main(){
    int n;
    #define MAXN 1050
    P data[MAXN];
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>data[i].time;
        data[i].id=i;
    }
    sort(data,data+n);
    float output = 0;
    for(int i=n-1;i>=0;--i){
        cout<<data[i].id+1<<" ";
        output += i * data[i].time;
    }
    cout<<endl;
    printf("%.2f",output/n);
    return 0;
}