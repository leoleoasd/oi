#include <iostream>
using namespace std;
int main(){
    char tmp;
    int a11[200][2]={0};
    int a11pos = 0;
    int a21[200][2]={0};
    int a21pos = 0;
    cin>>tmp;
    while(tmp != 'E'){
        if(tmp == "W"){
            a11[a11pos][0]++;
            if(a11[a11pos][0]+a11[a11pos][1]==11){
                ++a11pos;
            }
            a21[a21pos][0]++;
            if(a21[a21pos][0]+a21[a21pos][1]==21){
                ++a21pos;
            }
        }else{
            a11[a11pos][1]++;
            if(a11[a11pos][0]+a11[a11pos][1]==11){
                ++a11pos;
            }
            a21[a21pos][1]++;
            if(a21[a21pos][0]+a21[a21pos][1]==21){
                ++a21pos;
            }
        }
    }
    for(int i=0;i<=a11pos;++i){
        cout<<a11[i][0]<<":"<<a11[i][1]<<endl;
    }
    cout<<endl;
    for(int i=0;i<=a21pos;++i){
        cout<<a21[i][0]<<":"<<a21[i][1]<<endl;
    }
    return 0;
}