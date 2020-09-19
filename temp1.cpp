#include <iostream>
#include <algorithm>
using namespace std;
int n;
int main(){
    long long a,b;
    while(cin>>a>>b){
        if (a >= 0 and b >= 0) {
            long long sum = a+b;
            if(sum < a){
                // 溢出
                sum = ((unsigned long long)sum) - (1ULL<<63);
                sum /= 2;
                sum += (1LL<<62);
                cout<<sum<<endl;
            }else{
                cout<<sum/2<<endl;
            }
        } else if ((a>=0) + (b>=0) == 1){
            if(a+b >= 0)
                cout<<(a+b)/2<<endl;
            else
                cout<<((a+b - 1) / 2) << endl;
        } else {
            long long sum = a+b;
            if(sum > a){
                sum = ((unsigned long long)sum) + (1ULL<<63);
                sum = (sum-1)/2;
                sum -= (1LL<<62);
                cout<<sum<<endl;
            }else{
                cout<<(sum-1)/2<<endl;
            }
        }
    }

}
// 9000000000000000000