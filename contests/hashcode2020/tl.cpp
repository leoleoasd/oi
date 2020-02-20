#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define MAXB 100010
#define MAXL 30010
#define endl '\n'

int books_score[MAXB] = {0};
int lib_has_book[MAXL][MAXB] = {0};
int lib_book_scaned[MAXL][MAXB] = {0};
int book_scanned[MAXB] = {0};
int lib_books[MAXL] = {0};
int lib_signup[MAXL] = {0};
int lib_books_oneday[MAXL] = {0};
int lib_signed[MAXL] = {0};
int lib_can_sign[MAXL] = {0};

struct book{
    int id = 0;
    int count = 0;
    int score = 0;

    bool operator<(const book b) const {
        if(this->score != b.score){
            return this->score < b.score;
        }
        return this->count > b.count;
    }
};

int main(){
    int books, libs, days;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>books>>libs>>days;

    for(int i = 0; i < books; ++ i){
        cin>>books_score[i];
    }

    for(int i = 0; i < libs; ++ i){
        cin>>lib_books[i]>>lib_signup[i]>>lib_books_oneday[i];
        for(int j = 0; j < lib_books[i]; ++ j){
            cin>>lib_has_book[i][j];
        }
    }
    int score = 0;
    int count_libs = 0;
    cout<<96<<endl;
    while(days > 0){
        bool flag = 0;
        for(int i = 0; i < libs; ++ i){
            if(lib_signed[i]){
                lib_can_sign[i] = 0;
                continue;
            }
            lib_can_sign[i] = lib_signup[i] < days;
            if(lib_signup[i] < days){
                flag = 1;
            }
        }
        if(!flag) break; // 没有可sign的了

        int maxp = -1;
        int lib = -1;

        for(int i = 0; i < libs; ++ i){
            // 权重是从现在到最后能拿到的总分数
            if(!lib_can_sign[i]){
                continue;
            }
            int books = ( days - lib_signup[i]) * (lib_books_oneday[i]);
            int p = 0;
            for(int j = 0; j < lib_books[i] && books > 0; ++ j){
                if(!book_scanned[lib_has_book[i][j]]){
                    books--;
                    p += books_score[lib_has_book[i][j]];
                }
            }
            if(p > maxp){
                maxp = p;
                lib = i;
            }
        }

        lib_signed[lib] = 1;

        int books_count = (days - lib_signup[lib]) * lib_books_oneday[lib];
        days -= lib_signup[lib];
        int real_books = 0;
        vector<int> boo;

        book bo[MAXB];
        int revid[MAXB] = {-1};
        memset(revid,0xff,sizeof(revid));
        for(int i = 0; i < lib_books[lib]; ++ i){
            bo[i].id = lib_has_book[lib][i];
            bo[i].score = books_score[bo[i].id];
            revid[lib_has_book[lib][i]] = i;
        }
        for(int i = 0; i < libs; ++ i){
            for(int j = 0; j < lib_books[i]; ++ j){
                if(revid[lib_has_book[i][j]] >= 0){
                    bo[revid[lib_has_book[i][j]]].count ++;
                }
            }
        }
        priority_queue<book> que;
        for(int i = 0; i < lib_books[lib]; ++ i){
            que.push(bo[i]);
        }

        for(;books_count > 0 and !que.empty();){
            book now = que.top();
            que.pop();
            if(!book_scanned[now.id]){
                books++;
                books_count--;
                book_scanned[now.id] = 1;
                score += now.score;
                real_books ++;
                boo.push_back(now.id);
            }
        }

        /*
        for(int j = 0; j < lib_books[lib] && books_count > 0; ++ j){
            if(!book_scanned[lib_has_book[lib][j]]){
                book_scanned[lib_has_book[lib][j]] = 1;
                books_count --;
                score += 1;
                real_books++;
                boo.push_back(lib_has_book[lib][j]);
            }
        }
         */

        //cout<<days<<endl;
        count_libs++;
        cout<<lib<<" "<<real_books<<endl;
        for(auto i: boo){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    cout<<score<<endl;
    cout<<count_libs<<endl;
    // 6,148,500
    return 0;
}
