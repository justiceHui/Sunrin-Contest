#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, T, A[303030], B[303030], C[303030], D[303030], E[303030];

ll Crosswalk(ll ti, ll idx){
    ti = max(ti, C[idx]);
    ll x = (ti - C[idx]) / A[idx];
    if(C[idx] + A[idx]*x <= ti && ti + D[idx] <= C[idx] + A[idx]*x + B[idx]) return ti + D[idx];
    else return C[idx] + A[idx] * (x + 1) + D[idx];
}

ll GetTime(ll ti){
    ti += E[0];
    for(int i=1; i<=N; i++) ti = Crosswalk(ti, i) + E[i];
    return ti;
}

void Solve(){
    cin >> N >> T;
    for(int i=1; i<=N; i++) cin >> A[i] >> B[i] >> C[i] >> D[i];
    for(int i=0; i<=N; i++) cin >> E[i];
    ll l = 0, r = T;
    while(l < r){
        ll m = (l + r) / 2, t = GetTime(m);
        if(t == T){ cout << "YES\n"; return; }
        if(GetTime(m) >= T) r = m;
        else l = m + 1;
    }
    cout << "NO\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int TC; cin >> TC;
    for(int tc=1; tc<=TC; tc++) Solve();
}