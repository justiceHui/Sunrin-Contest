#include <bits/stdc++.h>
using namespace std;

int N, G[333][333];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=1; i<N; i++){
        int u, v; cin >> u >> v;
        G[u][v] = G[v][u] = 1;
    }

    vector<pair<int, int>> Res;
    if(N <= 4){
        for(int i=1; i<=N; i++){
            for(int j=i+1; j<=N; j++){
                if(!G[i][j]) Res.emplace_back(i, j);
            }
        }
    }
    else{
        for(int i=2; i<=N; i++){
            if(!G[1][i]) Res.emplace_back(1, i);
        }
    }

    cout << Res.size() << "\n";
    cout << (N <= 4 ? 1 : 2) << "\n";
    for(auto i : Res) cout << i.first << " " << i.second << "\n";
}