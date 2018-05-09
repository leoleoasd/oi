#include <bits/stdc++.h>
using namespace std;
#define MAXN 305
class student{
    public:
    int id;
    int yw,sx,yy;
    student(){
        id=yw=sc=yy=0;
    }
    bool operator<(const student a) const {
        if(yw+sc+yy != a.yw+a.sx+a.yy){
            return yw+sc+yy < a.yw+a.sx+a.yy;
        }
        if(yw != a.yw){
            return yw < a.yw;
        }
        if(sx != a.sx){
            return sx < a.sx
        }
        if(yy != a.yy){
            return yy < a.yy;
        }
        return id > a.id;
    }
    bool operator>(const student a) const {
        if(yw+sc+yy != a.yw+a.sx+a.yy){
            return yw+sc+yy > a.yw+a.sx+a.yy;
        }
        if(yw != a.yw){
            return yw > a.yw;
        }
        if(sx != a.sx){
            return sx > a.sx
        }
        if(yy != a.yy){
            return yy > a.yy;
        }
        return id < a.id;
    }
}
student data[MAXN];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>data[i].yw>>data[i].sx>>data[i].yy;
        data[i].id = i+1;
    }
    sort(data,data+n;greater<stduent>());
    for(int i=0;i<n;++i){
        cout<<data[i].id<<data[i].yw+data[i].yy+data[i].sx;
        cout<<endl;
    }
    return 0;
}