#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, M, Q, A[5050], W[5050][5050], X[5050];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M >> Q;
    for(int i=1; i<=M; i++){
        int cnt; cin >> cnt;
        vector<int> idx(cnt);
        for(auto &j : idx) cin >> j;
        idx.push_back(N+1);
        for(int j=0; j<idx.size(); j++) cin >> W[i][idx[j]];
    }
    for(int i=1; i<=M; i++){
        ll t; cin >> t;
        for(int j=1; j<=N+1; j++) A[j] += t * W[i][j];
    }
    ll t; cin >> t; A[N+1] += t;

    for(int q=1; q<=Q; q++){
        for(int i=1; i<=N; i++) cin >> X[i]; X[N+1] = 1;
        ll res = 0;
        for(int i=1; i<=N+1; i++) res += A[i] * X[i];
        cout << res << "\n";
    }
}