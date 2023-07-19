#include <bits/stdc++.h>
using namespace std;

int N, M;
double D[55];
vector<int> G[55];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M; D[1] = 100;
    for(int i=1,s,e; i<=M; i++) cin >> s >> e, G[s].push_back(e);
    for(int i=1; i<=N; i++){
        if(G[i].empty()) continue;
        double nxt = D[i] / G[i].size();
        for(auto j : G[i]) D[j] += nxt;
        D[i] = 0;
    }
    cout << fixed << setprecision(20) << *max_element(D+1, D+N+1);
}