#include <bits/stdc++.h>
using namespace std;

int N, M, K, Q, A[202020], R[202020];
map<pair<int,int>, int> T;
vector<tuple<int,int,int>> G[202020];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M >> K >> Q;
    for(int i=1,u,v; i<=M; i++) cin >> u >> v, T[{u,v}] = 0;
    for(int i=1; i<=K; i++) cin >> A[i];
    for(int i=1; i<=Q; i++){
        int t, u, v; cin >> t >> u >> v;
        auto it = T.find({u,v});
        if(it == T.end()) T.emplace_hint(it, make_pair(u,v), t);
        else{
            int st = it->second, ed = t - 1;
            G[u].emplace_back(v, st, ed);
            G[v].emplace_back(u, st, ed);
            T.erase(it);
        }
    }
    for(auto [e,st] : T){
        auto [u,v] = e; int ed = 400'000;
        G[u].emplace_back(v, st, ed);
        G[v].emplace_back(u, st, ed);
    }

    memset(R, 0x3f, sizeof R);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> P;
    for(int i=1; i<=K; i++) P.emplace(R[A[i]]=0, A[i]);
    while(!P.empty()){
        auto [c,v] = P.top(); P.pop();
        if(c != R[v]) continue;
        for(auto [i,s,e] : G[v]) if(c <= e && R[i] > max(s,c)+1) P.emplace(R[i]=max(s,c)+1, i);
    }
    for(int i=1; i<=N; i++) cout << (R[i] < 0x3f3f3f3f ? R[i] : -1) << " ";
}