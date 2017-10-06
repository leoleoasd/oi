#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <map>
using namespace std;

ifstream fin("Q.in");
ofstream fout("Q.out");

#define fin cin
#define fout cout
#define debug 1

#ifdef debug
    #define LOG(A) cout<<A<<" ";
#else
    #define LOG(A)
#endif

#define MM 300

map<int,map<int,int> > data;
int x,y,r1,r2;

inline double jl(int x1,int y1,int x2,int y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

inline void dr(){
    fin>>x>>y>>r1>>r2;
}

inline void mk(){
    int xx=x*MM;
    int yy=y*MM;
    int rr=r1*MM;
    int rr2=r2*MM;
    double jla ;
    for(register int i=xx-rr;i<=xx+rr;++i){
        for(register int j=yy-rr;j<=yy+rr;++j){
            jla = jl(i,j,xx,yy);
            if( jla>= rr2 and jla<= rr){
                data[i][j]=1;
                //cout<<jla<<endl;
                //cout<<i<<j<<endl;
            }
        }
    }
}

inline void zt(){
    int result=0;
    map<int,map<int,int> >::iterator f=data.begin();
    while(f != data.end()){
        map<int,int>::iterator l = f->second.begin();
        while(l != f->second.end()){
            ++result;
            ++l;
        }
        ++f;
    }
    fout<<setprecision(3)<<fixed<<(double(result)/MM/MM);//LOG(result)
}

int main(){
    ios::sync_with_stdio(false);
    int n;
    fin>>n;
    while(n--){
        dr();
        mk();
    }
    zt();
    return 0;
}