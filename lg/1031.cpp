#include <iostream>
using namespace std;
int main(){
    #define MAXN 100
    int n;
    int data[MAXN]={0};
    cin>>n;
    int output = 0;
    int sum = 0;
    for(int i=1;i<=n;++i){
        cin>>data[i];
        sum += data[i];
    }
    int avg = sum / n;
    for(int i=1;i<=n;++i){
        data[i] -= avg;
    }
    for(int i=1;i<=n;++i){
        if(data[i]==0){continue;}
        ++output;
        data[i+1]+=data[i];
        data[i]=0;
    }
    cout<<output;
    return 0;
}
