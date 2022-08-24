#include <bits/stdc++.h>
using namespace std;
constexpr int K = 60;
constexpr int MAX_N = 50'000;
constexpr int MAX_M = 50'000;
constexpr int MAX_Q = 50'000;
constexpr int MAX_W = 50'000;

int N, M, Q, D[3][MAX_N+10];
vector<pair<int,int>> G[MAX_N+10];
vector<int> Large[MAX_N+10];

void InitLarge(int s){
    memset(D, 0x3f, sizeof D);
    D[0][s] = 0;
    for(int i=0; i<2; i++){
        for(int j=1; j<=N; j++) for(auto [k,w] : G[j]) D[i+1][k] = min(D[i+1][k], D[i][j] + w);
    }
    Large[s] = vector<int>(D[0], D[0]+N+1);
    for(int i=1; i<=2; i++) for(int j=1; j<=N; j++) Large[s][j] = min(Large[s][j], D[i][j]);
}

int SolveSmall(int u, int v){
    int res = 0x3f3f3f3f;
    for(const auto [i,x] : G[u]){
        for(const auto [j,y] : G[v]){
            if(i == v) res = min(res, x);
            if(j == u) res = min(res, y);
            if(i == j) res = min(res, x + y);
            auto it = lower_bound(G[i].begin(), G[i].end(), make_pair(j, -1));
            if(it != G[i].end() && it->first == j) res = min(res, x + y + it->second);
        }
    }
    return res < 1e9 ? res : -1;
}

int SolveLarge(int u, int v){
    int res = 0x3f3f3f3f;
    for(const auto [i,w] : G[v]) res = min(res, Large[u][i] + w);
    return res < 1e9 ? res : -1;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M >> Q;
    for(int i=0,s,e,w; i<M; i++){
        cin >> s >> e >> w; if(s > e) swap(s, e);
        G[s].emplace_back(e, w);
        G[e].emplace_back(s, w);
    }
    for(int i=1; i<=N; i++) sort(G[i].begin(), G[i].end());
    for(int i=1; i<=N; i++) if(G[i].size() > K) InitLarge(i);

    map<pair<int,int>, int> cache;
    for(int i=1; i<=Q; i++){
        int u, v; cin >> u >> v;
        if(make_pair(G[u].size(),u) < make_pair(G[v].size(),v)) swap(u, v);
        if(auto it=cache.find(make_pair(u, v)); it != cache.end()){
            cout << it->second << "\n"; continue;
        }
        int res = G[u].size() <= K ? SolveSmall(u, v) : SolveLarge(u, v);
        cache[{u,v}] = res;
        cout << res << "\n";
    }
}
