#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef pair<int, int> p;

int n, m, l, k;
p v[111];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> l >> k;
    for(int i=1; i<=k; i++) cin >> v[i].x >> v[i].y;
    
    int mx = 0;
    for(int i=1; i<=k; i++) for(int j=1; j<=k; j++){
            int ret = 0;
            int x = v[i].x, xx = v[i].x + l;
            int y = v[j].y, yy = v[j].y + l;
            for(int s=1; s<=k; s++) if(x <= v[s].x && v[s].x <= xx && y <= v[s].y && v[s].y <= yy) ret++;
            mx = max(mx, ret);
        }
    cout << k-mx;
}