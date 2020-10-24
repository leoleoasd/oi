#include <iostream>
using namespace std;

#define lson (now*2)
#define rson (now*2+1)

long long query(long long x){
    cout<<x<<endl;
    long long t;
    cin>>t;
    return t;
}
int main(){
    long long n = 0;
    long long now = 1;
    long long now_depth = 0;
    long long answer = 0;
    cin>>n;
    long long answer_depth = query(1);
    if (answer_depth == 0) {
        cout<<"! 1"<<endl;
        return 0;
    }
    while(true){
        //cout<<"n"<<now<<"nd"<<now_depth<<"ad"<<answer_depth<<endl;
        long long d = query(lson);
        if (d == 0){
            cout<<"! "<<lson<<endl;
            return 0;
        }
        if (now_depth == answer_depth - 1) {
            cout<<"! "<<rson<<endl;
            return 0;
        } else {
            if (now_depth + d + 1!= answer_depth){
                now = rson;
            } else {
                now = lson;
            }
            now_depth ++;
        }
    }
    return 0;
}