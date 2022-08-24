#include <bits/stdc++.h>
using namespace std;

int N, A[303030], B[303030], P[303030], L[303030], R[303030], Mn[303030], Mx[303030];
int Find(int v){ return v == P[v] ? v : P[v] = Find(P[v]); }
bool Merge(int u, int v){
    u = Find(u); v = Find(v);
    if(u == v) return false;
    P[u] = v;
    L[v] = min(L[v], L[u]);
    R[v] = max(R[v], R[u]);
    Mn[v] = min(Mn[v], Mn[u]);
    Mx[v] = max(Mx[v], Mx[u]);
    return true;
}

bool Check(int a, int b){
    return Mx[Find(a)] + 1 == Mn[Find(b)] || Mx[Find(b)] + 1 == Mn[Find(a)];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=1; i<=N; i++) cin >> A[i];
    for(int i=1; i<=N; i++) B[A[i]] = i;
    for(int i=1; i<=N; i++) P[i] = L[i] = R[i] = i;
    for(int i=1; i<=N; i++) Mn[i] = Mx[i] = A[i];

    queue<pair<int,int>> Q;
    for(int i=2; i<=N; i++) if(Check(i-1, i)) Q.emplace(i-1, i);
    while(!Q.empty()){
        auto [p1,p2] = Q.front(); Q.pop();
        Merge(p1, p2);
        int p = Find(p1), l = L[p], r = R[p];
        if(l > 1 && Check(p, l-1)) Q.emplace(l-1, p);
        if(r < N && Check(p, r+1)) Q.emplace(p, r+1);
    }
    
    if(L[Find(1)] == 1 && R[Find(1)] == N) cout << "YES\n";
    else cout << "NO\n";
}