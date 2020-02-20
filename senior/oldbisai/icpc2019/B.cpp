// Orz teacherone
// Orz SJY
// Orz WYD
// Orz TYX
// Orz SZ
/**
 *                             _ooOoo_
 *                            o8888888o
 *                            88" . "88
 *                            (| -_- |)
 *                            O\  =  /O
 *                         ____/`---'\____
 *                       .'  \\|     |//  `.
 *                      /  \\|||  :  |||//  \
 *                     /  _||||| -:- |||||-  \
 *                     |   | \\\  -  /// |   |
 *                     | \_|  ''\---/''  |   |
 *                     \  .-\__  `-`  ___/-. /
 *                   ___`. .'  /--.--\  `. . __
 *                ."" '<  `.___\_<|>_/___.'  >'"".
 *               | | :  `- \`.;`\ _ /`;.`/ - ` : | |
 *               \  \ `-.   \_ __\ /__ _/   .-` /  /
 *          ======`-.____`-.___\_____/___.-`____.-'======
 *                             `=---='
 *          ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
 *                     佛祖保佑        永无BUG
 *            佛曰:
 *                   写字楼里写字间，写字间里程序员；
 *                   程序人员写程序，又拿程序换酒钱。
 *                   酒醒只在网上坐，酒醉还来网下眠；
 *                   酒醉酒醒日复日，网上网下年复年。
 *                   但愿老死电脑间，不愿鞠躬老板前；
 *                   奔驰宝马贵者趣，公交自行程序员。
 *                   别人笑我忒疯癫，我笑自己命太贱；
 *                   不见满街漂亮妹，哪个归得程序员？
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXN 1000001

int t,n,m;
unsigned short Ls[MAXN] = {0};
unsigned short Rs[MAXN] = {0};

inline int solve(){
    int ans = 0;
    bool flag = 0;
    for(int i = 0; i < n; ++ i){
        if(Ls[i] & 1){
            flag = !flag;
        }
        ans += flag;
        if(Rs[i] & 1){
            flag = !flag;
        }
    }
    return ans;
}
template <typename _tp> inline _tp read(_tp&x){
	char ch=getchar(),sgn=0;x=0;
	while(ch^'-'&&!isdigit(ch))ch=getchar();if(ch=='-')ch=getchar(),sgn=1;
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();if(sgn)x=-x;return x;
}
int main(){
    read(t);
    int a,b;
    for(int kk = 1; kk <= t; ++ kk){
        read(n);
        read(m);
        memset(Ls,0,2*n);
        memset(Ls,0,2*n);
        for(int i = 0; i < m; ++ i){
            read(a);
            read(b);
            Ls[a]++;
            Rs[b]++;
        }
        printf("Case #%d: %d\n",kk,solve());
    }
    return 0;
}