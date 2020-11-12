#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef pair<int, int> p;

int n, m;
vector<p> v;
int dp[1010][1010];

int f(int pos, int last){
    int &res = dp[pos][last];
    if(res != -1) return res;
    if(pos == m) return res = n - last;
    
    if(v[pos].x <= last) return res = f(pos+1, last);
    return res = min(f(pos+1, last), max(v[pos].x - last - 1, f(pos+1, v[pos].y)));
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m; v.resize(m);
    for(int i=0; i<m; i++) cin >> v[i].x >> v[i].y;
    sort(v.begin(), v.end());
    memset(dp, -1, sizeof dp);
    cout << f(0, 0);
}