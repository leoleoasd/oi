#include <iostream>
using namespace std;
#define MAXN 15
int data[MAXN][MAXN]={0};
int input[MAXN]={0};
int main(){
    int n;
    cin>>n;
    int sum = 0;
    for(int i=0;i<n;++i){
        cin>>input[i];
        sum += input[i];
        
    }
    if(sum%2!=0){
        cout<<"None";
        return 0;
    }
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j){
            if(input[i]!=0 and input[j]!=0 and i != j and data[i][j]==0){
                data[i][j]=1;
                data[j][i]=1;
                --input[i];
                --input[j];
            }
    }
    for(int i=0;i<n;++i){
        if(input[i]!=0){
            cout<<"None";
            return 0;
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j)
            cout<<data[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}