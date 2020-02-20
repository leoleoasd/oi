#include <stdio.h>
#include <string.h>

int sta;
long dp[256];
long solve(int ste);

int main(void){
    memset(dp, 0, sizeof(dp));
    scanf("%d", &sta);
    printf("%ld", solve(sta - 1));

    return 0;
}

long solve(int ste){
    if (dp[ste] != 0) return dp[ste];
    if (ste == 1) return 1;
    if (ste == 2) return 2;
    else return dp[ste] = (solve(ste - 1) + solve(ste - 2));

}