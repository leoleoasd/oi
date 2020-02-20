#include <iostream>
#include <algorithm>
using namespace std;
int n,k;
int pools[500020] = {0};
// int k;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>n>>k){
        for(int i = 0; i < n; ++ i){
            cin>>pools[i];
        }
        sort(pools,pools+n);
        while(k != 0){
            int pos = 0;
            int amount = pools[n-1];
            for(int i = n-2; i >= 0; --i){
                if(amount == pools[i]) pos = i;
                else break;
            }
            long long amount_to_remove = (n-pos) * (amount - pools[pos-1]);
            cout<<amount_to_remove<<endl;
            if(amount_to_remove > k){
                int t = k / (n-pos);
                for(int i = n-1; i >= pos; --i){
                    pools[i] -= t;
                }
                k -= t * (n-pos);
                for(int i = pos; k !=0; ++i){
                    pools[i] -= 1;
                    k--;
                }
                cout<<123;
                break;
            }
            k -= amount_to_remove;
            for(int i = n-1; i >= pos; --i){
                pools[i] = pools[pos - 1];
            }
            while(amount_to_remove > 0){
                int lpos = 0;
                for(int i = 0;; ++ i){
                    if(pools[i] == pools[0]) lpos = i;
                    else break;
                }
                if(amount_to_remove > (lpos+1) * (pools[lpos+1] - pools[0])){
                    amount_to_remove -= (lpos+1) * (pools[lpos+1] - pools[0]);
                    for(int i = 0; i <= lpos; ++ i){
                        pools[i] =pools[lpos+1];
                    }
                }else{
                    int t = amount_to_remove / (lpos+1);
                    for(int i = 0; i <= lpos; ++ i){
                        pools[i] += t;
                    }
                    amount_to_remove -= (lpos+1) * t;
                    for(int i = lpos; amount_to_remove; --i){
                        pools[i] += 1;
                        amount_to_remove --;
                    }
                }
            }
        }
        cout<<pools[n-1] - pools[0]<<'\n';
    }
}