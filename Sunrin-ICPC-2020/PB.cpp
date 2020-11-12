#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

ll n, t, x, y;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> t;
    ll lst = 0, dir = 0;
    for(int i=1; i<=n; i++){
        ll now; string s;
        cin >> now >> s;
        x += dx[dir] * (now - lst);
        y += dy[dir] * (now - lst);
        if(s == "left") dir = (dir + 3) % 4;
        else dir = (dir + 1) % 4;
        lst = now;
    }
    x += dx[dir] * (t - lst);
    y += dy[dir] * (t - lst);
    cout << x << " " << y;
}