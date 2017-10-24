#include <cstdio>
#include <iostream>
#include <ccstdlib>
#include <ctime>
int main(){
    int n =0 ;
    cin>>n;
    srand( (unsigned)time( NULL ) );
　　for(int i = 0; i < n;i++ )
　　　　printf("%d ", rand() );
}