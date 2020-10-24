#include <cstring>
#include <string>
#include <iostream>

using namespace std;

const int CHAR = 26;
struct SAM_Node {
    SAM_Node *link, *next[CHAR];
    int len;
    long long cnt;
    void clear() {
        link = 0;
        memset(next, 0, sizeof(next));
        cnt = 0;
    }
};
SAM_Node *root;
SAM_Node *newnode(int len) {
    SAM_Node *cur = new SAM_Node;
    cur->clear();
    cur->len = len;
    return cur;
}

void SAM_init() {
    root = newnode(0);
}

SAM_Node *extend(SAM_Node *last, int x) {
    SAM_Node *p = last;
    SAM_Node *np = newnode(p->len + 1);
    while (p && !p->next[x])
        p->next[x] = np, p = p->link;
    if (!p)np->link = root;
    else {
        SAM_Node *q = p->next[x];
        if (q->len == p->len + 1)np->link = q;
        else {
            SAM_Node *nq = newnode(p->len + 1);
            memcpy(nq->next, q->next, sizeof(q->next));
            nq->link = q->link;
            q->link = np->link = nq;
            while (p && p->next[x] == q)
                p->next[x] = nq, p = p->link;
        }
    }
    return np;
}

void dfs(SAM_Node* now, string nn){
    cout<<nn<<endl;
    for(int i = 0; i < CHAR; ++ i){
        if (now->next[i]) {
            dfs(now->next[i], nn + char('a'+i));
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string father;
    string mother;
    string baby_fat;
    string baby_mom;
    SAM_init();
    cin>>father>>mother;
    SAM_Node *now = root;
    SAM_Node *ma_root = root;
    for (char i:mother) {
        now = extend(now, i - 'a');
    }
    now = ma_root;
    while(now){
        int flag = 0;
        for(int i = CHAR-1; i >= 0; -- i){
            if (now->next[i]){
                now = now->next[i];
                baby_mom += char(i+'a');
                flag = 1;
                break;
            }
        }
        if (flag) continue;
        break;
    }
    root = newnode(0);
    SAM_Node *fa_root = root;
    now = root;
    for (char i:father) {
        now = extend(now, i - 'a');
    }
    now = fa_root;
    while(now) {
        int flag = 0;
        for(int i = CHAR-1; i >= 0; -- i){
            if (now != fa_root){
                if (i + 'a' < baby_mom[0]) {
                    break;
                }
            }
            if (now->next[i]){
                now = now->next[i];
                baby_fat += char(i+'a');
                flag = 1;
                break;
            }
        }
        if (flag == 1) continue;
        break;
    }
    cout<<baby_fat + baby_mom<<endl;
}