#include <iostream>
using namespace std;
int main() {
    int n = 0;
    cin>>n;
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            printf("%d ", i);
        }
    }
    return 0;
}