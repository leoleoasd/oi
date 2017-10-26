#include <iostream>
#include <string>
using namespace std;
int p1,p2,p3;
bool is_word(char a){
    return a <= 'z' and a >= 'a';
}
bool is_num(char a){
    return a <= '9' and a >= '0';
}
int judge(char a){
    if(is_word(a)) return 1;
    if(is_num(a)) return -1;
    return 0;
}
void add(string &to,char from,int num){
    if(num<=0){
        return;
    }
    if(p1==3){
        for(int i=0;i<num*p2;++i)
            to+=("*");
        return 0;
    }
    if(is_word(from) and p1==2){
        from += 'A'-'a';
    }
    if(p3==1){
        for(char i = from;i < from+num;++i){
            for(int j=0;j<p2;++j){
                to+=(i);
            }
        }
    }else{
        for(char i = from+num-1;i>=from;--i){
            for(int j=0;j<p2;++j){
                to+=(i);
            }
        }
    }
}
int main(){
    string from,to;
    cin>>p1>>p2>>p3;
    cin>>from;
    for(int i=0;i<from.size();++i){
        if(from[i]!='-'){
            to+=(from[i]);
            continue;
        }
        if(judge(from[i-1])==judge(from[i+1])){
            add(to,from[i-1]+1,from[i+1]-from[i-1]-1);
        }else{
            to+=(from[i]);
            continue;
        }
    }
    cout<<to;
    return 0;
}
