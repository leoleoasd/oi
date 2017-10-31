#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
//using namespace std;
struct toy{
    string name;
    int cx;
    toy(string a,int b){
        name=a;
        cx=b;
    }
    toy(){}
};
#define MAXN 100020
toy toys[MAXN];
int main(){
    int n,m;
    string tmp;
    int a,b,c,d,e;
    cin>>n>>m;
    for(int i=0;i<n;++i){
        cin>>a>>tmp;
        if(a==0)a=-1;
        toys[i]=toy(tmp,a);
    }
    int f = 0;
    int now = 0;
    for(int i=0;i<m;++i){
        cin>>a>>b;
        if(a==0)a=-1;
        f = -(a*toys[now].cx);
        now += f*b;
        now += n;
        now %= n;
    }
    cout<<toys[now].name;
    return 0;
}
