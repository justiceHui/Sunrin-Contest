#include <bits/stdc++.h>
using namespace std;

int idx[11];
int n;

vector<string> v;
int cnt[11];

int f(string &x){
    int ret = 0;
    for(int i=1; i<x.size(); i++){
        ret += x[i-1] != x[i];
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n; v.resize(n);
    for(int i=0; i<10; i++) idx[i] = i;
    for(int i=0; i<n; i++) cin >> v[i];
    
    int sum = 0;
    for(int i=0; i<n; i++){
        cnt[i] = f(v[i]);
        sum += cnt[i];
    }
    
    int ans = 1e9+7;
    do{
        int now = 0;
        for(int i=1; i<n; i++){
            now += v[idx[i-1]].back() != v[idx[i]][0];
        }
        ans = min(ans, now);
    }while(next_permutation(idx, idx+n));
    ans += sum;
    cout << ans;
}