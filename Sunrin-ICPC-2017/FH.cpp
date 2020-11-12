#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> p;
typedef pair<p, int> pi; //<depth, dist, now

vector<p> G[50010];

pi dfs(int now, int prv, int depth){
    pi ret = make_pair( make_pair(depth, 0), now );
    for(int i=0; i<G[now].size(); i++){
        int next = G[now][i].first;
        int dist = G[now][i].second;
        if(next == prv) continue;
        pi tmp = dfs(next, now, depth+1);
        tmp.first.second -= dist;
        ret = max(ret, tmp);
    }
    return ret;
}

int main(){
    int n, t; scanf("%d %d", &n, &t);
    for(int i=0; i<n-1; i++){
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        G[a].push_back( make_pair(b, c) );
        G[b].push_back( make_pair(a, c) );
    }
    int farNode = dfs(1, 0, 0).second;
    int ans = -dfs(farNode, 0, 0).first.second;
    printf("%d", (ans+t-1)/t);
}