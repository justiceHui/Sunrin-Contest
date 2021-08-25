#include <bits/stdc++.h>
using namespace std;

int N, Q, M, P[303030];
vector<int> G[303030];
vector<pair<int,int>> Edges;

void DFS(int v){
    for(auto i : G[v]){
        DFS(i);
        Edges.emplace_back(i, v);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> Q;
    for(int i=1; i<=N; i++) cin >> P[i];
    cout << N << " " << Q << "\n";

    cin >> M;
    for(int i=1; i<=M; i++){
        int v; cin >> v;
        cout << "2 " << v << "\n";
    }
    Q -= M;

    for(int i=1; i<=N; i++){
        if(i != P[i]) G[P[i]].push_back(i);
    }
    for(int i=1; i<=N; i++) if(i == P[i]) DFS(i);

    while(Q > Edges.size()) cout << "1 1 1\n", Q--;
    for(auto [u,v] : Edges){
        cout << "1 " << u << " " << v << "\n";
    }
}