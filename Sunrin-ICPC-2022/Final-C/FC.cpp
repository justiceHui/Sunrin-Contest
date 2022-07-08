#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, S[202020], E[202020], C[202020], P[202020];
ll A[202020], B[202020], Group[202020], Vertex[202020];
vector<pair<int,int>> G[202020];

int Find(int v){ return v == P[v] ? v : P[v] = Find(P[v]); }
bool Merge(int u, int v){ return Find(u) != Find(v) && (P[P[u]] = P[v], true); }

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=1; i<N; i++){
        cin >> S[i] >> E[i] >> C[i];
        G[S[i]].emplace_back(E[i], i);
        G[E[i]].emplace_back(S[i], i);
    }
    for(int i=1; i<=N; i++) cin >> A[i];
    for(int i=1; i<=N; i++) cin >> B[i];

    iota(P+1, P+N+1, 1);
    for(int i=1; i<=N; i++) sort(G[i].begin(), G[i].end(), [](auto a, auto b){ return C[a.second] < C[b.second]; });
    for(int i=1; i<=N; i++){
        for(int j=1; j<G[i].size(); j++) if(C[G[i][j-1].second] == C[G[i][j].second]) Merge(G[i][j-1].second, G[i][j].second);
    }
    
    for(int i=1; i<=N; i++) sort(G[i].begin(), G[i].end(), [](auto a, auto b){ return Find(a.second) < Find(b.second); });
    for(int i=1; i<=N; i++){
        for(int j=0; j<G[i].size(); j++) if(j == 0 || Find(G[i][j-1].second) != Find(G[i][j].second)) Group[Find(G[i][j].second)] += A[i];
    }
    for(int i=1; i<=N; i++){
        for(int j=0; j<G[i].size(); j++) if(j == 0 || Find(G[i][j-1].second) != Find(G[i][j].second)) Vertex[i] += Group[Find(G[i][j].second)];
    }

    ll mn = 0, mx = 0;
    sort(Vertex+1, Vertex+N+1);
    sort(B+1, B+N+1);
    for(int i=1; i<=N; i++) mx += Vertex[i] * B[i];
    reverse(B+1, B+N+1);
    for(int i=1; i<=N; i++) mn += Vertex[i] * B[i];

    cout << mn << "\n" << mx << "\n";
}