#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct BIT{
    ll tree[101010];
    void add(int x, ll v){ for(x++; x<101010; x+=x&-x) tree[x] += v; }
    void add(int s, int e, ll v){ add(s, v); add(e+1, -v); }
    ll get(int x){ ll ret = 0; for(x++; x; x-=x&-x) ret += tree[x]; return ret; }
} t1, t2;

ll arr[101010];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for(int i=1; i<=n; i++) cin >> arr[i];
    
    int q; cin >> q;
    while(q--){
        int op; cin >> op;
        if(op == 1){
            int a, b; cin >> a >> b;
            t1.add(a, b, 1);
            t2.add(a, b, a-1);
        }else{
            int x; cin >> x;
            ll res = arr[x] + t1.get(x) * x - t2.get(x);
            cout << res << "\n";
        }
    }
}