#include <iostream>
#include <string>
using namespace std;
int main(){
    string input;
    cin>>input;
    if(input.size() % 2 == 0){
        cout<<"NN\n";
    }else{
        cout<<"N\n";
    }
    return 0;
}