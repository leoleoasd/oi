#include <iostream>
#include <vector>
using namespace std;
int n;
char t;
pair<vector<int>, vector<int> > read(vector<int> dims) {
    vector<int> p,m;
    if (dims.size() == 1) {
        for(int i = 0; i < dims[0]; ++ i){
            cin>>t;
            if (t == 'P'){
                p.push_back(i+1);
            }
            if (t == 'M'){
                m.push_back(i+1);
            }
        }
        return make_pair(p,m);
    } else {
        for (int i = 0; i < dims[dims.size()-1]; ++ i){
            auto rst = read(vector<int>(dims.begin(), dims.end()-1));
            if (!rst.first.empty()){
                p = rst.first;
                p.push_back(i+1);
            }
            if (!rst.second.empty()){
                m = rst.second;
                m.push_back(i+1);
            }
        }
        return make_pair(p,m);
    }
}

int main() {
    int t;
    vector<int> dims;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>t;
        dims.push_back(t);
    }
    auto rst = read(dims);
//    for (int & i : rst.first) {
//        cout<<i<<" ";
//    }
//    cout<<endl;
//    for (int & i : rst.second) {
//        cout<<i<<" ";
//    }
//    cout<<endl;
    int ans = 0;
    int zs = 0;
    int sqrt = 0;
    for(int i = 0; i < rst.first.size(); ++ i){
        ans += (rst.first[i] - rst.second[i]) * (rst.first[i] - rst.second[i]);
    }
    if (ans == 0){
        cout<<ans<<endl;
        return 0;
    }
    sqrt = ans;
    zs = 1;
    for(int i = 1; i < 46340; ++ i){
        if (ans % (i*i) == 0){
            sqrt /= i*i;
            zs *= i;
        }
    }
    if(zs != 1)
        cout<<zs;
    if(sqrt != 1)
        cout<<"\\sqrt[2]{"<<sqrt<<"}";
    if(zs == 1 and sqrt == 1){
        cout<<1;
    }
    cout<<endl;
    return 0;
}