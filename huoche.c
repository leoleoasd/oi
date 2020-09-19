#include <stdio.h>
#include <string.h>
#define MAXN 55
int cities = 0;
char names[MAXN][21] = {0};
int miles[MAXN] = {0};

int trains = 0;
int train_id[MAXN] = {0};
char to[MAXN][21] = {0};
int in_position[MAXN] = {0}; // 是否已经到了A中'
int in_position_ids[MAXN] = {0};
int in_position_count = 0;

int pushes = 0;

int main(){
    int i,j;
    int to_move = 0;
    int to_move_count = 0;
    scanf("%d", &cities);
    for(i = 0; i < cities; ++ i){
        scanf("%s %d", names[i], &miles[i]);
    }
    scanf("%d", &trains);
    for(i = 0; i < trains; ++ i){
        scanf("%d %s", &train_id[i], to[i]);
    }

    while (in_position_count != trains){
        to_move = -1;
        to_move_count = 0;
        // 首先找还没到位的最近的
        for(i = cities-1; i >= 0; --i){
            for(j = 0; j < trains; ++j){
                if(!in_position[j] && strcmp(to[j], names[i]) == 0){
                    to_move = j;
                    break;
                }
            }
            if(to_move != -1){
                break;
            }
        }
        // 然后找需要挪几辆车, 就是从车头到这节车厢一共有几节
        for(i = 0; i<= to_move; ++i){
            to_move_count += (in_position[i] == 0);
        }
        pushes += to_move_count;

        if(to_move_count != 1){
            pushes += 1;
        }
        in_position_ids[in_position_count++] = to_move;
        in_position[to_move] = 1;
    }
    for(i = 0; i < trains; ++ i){
        printf("%04d ", train_id[in_position_ids[i]]);
    }
    printf("\n%d\n", pushes);
    return 0;
}

/*
【样例输入】

10
shijiazhuang 280
xingtai 390
xinxiang 610
zhengzhou 689
wuchang 1221
chibi 1339
yueyang 1434
changsha 1559
shaoguan 2057
guangzhou 2273
12
0039 guangzhou
5217 xingtai
0262 yueyang
7205 wuchang
3211 guangzhou
4893 shijiazhuang
2283 shaoguan
0890 guangzhou
8729 wuchang
6839 shijiazhuang
2122 changsha
3280 wuchang
【样例输出】
0039 3211 0890 2283 2122 0262 7205 8729 3280 5217 4893 6839
45
 */