#include <iostream>
using namespace std;
#define MAXN 1000100
int data[MAXN][2] = {0};
int n = 0;
int main(){
    cin>>n;
    for(int i = 0; i < n; ++i){
        cin>>data[i][0]>>data[i][1];
    }
    int now = 0;
    int count = 0;
    bool flag = true;
    int min = 0, minn = 0x7fffffff;
    while (true) {
        flag = false;
        min = 0, minn = 0x7fffffff;
        for(int i = 0; i < n; ++i){
            if(data[i][0] >= now)
                if(minn > data[i][1]){
                    minn = data[i][1];
                    min = i;
                    flag = true;
                }
        }
        if(!flag){
            break;
        }
        now = data[min][1];
        count += 1;
    }
    cout<<count;
    return 0;
}