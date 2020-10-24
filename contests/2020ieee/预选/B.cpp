#include <iostream>
#include <cstring>

using namespace std;

#define MAXN 200050
char father[MAXN];
char mother[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>father>>mother;
    int m_l = 0;
    int f_l = 0;
    int f_r = 0;
    int m_s = strlen(mother);
    int f_s = strlen(father);

    for(int i = 0; i < m_s; ++ i){
        if(memcmp(mother+i, mother+m_l, m_s - i) > 0 ) {
            m_l = i;
        }
    }

    for(int i = 0; i < f_s; ++ i){
        if(memcmp(father+i, father+f_l, f_s - i) > 0 ) {
            f_l = i;
        }
    }
    for(int i = f_l+1; i < f_s; ++ i){
        if (father[i] < mother[m_l]){
            f_r = i;
            break;
        }
    }
    if(f_r == 0){
        f_r = f_s;
    }
    for(int i = f_l; i < f_r; ++ i){
        cout<<father[i];
    }
    cout<<mother+m_l<<endl;

    return 0;
}