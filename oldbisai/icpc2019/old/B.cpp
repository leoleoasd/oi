#include <iostream>
#include <map>
using namespace std;

map<int,bool> marked;
map<int,int> next1;
int n,q;
int main(){
    cin>>n>>q;
    int z,x;
    while(q--){
        cin>>z>>x;
        if(z == 1){
            marked[x] = true;
            if(next1.count(x+ 1) == 0){
                next1[x] = x + 1;
            }else{
                next1[x] = next1[x+1];
            }
        } else {
            while(true) {
                if(next1.count(x) == 0){
                    cout<<x<<endl;
                    break;
                }
                if(marked.count(next1[x]) == 0) {
                    cout<<next1[x]<<endl;
                    break;
                }
                if(marked[next1[x]] == false) {
                    cout<<next1[x]<<endl;
                    break;
                }
                x = next1[x];
            }
        }
    }
    return 0;
}
/*
a[i] : i以后第一个可用
b[i] : 布尔,标记是否可用

初始化: a[i] = i

更新: a[i] = a[i+1]

查询:
while true :
    if b[a[i]] = true return a[i]
    i = a[i]
*/