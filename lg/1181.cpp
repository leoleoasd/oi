#include <bits/stdc++.h>
using namespace std;
#define MAXN 100100
int data[MAXN]={0};
int n = 0;
int maxn = 0;
int main(){
    cin>>n>>maxn;
    for(int i = 0; i < n; ++i){
        cin>>data[i];
    }
    int output = 0;
    int sum = 0;
    for(int i = 0; i < n; ++i){
        if(sum + data[i] <= maxn){
            sum += data[i];
            continue;
        }
        output += 1;
        sum = data[i];
    }
    cout<<output+1;
    return 0;
}