#include <iostream>
using namespace std;

#define LL long long

long long C,N,P,W;

int main(){
    cin>>C>>N>>P>>W;
    long long tables = 0,woods = W;
    if(W/C > 1e8){
        LL capacity = P*N;
        LL em = P*N-W;
        LL empty = C-P;
        if(empty >= 0){
            cout<<W/C<<endl;
        } else {
            tables += W/C - 1e5;
            woods -= (W/C - 1e5) * C;
            while(woods>=C){
//		cout<<"tables:"<<tables<<",woods:"<<woods<<endl;
                woods -= C;
                tables++;
                long long woodSlots = woods/P;
                if(woods%P!=0)
                    woodSlots++;
                if(tables+woodSlots>N){
                    tables--;
                    break;
                }
            }
            cout<<tables<<endl;
        }
    } else {
        while(woods>=C){
//		cout<<"tables:"<<tables<<",woods:"<<woods<<endl;
            woods -= C;
            tables++;
            long long woodSlots = woods/P;
            if(woods%P!=0)
                woodSlots++;
            if(tables+woodSlots>N){
                tables--;
                break;
            }
        }
        cout<<tables<<endl;
    }
    return 0;
}