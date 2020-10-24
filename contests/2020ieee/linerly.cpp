#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
struct point {
    double x;
    double y;
    point() {}
    point(double x, double y) : x(x), y(y) {}
    bool operator<(const point &that) const {
        if (x != that.x) return x < that.x;
        return y < that.y;
    }

    bool operator==(const point &that) const {
        return x == that.x && y == that.y;
    }

};
#define endl '\n'
#define MAXN 100020
#define EPSILON 0.000001

bool cmp(point x, point y) {
    return x.x < y.x || (x.x == y.x && x.y < y.y);//x从小到大排序，如果x相同则y从小到大排序
}
int Cross(point x, point y, point z) {
    double x1 = x.x - y.x;
    double y1 = x.y - y.y;
    double x2 = z.x - y.x;
    double y2 = z.y - y.y;
    if ((x1 * y2 - x2 * y1) <= 0) return 0;//如果不希望在凸包的边上有输入点。把<=改成<
    return 1;
}
vector<point> andrew(vector<point> &p) {
    vector<point> ch;
    int n = p.size();
    sort(p.begin(), p.end(), cmp);
    int m = 0;
    int i;
    for (i = 0; i < n; i++)//从左到右扫描
    {
        while (m > 1 && !Cross(ch[m - 1], ch[m - 2], p[i])) m--;
        ch.push_back(p[i]);
        m++;
    }
    int k = m;
    for (i = n - 2; i >= 0; i--)//从右到左扫描
    {
        while (m > k && !Cross(ch[m - 1], ch[m - 2], p[i])) m--;
        ch.push_back(p[i]);
        m++;
    }
    return ch;
}

//判断点在线段上
bool IsPointOnLine(double px0, double py0, double px1, double py1, double px2, double py2) {
    bool flag = false;
    double d1 = (px1 - px0) * (py2 - py0) - (px2 - px0) * (py1 - py0);
    if ((abs(d1) < EPSILON) && ((px0 - px1) * (px0 - px2) <= 0) && ((py0 - py1) * (py0 - py2) <= 0)) {
        flag = true;
    }
    return flag;
}

//判断两线段相交
bool IsIntersect(double px1, double py1, double px2, double py2, double px3, double py3, double px4, double py4) {
    bool flag = false;
    double d = (px2 - px1) * (py4 - py3) - (py2 - py1) * (px4 - px3);
    if (d != 0) {
        double r = ((py1 - py3) * (px4 - px3) - (px1 - px3) * (py4 - py3) + 1e-11) / d ;
        double s = ((py1 - py3) * (px2 - px1) - (px1 - px3) * (py2 - py1) + 1e-11) / d;
        if ((r >= 0) && (r <= 1) && (s >= 0) && (s <= 1)) {
            flag = true;
        }
    }
    return flag;
}

//判断点在多边形内
bool pip(point &po, const vector<point> &POL) {
    bool isInside = false;
    int count = 0;

    double minX = 200;
    for (auto &p : POL) {
        minX = std::min(minX, p.x);
    }

    double px = po.x;
    double py = po.y;
    double linePoint1x = po.x;
    double linePoint1y = po.y;
    double linePoint2x = minX - 10;
    double linePoint2y = po.y;

    //遍历每一条边
    for (int i = 0; i < POL.size() - 1; i++) {
        double cx1 = POL[i].x;
        double cy1 = POL[i].y;
        double cx2 = POL[i + 1].x;
        double cy2 = POL[i + 1].y;
        if (IsPointOnLine(px, py, cx1, cy1, cx2, cy2)) {
            return true;
        }
        if (fabs(cy2 - cy1) < EPSILON)
        {
            continue;
        }
        if (IsPointOnLine(cx1, cy1, linePoint1x, linePoint1y, linePoint2x, linePoint2y)) {
            if (cy1 > cy2){
                count++;
            }
        } else if (IsPointOnLine(cx2, cy2, linePoint1x, linePoint1y, linePoint2x, linePoint2y)) {
            if (cy2 > cy1){
                count++;
            }
        } else if (IsIntersect(cx1, cy1, cx2, cy2, linePoint1x, linePoint1y, linePoint2x, linePoint2y)){
            count++;
        }
    }

    if (count % 2 == 1) {
        isInside = true;
    }
    return isInside;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    double a, b;
    int c;
    while (t--) {
        int n;
        vector<point> plus;
        vector<point> minus;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a >> b >> c;
            if (c == 1) {
                plus.emplace_back(a, b);
            } else {
                minus.emplace_back(a, b);
            }
        }
        auto plus_tb = andrew(plus);

        int flag = 0;
        point mi(200,200), ma(-200,-200);
        double xl = (plus_tb[0].y - plus_tb[1].y) / (plus_tb[0].x - plus_tb[1].x + 1e-11);
        for(int i = 2; i < plus_tb.size(); ++ i){
            mi = min(mi, plus_tb[i]);
            ma = max(ma, plus_tb[i]);
            if(xl - (plus_tb[0].y - plus_tb[1].y) / (plus_tb[0].x - plus_tb[1].x + 1e-11) > EPSILON){
                flag = 1;
                break;
            }
        }

        if(flag == 0){
            flag = 0;
            int last = 0;
            for(auto &p: minus){
                if((p.y - mi.y)*(ma.x - mi.x) - (ma.y - mi.y)*(p.x - mi.x) > 0){
                    if(last == 0){
                        last = 1;
                        continue;
                    } else if(last == -1){
                        flag = 1;
                        break;
                    }
                } else if((p.y - mi.y)*(ma.x - mi.x) - (ma.y - mi.y)*(p.x - mi.x) < 0) {
                    if(last == 0){
                        last = -1;
                        continue;
                    } else if(last == 1){
                        flag = 1;
                        break;
                    }
                }
            }
        } else {
            flag = 0;
            for(auto& p:minus){
                if(pip(p, plus_tb)){
                    flag = 1;
                    break;
                }
            }
        }

        if(flag == 0){
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}