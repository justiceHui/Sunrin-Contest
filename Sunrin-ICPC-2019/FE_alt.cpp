#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Seg{
    ll tree[404040];
    ll tmp[404040];
    
    void push(int node, int s, int e){
        if(!tmp[node]) return;
        tree[node] += (e-s+1) * tmp[node];
        if(s ^ e){
            tmp[node*2] += tmp[node];
            tmp[node*2+1] += tmp[node];
        }
        tmp[node] = 0;
    }
    
    void update(int node, int s, int e, int l, int r, int v){
        push(node, s, e);
        if(r < s || e < l) return;
        if(l <= s && e <= r){
            tree[node] += (e-s+1) * v;
            if(s ^ e){
                tmp[node*2] += v;
                tmp[node*2+1] += v;
            }
            return;
        }
        int m = s + e >> 1;
        update(node*2, s, m, l, r, v);
        update(node*2+1, m+1, e, l, r, v);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
    
    ll query(int node, int s, int e, int l, int r){
        push(node, s, e);
        if(r < s || e < l) return 0;
        if(l <= s && e <= r) return tree[node];
        int m = s + e >> 1;
        return query(node*2, s, m, l, r) + query(node*2+1, m+1, e, l, r);
    }
} seg1, seg2;

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
            seg1.update(1, 1, n, a, b, 1);
            seg2.update(1, 1, n, a, b, a-1);
        }else{
            int x; cin >> x;
            ll a = arr[x];
            ll b = seg1.query(1, 1, n, x, x) * x;
            ll c = seg2.query(1, 1, n, x, x) * -1;
            cout << (a+b+c) << "\n";
        }
    }
}