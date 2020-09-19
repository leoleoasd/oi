#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n = 0, cnt = 0;
    cin>>n;
    for(int i = 1; i <= n; ++ i){
        string str = to_string(i);
        char last = str[0];
        int flag = 1;
        for(auto j = str.begin(); j != str.end(); ++ j){
            if(*j > last){
                last = *j;
            }else if(*j < last){
                flag = 0;
                break;
            }
        }
        cnt += flag;
    }
    cout<<cnt<<endl;
    return 0;
}
