#include<iostream>
#include<cmath>
using namespace std;
int main() {
    int a = 0, n = 0;
    int sum = 0;
    cin>>a>>n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            sum += a * pow(10, j - 1);
        }
    }
    cout<<sum<<endl;
    return 0;
}