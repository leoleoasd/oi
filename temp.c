
#define MAXN 100
#define MAXM 100
#define max(a,b) ((a)>(b)?(a):(b))
int n,m;
int cache[MAXN][MAXM] = {0};
int data[MAXN][MAXM] = {0};

int dfs(int i, int j){
    if (cache[i][j] != 0) {
        return cache[i][j];
    }
    int maxa = 0;
    if (i - 1 >= 0 && data[i-1][j] < data[i][j]) {
        maxa = max(maxa, dfs(i-1,j)+1);
    }
    if (i + 1 < n && data[i+1][j] < data[i][j]){
        maxa = max(maxa, dfs(i+1,j)+1);
    }
    if (j - 1 >= 0 && data[i][j] < data[i][j-1]) {
        maxa = max(maxa, dfs(i,j+1)+1);
    }
    if (j + 1 < m && data[i][j] < data[i][j+1]){
        maxa = max(maxa, dfs(i,j-1)+1);
    }
    return cache[i][j] = maxa;
}
