#include <bits/stdc++.h>
#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define IDX(v, x) (lower_bound(all(v), x) - v.begin())
using namespace std;
using PII = pair<int, int>;

struct Tree{
    int n;
    vector<vector<int>> g;
    vector<PII> edges;
    vector<bool> onDiameter;
    PII diameter_vertex;
    int diameter_dist;
    bool empty(){ return n != 0; }
    void addEdge(int u, int v){
        edges.emplace_back(u, v);
    }
    void build(){
        if(edges.empty()){ n = 1; return; }
        vector<int> vertices;
        for(auto i : edges) vertices.push_back(i.x), vertices.push_back(i.y);
        compress(vertices);
        n = vertices.size();

        g.resize(n + 1);
        for(auto &i : edges){
            i.x = IDX(vertices, i.x) + 1;
            i.y = IDX(vertices, i.y) + 1;
            g[i.x].push_back(i.y);
            g[i.y].push_back(i.x);
        }

        getDiameter();
    }
    void getDiameter(){
        onDiameter.resize(n + 1);
        vector<int> prv(n + 1);
        function<PII(int,int,int)> dfs = [&](int v, int b, int d){
            PII ret(d, v); prv[v] = b;
            for(auto i : g[v]) if(i != b) ret = max(ret, dfs(i, v, d+1));
            return ret;
        };
        int u = dfs(1, -1, 0).y;
        auto res = dfs(u, -1, 0);
        diameter_vertex = {u, res.y};
        diameter_dist = res.x;
        for(int i=res.y; i!=-1; i=prv[i]) onDiameter[i] = true;
    }
    bool isBamboo(){
        if(n < 3) return false;
        int u = diameter_vertex.x, v = diameter_vertex.y;
        int dst = diameter_dist;
        if(dst >= 3 && __isBamboo(u, v)) return true;

        onDiameter[u] = false;
        if(dst-1 >= 3 && !g[u].empty() && __isBamboo(g[u][0], v)) return true;
        onDiameter[u] = true;

        onDiameter[v] = false;
        if(dst-1 >= 3 && !g[v].empty() && __isBamboo(u, g[v][0])) return true;
        onDiameter[v] = true;

        onDiameter[u] = onDiameter[v] = false;
        if(dst-2 >= 3 && !g[u].empty() && !g[v].empty() && __isBamboo(g[u][0], g[v][0])) return true;
        onDiameter[u] = onDiameter[v] = true;

        return false;
    }
    bool __isBamboo(int u, int v){
        int tot = 0;
        for(int i=1; i<=n; i++){
            if(!onDiameter[i]) continue;
            tot++;
            int degree = 0;
            for(auto j : g[i]) if(!onDiameter[j]) degree++, tot++;
            if(degree != 0 && degree != 2) return false;
        }
        return tot == n;
    }
} T[101010];

int UF[101010];
int Find(int v){ return v == UF[v] ? v : UF[v] = Find(UF[v]); }
bool Merge(int u, int v){
    u = Find(u); v = Find(v);
    if(u == v) return false;
    UF[u] = v; return true;
}

int N, M, S[202020], E[202020];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    iota(UF, UF+101010, 0);
    cin >> N >> M;
    for(int i=1; i<=M; i++){
        cin >> S[i] >> E[i];
        if(!Merge(S[i], E[i])){
            cout << "NIE"; return 0;
        }
    }

    for(int i=1; i<=M; i++) T[Find(S[i])].addEdge(S[i], E[i]);
    for(int i=1; i<=N; i++) if(Find(i) == i) T[i].build();
    for(int i=1; i<=N; i++){
        if(Find(i) == i && !T[i].isBamboo()){
            cout << "NIE"; return 0;
        }
    }
    cout << "TAK";
}