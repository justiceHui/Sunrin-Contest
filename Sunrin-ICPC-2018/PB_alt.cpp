#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> p;

char str[1001];
int cnt[1001] = {0};
vector<int> adj[1001];
int n;
int path[1001][1001];
int ans = 0;

void search(int n){
    path[n][n] = 1;
    int now = n;
    cnt[n]++;
    adj[n].push_back(n);
    if(str[n] == 'E') now++;
    else now--;
    while(path[n][now] == 0){
        path[n][now] = 1;
        adj[now].push_back(n);
        cnt[now]++;
        if(str[now] == 'E') now++;
        else now--;
    }
}

bool chk(){
    for(int i=0; i<n; i++) if(cnt[i] > 0) return false;
    return true;
}

int main(){
    scanf("%d", &n);
    scanf("%s", str);
    for(int i=0; i<n; i++) search(i);
    
    while(!chk()){
        int v = 0;
        for(int i=0; i<n; i++) if(cnt[v] < cnt[i] && cnt[i]>0) v = i;
        cnt[v] = 0;
        for(int i=0; i<adj[v].size(); i++) cnt[adj[v][i]] = 0;
        ans++;
    }
    printf("%d", ans);
}