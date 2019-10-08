#include <iostream>
using namespace std;
int main() {
    int sign = 1;
    int i = 1;
    double sum = 0;
    while((1.0 / i) > 1e-4){
        sum += sign * (1.0 / i);
        sign = !sign;
        i++;
    }
    cout<<sum<<endl;
    return 0;
}