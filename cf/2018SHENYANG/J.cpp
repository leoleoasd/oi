#include <cstdio>
#include <iostream>
using namespace std;

inline long long solve(){
    int n;
    long long UsedMem = 0;
    scanf("%d",&n);
    getchar();
    char c;
    long long this_mem = -1;
    long long size = 1;
    for(int i = 0; i < n; ++ i){
        // 获取类型
        this_mem = -1;
        size = 1;
        c = getchar();
        switch(c){
            case 'c': // char
                //cout<<"char"<<endl;
                this_mem = 1;
                break;
            case 'i': // int
                //cout<<"int"<<endl;
                this_mem = 4;
                break;
            case 'l': //long long 或 long double
                // TODO
                getchar(); // 'o'
                getchar(); // 'n'
                getchar(); // 'g'
                getchar(); // ' '

                c = getchar();
                if(c == 'd'){ // long double
                    //cout<<"ld"<<endl;
                    this_mem = 16;
                }else{ // long long
                    //cout<<"ll"<<endl;
                    this_mem = 8;
                }
                break;
            case '_': // __int128
                //cout<<"i128"<<endl;
                this_mem = 16;
                break;
            case 'f': // float
                //cout<<"float"<<endl;
                this_mem = 4;
                break;
            case 'd': // double
                //cout<<"double"<<endl;
                this_mem = 8;
                break;
            case 'b': // bool
                //cout<<"bool"<<endl;
                this_mem = 1;
                break;
        }
        c = getchar();
        while(c != '\n'){
            if(c == '['){
                scanf("%lld",&size);
            }
            c = getchar();
        }
        UsedMem += this_mem * size;
    }
    return (UsedMem+1023)/1024;
}

int main(){
    int t;
    scanf("%d",&t);
    for(int i = 1;i <= t; ++ i){
        printf("Case #%d: %lld\n",i,solve());
    }
    return 0;
}