#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef pair<int, int> p;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<p> v(n);
    for(int i=0; i<n; i++) cin >> v[i].x >> v[i].y;
    int ans = 0;
    
    for(int i=0; i<n; i++){
        int j = (i + 1) % n;
        ans += abs(v[j].x - v[i].x);
        ans += abs(v[j].y - v[i].y);
    }
    cout << ans;
}