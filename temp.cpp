#include <iostream>
#include <cstdlib>
using namespace std;
int main(){

    cout<<(int)L'鼠'<<" "<<(int)L'年'<<" "<<(int)L'大'<<" "<<(int)L'吉'<<endl;

    int mod = 20000;
    for (unsigned int seed = 1; seed != 0; seed++) {
        // endless loop;
        srand(seed);
        int rd1, rd2, rd3, rd4;
        rd1 = rand() % mod + add;
        rd2 = rand() % mod + add;
        rd3 = rand() % mod + add;
        rd4 = rand() % mod + add;
        if (rd1 - rd2 == L'鼠' - L'年' and rd2 - rd3  == L'年' - L'大' and rd3 - rd4 == L'大' - L'吉') {
            cout << seed << " "<< endl;
            return 0;
        }
    }
    return 0;
}