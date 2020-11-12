#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef pair<double, double> p;

int ccw(const p &a, const p &b, const p &c){
    double dx1 = b.x - a.x, dy1 = b.y - a.y;
    double dx2 = c.x - b.x, dy2 = c.y - b.y;
    double res = dx1*dy2 - dx2*dy1;
    return (res > 0) - (res < 0);
}

int cross_chk(p a, p b, p c, p d){
    int ab = ccw(a, b, c) * ccw(a, b, d);
    int cd = ccw(c, d, a) * ccw(c, d, b);
    if(!ab && !cd){
        if(a > b) swap(a, b);
        if(c > d) swap(c, d);
        return c <= b && a <= d;
    }
    return ab <= 0 && cd <= 0;
}

int n;
p pt[101010];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    for(int i=1; i<=n; i++) pt[i].x = i, cin >> pt[i].y;
    double k; cin >> k;
    
    for(int i=1; i<=n; i++){
        p t1 = p(i-1, k*(i-1)), t2 = p(i, k*i);
        if(!cross_chk(pt[i-1], pt[i], t1, t2)) continue;
        if(i > 1 || pt[i] == t2){
            cout << "T"; return 0;
        }
    }
    cout << "F";
}