#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p;

int tree[505050];
void update(int x, int v){
    for(x++; x<505050; x+=x&-x) tree[x] += v;
}
int query(int x){
    int ret = 0;
    for(x++; x; x-=x&-x) ret += tree[x];
    return ret;
}
int query(int l, int r){ return query(r) - query(l-1); }

int n; p inp[505050];
vector<int> v;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n; for(int i=1; i<=n; i++) cin >> inp[i].x >> inp[i].y;
    sort(inp+1, inp+n+1, greater<>());
    for(int i=1; i<=n; i++) v.push_back(inp[i].y);
    
    int ans = 0;
    for(auto i : v){
        int l = 1, r = i-1;
        if(!query(r)){ ans++; update(1, 1); continue; }
        while(l < r){
            ll m = l + r + 1 >> 1;
            if(query(m, r)) l = m;
            else r = m - 1;
        }
        update(l, -1); update(l+1, 1);
    }
    cout << ans;
}