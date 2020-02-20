#include <iostream>
#include <vector>
#include <cstdlib>
#include <sstream>
using namespace std;
//从3w个图书馆里找1.5w个，就当他们的书全都能印

int shit,bookCnt,ret=0,seed;
int B,L,D,buffer;
int maxCnt=0,maxId;
vector<int> V[30005];

int main(int argc,char **argv){
    stringstream ss;
    ss<<argv[1];
    ss>>seed;
    srand(seed);
    //cout<<"yo"<<endl;
    int maxVectorCnt,maxThisCnt;
    cin>>B>>L>>D;
    for(int i=0;i<B;i++)
        cin>>shit;
    for(int i=0;i<L;i++){
        cin>>bookCnt>>shit>>shit;//shit1=2,shit2=1
        for(int j=0;j<bookCnt;j++){
            cin>>buffer;
            V[i].push_back(buffer);
        }
    }
    //cout<<"yo"<<endl;
    //cout<<"15000"<<endl;
    for(int k=0;k<15000;k++){//共选15000轮
        maxCnt=0;
        for(int i=0;i<L;i++){//选出可提供最多的
            if(maxCnt<V[i].size()||(maxCnt==V[i].size()&&rand()%2)){
                maxCnt=V[i].size();
                maxId=i;
            }
        }
        //cout<<"yo"<<endl;
        maxVectorCnt=V[maxId].size();
        for(int i=0;i<L;i++){//删除选中的
            if(i==maxId)
                continue;
            for(int j=0;j<maxVectorCnt;j++){
                maxThisCnt=V[i].size();
                for(int k=0;k<maxThisCnt;k++){
                    //cout<<"maxId="<<maxId<<",j="<<j<<",i="<<i<<",k="<<k<<"\n";
                    if(V[maxId][j]==V[i][k]){
                        V[i].erase(V[i].begin()+k);
                    }
                }
            }
        }
//        cout<<maxId<<" "<<maxCnt<<"\n";
//        for(int j=0;j<maxVectorCnt;j++)
//            cout<<V[maxId][j]<<" ";
//        cout<<"\n";
        ret+=maxCnt;
        V[maxId].clear();
    }

    cout<<ret*65<<endl;
    return 0;
}
