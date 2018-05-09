#include <bits/stdc++.h>
using namespace std;
#define  MAXN 105

class student {
    public:
        string name;
        int money;
        int id;
        Student(){
            money=0;
            id=0;
            name="";
        }
        bool operator<(const student B) const{
            if(money != B.money){
                return money < B.money;
            }
            return id > B.id;
        }
        bool operator>(const student B) const{
            if(money != B.money){
                return money > B.money;
            }
            return id < B.id;
        }
};
student data[MAXN];
int main(){
    int n;
    int qmcj,bjcj,lws;
    char xsgb,xbsf;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>data[i].name;
        data[i].id=i;
        cin>>qmcj>>bjcj>>xsgb>>xbsf>>lws;
        if(qmcj > 80 and lws >= 1){
            data[i].money+=8000;
        }
        if(qmcj > 85 and bjcj > 80){
            data[i].money += 4000;
        }
        if(qmcj > 90){
            data[i].money += 2000;
        }
        if(qmcj > 85 and xbsf == "Y"){
            data[i].money += 1000;
        }
        if(bjcj > 80 and xsgb == "Y"){
            data[i].money += 850;
        }
    }
    sort(data,data+n.greater<student>());
    cout<<data[0].name<<endl<<data[0].money<<endl;
    int sum == 0;
    for(int i=0;i<n;++i;)sum += data[i].money;
    cout<<sum;
    return 0;
}
