#include <bits/stdc++.h>
using namespace std;

namespace SCC{
    vector<int> G[202020], R[202020], dfn;
    int chk[202020], deg[202020], pv;
    void addEdge(int s, int e){
        G[s].push_back(e);
        R[e].push_back(s);
    }
    void DFS1(int v){
        chk[v] = 1;
        for(auto i : G[v]) if(!chk[i]) DFS1(i);
        dfn.push_back(v);
    }
    void DFS2(int v, int color){
        chk[v] = color;
        for(auto i : R[v]) if(!chk[i]) DFS2(i, color);
    }
    int Run(int N){
        for(int i=1; i<=N; i++) if(!chk[i]) DFS1(i);
        reverse(dfn.begin(), dfn.end());
        fill(chk+1, chk+N+1, 0);
        for(auto i : dfn) if(!chk[i]) DFS2(i, ++pv);

        for(int i=1; i<=N; i++){
            for(auto j : G[i]){
                if(chk[i] != chk[j]) deg[chk[j]]++;
            }
        }

        int ret = 0;
        for(int i=1; i<=pv; i++) if(!deg[i]) ret++;
        return ret;
    }
}

int N, M, T;
set<int> st;

int getID(int v){ return SCC::chk[v]; }
int getDeg(int v){ return SCC::deg[getID(v)]; }

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M;
    for(int i=1; i<=M; i++){
        int u, v; cin >> u >> v;
        SCC::addEdge(u, v);
    }
    int need = SCC::Run(N);

    cin >> T;
    for(int i=1; i<=T; i++){
        int now; cin >> now;
        if(getDeg(now) == 0) st.insert(getID(now));
    }
    if(st.size() == need) cout << need;
    else cout << -1;
}