#include <bits/stdc++.h>
using namespace std;
class student {
    public:
        string name;
        int money;
        int id;
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
student data[20];
int main(){
    data[0].money=20;
    data[1].money=20;
    data[0].id=0;
    data[1].id=1;
    sort(data,data+2,greater<student>());
    cout<<data[0].money<<" "<<data[0].id;
    return 0;
}
