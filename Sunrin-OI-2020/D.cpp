#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p;
const ll inf = 1e18;

int n, m;
vector<p> g[202020];

ll dst[202020];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        ll s, e, x, y; cin >> s >> e >> x >> y;
        g[s << 1].emplace_back(e << 1, x);
        g[e << 1].emplace_back(s << 1, x);
        g[s << 1 | 1].emplace_back(e << 1 | 1, x);
        g[e << 1 | 1].emplace_back(s << 1 | 1, x);
        g[s << 1].emplace_back(e << 1 | 1, inf+x-y);
        g[e << 1].emplace_back(s << 1 | 1, inf+x-y);
    }
    
    memset(dst, 0x3f, sizeof dst);
    priority_queue<p> pq; pq.emplace(0, 2); dst[2] = 0;
    while(pq.size()){
        ll now = pq.top().y, cst = -pq.top().x; pq.pop();
        if(cst > dst[now]) continue;
        for(auto i : g[now]){
            if(dst[i.x] > cst + i.y){
                dst[i.x] = cst + i.y;
                pq.emplace(-dst[i.x], i.x);
            }
        }
    }
    for(int i=2; i<=n; i++) cout << dst[i << 1 | 1]-inf << "\n";
}