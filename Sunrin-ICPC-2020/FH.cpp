#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef pair<int, int> p;

int N, A[202020];
vector<int> G[202020];

int sz[202020];
int get_sz(int v, int b = -1){
    sz[v] = 1;
    for(auto i : G[v]) if(i != b) sz[v] += get_sz(i, v);
    return sz[v];
}
p get_edge(int v, int total, int b = -1){
    int now = abs(total - sz[v]*2);
    p ret(b, v);
    for(auto i : G[v]){
        if(i == b) continue;
        p t = get_edge(i, total, v);
        if(abs(total - sz[t.y]*2) < now){
            now = abs(total - sz[t.y]*2);
            ret = t;
        }
    }
    return ret;
}
void get_list(int v, int b, vector<int> &l){
    l.push_back(v);
    for(auto i : G[v]) if(i != b) get_list(i, v, l);
}
void color(int v, int value, int b = -1){
    A[v] ^= value;
    for(auto i : G[v]) if(i != b) color(i, value, v);
}

void Go(int v, int base, int d = 28){
    if(get_sz(v) == 1){
        if(A[v] == -1) A[v] = base;
        return;
    }
    p edge = get_edge(v, sz[v]);
    int s = edge.x, e = edge.y;
    G[s].erase(find(G[s].begin(), G[s].end(), e));
    G[e].erase(find(G[e].begin(), G[e].end(), s));

    vector<int> li; get_list(e, -1, li);
    Go(s, base, d-1);
    Go(e, base | (1 << d), d-1);

    int val = A[s] ^ A[e] ^ (1 << d);
    for(auto i : li) A[i] ^= val;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=1; i<N; i++){
        int s, e; cin >> s >> e;
        G[s].push_back(e);
        G[e].push_back(s);
    }
    memset(A, -1, sizeof A);
    Go(1, 0);
    for(int i=1; i<=N; i++) cout << A[i] << " ";
}