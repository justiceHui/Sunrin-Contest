#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N, rt;
vector<int> G[202020];
ll sz[202020], cnt[202020];

void DFS(int v){
    sz[v] = 1;
    for(auto i : G[v]){
        DFS(i);
        cnt[v] += sz[v] * sz[i] * 2;
        sz[v] += sz[i];
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=1; i<=N; i++){
        int p; cin >> p;
        if(p != 0) G[p].push_back(i);
        else rt = i;
    }
    fill(cnt+1, cnt+N+1, 1);
    DFS(rt);

    ll odd = 0, even = 0;
    ll flag = 1;
    for(int i=1; i<=N; i++){
        ll a = (cnt[i] + 1) / 2;
        ll b = cnt[i] / 2;
        if(flag) odd += a * i, even += b * i;
        else odd += b * i, even += a * i;
        if(cnt[i] % 2 == 1) flag ^= 1;
    }
    cout << even << " " << odd;
}