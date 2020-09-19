#include<stdio.h>
#include<stdlib.h>
#define MAXN 110
struct memory{
    int begin;
    int end;
};
int n = 0;
struct memory mem[MAXN] = {0};

int cmp(const void * a,const void * b){
    if(((struct memory*)a)->begin != ((struct memory*)b)->begin){
        return ((struct memory*)a)->begin - ((struct memory*)b)->begin;
    }
    return ((struct memory*)a)->end - ((struct memory*)b)->end;
}

int main(){
    int i = 0;
    scanf("%d", &n);
    for(i = 0; i < n; ++ i){
        scanf("%d%d", &mem[i].begin, &mem[i].end);
    }
    qsort(mem, n, sizeof(struct memory), cmp);
    for(i = 0; i < n; ++ i){
        if(!(i > 0 && mem[i-1].end+1 == mem[i].begin)){
            printf("%d ", mem[i].begin);
        }
        if(!(i < n-1 && mem[i].end+1 == mem[i+1].begin)){
            printf("%d\n", mem[i].end);
        }
    }
    return 0;
}
/*
10
48 99
0 39
1024 2047
100 479
4000 5999
600 799
40 47
2048 3047
840 859
8000 8999

 */