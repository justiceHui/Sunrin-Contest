#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef pair<int, int> p;
vector<p> v;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n; v.resize(n);
    for(int i=0; i<n; i++){
        double t; cin >> t;
        v[i].x = (int)t;
        v[i].y = 0;
        if(t - (int)t > 0.1) v[i].y = 1;
    }
    
    int ans = v[0].x;
    if(v[0].y == 1) ans++;
    for(int i=1; i<n; i++){
        if(v[i].y == 1 && ans == 0) ans++;
        ans += v[i].x;
    }
    cout << ans;
}