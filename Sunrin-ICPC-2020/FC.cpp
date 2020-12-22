#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
using namespace std;

typedef long long ll;

int N, K, base;
ll A[1 << 18], DP[1 << 19], Sum[1 << 19], mx;
int S[1 << 19], E[1 << 19];

int Log2(int x){
    int ret = 0;
    while(x > 1) x /= 2, ret++;
    return ret;
}

void DFS(int node, int s, int e){
    S[node] = s; E[node] = e;
    if(s == e) return;
    int m = (s + e) / 2;
    DFS(node*2, s, m);
    DFS(node*2+1, m+1, e);
}

int LCA(int u, int v){
    while(u != v) u /= 2, v /= 2;
    return u;
}

ll f(int l, int r){
    int lca = LCA(base+l, base+r);
    ll now = Sum[lca], nd;
    ll le = 0, ri = 0, pa = 0;

    nd = base+l;
    while(nd >= lca){
        if(E[nd*2] < l) now -= Sum[nd*2], le = max(le, DP[nd*2]);
        nd /= 2;
    }
    nd = base+r;
    while(nd >= lca){
        if(r < S[nd*2+1]) now -= Sum[nd*2+1], ri = max(ri, DP[nd*2+1]);
        nd /= 2;
    }
    nd = lca;
    ll acc = 0;
    while(nd > 1){
        pa = max(pa, DP[nd^1] + A[nd/2] + acc);
        acc += A[nd/2];
        nd /= 2;
    }

    if(min({le, ri, pa}) == le) now += ri + pa;
    else if(min({le, ri, pa}) == ri) now += le + pa;
    else now += le + ri;
    return now;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N; base = (N+1)/2-1; K = Log2(N+1);
    for(int i=1; i<=N; i++) cin >> A[i];
    for(int i=N; i>=1; i--) DP[i] = max(DP[i*2], DP[i*2+1]) + A[i];
    for(int i=N; i>=1; i--) Sum[i] = A[i] + Sum[i*2] + Sum[i*2+1];
    for(int i=1; i<=N; i++) mx = max(mx, A[i] + DP[i*2] + DP[i*2+1]);
    DFS(1, 1, base+1);

    for(int i=K; i<=base+1; i++) mx = max(mx, f(i-K+1, i));
    cout << mx;
}